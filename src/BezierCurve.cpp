//
//  BezierCurve.cpp
//  ofSplineSample
//
//  Created by SakuragiYoshimasa on 2015/10/31.
//
//

#include "BezierCurve.h"

void BezierCurve::reset(){
    points.clear();
    points.push_back(ofVec3f(100,100,0));
    points.push_back(ofVec3f(100,200,0));
    points.push_back(ofVec3f(300,100,0));
    points.push_back(ofVec3f(400,200,0));
}

ofVec3f BezierCurve::GetPoint(float t){
    
    return Bezier::GetPoint(points[0],points[1], points[2], points[3], t);
}

ofVec3f BezierCurve::GetVelocity(float t){
    return  Bezier::GetFirstDerivative(points[0], points[1], points[2], points[3], t);
}

ofVec3f BezierCurve::GetDirection(float t){
    return (GetVelocity(t)).normalized() * 100;
}