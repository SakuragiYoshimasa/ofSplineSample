//
//  BezierCurve.h
//  ofSplineSample
//
//  Created by SakuragiYoshimasa on 2015/10/31.
//
//
#ifndef BezierCurve_h
#define BezierCurve_h

#include "ofMain.h"
#include "Bezier.h"

class BezierCurve{
public:
    vector<ofVec3f> points;
    void reset();
    ofVec3f GetPoint(float t);
    ofVec3f GetVelocity(float t);
    ofVec3f GetDirection(float t);
    BezierCurve(){
        reset();
    };
};
#endif
