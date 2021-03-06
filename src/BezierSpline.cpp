//
//  BezierSpline.cpp
//  ofSplineSample
//
//  Created by SakuragiYoshimasa on 2015/10/31.
//
//

#include "BezierSpline.h"

void BezierSpline::reset(){
    points.clear();
    points.push_back(*new ofVec3f(100,100,0));
    points.push_back(*new ofVec3f(100,200,0));
    points.push_back(*new ofVec3f(300,100,0));
    points.push_back(*new ofVec3f(400,200,0));
    curveNum = 1;
    modes.clear();
    modes.push_back(MIRRORED);
    modes.push_back(MIRRORED);
    modeColors[0] = ofColor(255,255,255,255);
    modeColors[1] = ofColor(255,255,0,255);
    modeColors[2] = ofColor(0,255,255,255);
}

void BezierSpline::saveSpline(string fileName){
    csvOperator::saveSplinePoints(fileName, points);
}

void BezierSpline::loadSpline(string fileName){
    points.clear();
    modes.clear();
    modes.push_back(MIRRORED);
    points = csvOperator::loadSplinePoints(fileName);
    curveNum = (points.size() - 1)/3;
    for(int i = 0; i < GetCurveNum(); i++){
        modes.push_back(MIRRORED);
        EnforceMode(i * 3);
        EnforceMode(i * 3 + 1);
        EnforceMode(i * 3 + 2);
    }
}

void BezierSpline::addCurve(){
    ofVec3f point = points[points.size() - 1];
    for(int i = 0; i < 3; i++){
        point.x += ofRandom(50);
        point.y += ofRandom(-50,50);
        point.z += ofRandom(-50,50);
        points.push_back(point);
    }
    curveNum++;
    modes.push_back(modes[modes.size() - 1]);
    EnforceMode(points.size() - 4);
}

void BezierSpline::SetControlPoint(int index, ofVec3f point){
    //move controllPoints too
    if(index % 3 == 0){
        ofVec3f delta = point - points[index];
        if(index > 0){
            points[index - 1] += delta;
        }
        if(index + 1 < points.size()){
            points[index + 1] += delta;
        }
    }
    points[index] = point;
    EnforceMode(index);
}

void BezierSpline::SetControlPointMode(int index, ControlMode mode){
    modes[(index + 1)/3] = mode;
    EnforceMode(index);
}

const int BezierSpline::GetCurveNum(){
    return curveNum;
}

const int BezierSpline::GetPointNum(){
    return points.size();
}

const vector<ofVec3f> BezierSpline::GetPoints(){
    return points;
}

ofVec3f BezierSpline::GetControlPoint(int index){
    return points[index];
}

ControlMode BezierSpline::GetControlPointMode(int index){
    return modes[(index + 1) / 3];
}

ofVec3f BezierSpline::GetPoint(float t){
    if(t >= 1) t = 1;
    if(t < 0) t = 0;
    int i;
    t = t * float(curveNum);
    i = int(t);
    t -= i;
    i *= 3;
    return GetPoint(t , i);
}

ofVec3f BezierSpline::GetPoint(float t, int curveIndex){
    return Bezier::GetPoint(points[(curveIndex - 1) * 3], points[(curveIndex - 1) * 3 + 1], points[(curveIndex - 1) * 3 + 2], points[curveIndex * 3], t);
}

ofVec3f BezierSpline::GetVelocity(float t, int curveIndex){
    return  Bezier::GetFirstDerivative(points[(curveIndex - 1) * 3], points[(curveIndex - 1) * 3 + 1], points[(curveIndex - 1) * 3 + 2], points[curveIndex * 3], t);
}

ofVec3f BezierSpline::GetDirection(float t ,int curveIndex){
    return (GetVelocity(t, curveIndex));
}

void BezierSpline::EnforceMode(int index){
    int modeIndex = (index + 1) / 3;
    ControlMode mode = modes[modeIndex];
    if(mode == FREE || modeIndex == 0 || modeIndex == modes.size() - 1){
        return;
    }
    //Mirrored か alignedならもう一方を強制移動
    int middleIndex = modeIndex * 3;
    int fixedIndex, enforedIndex;
    if(index <= middleIndex){
        fixedIndex = middleIndex - 1;
        enforedIndex = middleIndex + 1;
    }else{
        fixedIndex = middleIndex + 1;
        enforedIndex = middleIndex - 1;
    }
    
    ofVec3f middle = points[middleIndex];
    ofVec3f enforcedTangent = middle - points[fixedIndex];
    if(mode == ALIGNED){
        enforcedTangent = enforcedTangent.normalized() * middle.distance(points[enforedIndex]);
    }
    points[enforedIndex] = middle + enforcedTangent;
}