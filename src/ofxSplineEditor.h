//
//  ofxSplineEditor.hpp
//  ofSplineSample
//
//  Created by SakuragiYoshimasa on 2015/10/31.
//
//

#ifndef ofxSplineEditor_h
#define ofxSplineEditor_h

#include "ofMain.h"
#include "BezierCurve.h"
#include "BezierSpline.h"
#include "ofxGui.h"
#include "csvOperator.h"

class ofxSplineEditor {
public:
    ofxSplineEditor(){};
    void setup();
    void update();
    void draw();
    void drawgui();
    void setFileName(string fileName);
    void setStrokeWidth(float width);
    BezierSpline * getSpline();
private:
    
    void updateSpline();
    void updateSplineFileSystem();
    void updateSplinePoint();
    void drawMarkPoint();
    //------------------------------------
    //GUI
    //------------------------------------
    ofxPanel gui;
    ofxIntSlider editPointIndex;
    ofxToggle drawDirectionButton;
    ofxToggle drawControlLine;
    ofxToggle addCurve;
    ofxToggle editPointMode;
    ofxToggle savePoints;
    ofxToggle loadPoints;
    ofxFloatSlider pointSize;
    ofxFloatSlider adjustScale;
    ofxButton plusX;
    ofxButton minusX;
    ofxButton plusY;
    ofxButton minusY;
    ofxButton plusZ;
    ofxButton minusZ;
    
    //-------------------------------------
    //
    //-------------------------------------
    BezierSpline spline;
    float strokeWidth;
    string fileName = "";
};
#endif
