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
    points.push_back(ofVec3f(100,100,0));
    points.push_back(ofVec3f(100,200,0));
    points.push_back(ofVec3f(300,100,0));
    points.push_back(ofVec3f(400,200,0));
    curveNum = 1;
    
    modes.clear();

    modes.push_back(MIRRORED);
    modes.push_back(MIRRORED);
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

void BezierSpline::SetControlPoint(int index, ofVec3f point){
    
    //ControllPointも一緒に動かす
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

ofVec3f BezierSpline::GetControlPoint(int index){
    return points[index];
}

void BezierSpline::SetControlPointMode(int index, ControlMode mode){
    modes[(index + 1)/3] = mode;
    EnforceMode(index);
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
    

    cout << "index:" << i << " t:" << t << endl;
    return GetPoint(t , i);
}

void BezierSpline::addCurve(){
    
    ofVec3f point = points[points.size() - 1];
    point.x += ofRandom(50);
    point.y += ofRandom(50);
    points.push_back(point);
    point.x += ofRandom(50);
    point.y += ofRandom(50);
    points.push_back(point);
    point.x += ofRandom(50);
    point.y += ofRandom(50);
    points.push_back(point);
    curveNum++;
    modes.push_back(modes[modes.size() - 1]);
    EnforceMode(points.size() - 4);
}

ofVec3f BezierSpline::GetPoint(float t, int curveIndex){
    return Bezier::GetPoint(points[(curveIndex - 1) * 3],points[(curveIndex - 1) * 3 + 1], points[(curveIndex - 1) * 3 + 2], points[curveIndex * 3], t);
}

ofVec3f BezierSpline::GetVelocity(float t, int curveIndex){
    return  Bezier::GetFirstDerivative(points[(curveIndex - 1) * 3],points[(curveIndex - 1) * 3 + 1], points[(curveIndex - 1) * 3 + 2], points[curveIndex * 3], t);
}

ofVec3f BezierSpline::GetDirection(float t ,int curveIndex){
    return (GetVelocity(t, curveIndex));
}