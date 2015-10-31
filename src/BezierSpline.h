//
//  BezierSpline.hpp
//  ofSplineSample
//
//  Created by SakuragiYoshimasa on 2015/10/31.
//
//

#ifndef BezierSpline_h
#define BezierSpline_h

#include "ofMain.h"
#include "Bezier.h"

class BezierSpline{
public:
    vector<ofVec3f> points;
    vector<ControlMode> modes;
    
    int curveNum;
    void reset();
    void addCurve();
    ofVec3f GetPoint(float t);
    ofVec3f GetPoint(float t, int curveIndex);
    ofVec3f GetVelocity(float t, int curveIndex);
    ofVec3f GetDirection(float t ,int curveIndex);
    
    void EnforceMode(int index);
    void SetControlPoint(int index, ofVec3f point);
    void SetControlPointMode(int index, ControlMode mode);
    ofVec3f GetControlPoint(int index);
    ControlMode GetControlPointMode(int index);
    
    
    BezierSpline(){
        reset();
    };
    
    ofColor modeColors[3] = {
        ofColor(255,255,255),
        ofColor(255,255,0),
        ofColor(0,255,255)
    };

};

#endif
