//
//  ofxSplineEditor.cpp
//  ofSplineSample
//
//  Created by SakuragiYoshimasa on 2015/10/31.
//
//

#include "ofxSplineEditor.h"

void ofxSplineEditor::setup(){
    gui.setup();
    gui.add(editPointIndex.setup("editPointIndex",0,0,spline.points.size()));
    gui.add(drawDirectionButton.setup("Direction",true));
    gui.add(addCurve.setup("AddCurve",false));
    gui.add(pointSize.setup("PointSize",5,0,100));
    gui.add(editPointMode.setup("EditPointMode",true));
}

void ofxSplineEditor::draw(){
    gui.draw();
    //spline.reset();
    ofPath line = ofPath();
    line.setStrokeColor(ofColor(255,255,255));
    line.setFilled(false);
    line.setStrokeWidth(1);
    
    float lineSteps = 10.0;
    ofVec3f lineStart = spline.GetPoint(0,1);
    line.moveTo(lineStart);
    
    for(int index = 1; index <= spline.curveNum; index++){
        for(int i = 0; i <= lineSteps; i++){
            ofVec3f lineEnd = spline.GetPoint(float(i)/lineSteps, index);
            line.lineTo(lineEnd);
            ofSetColor(0, 255, 0);
            if(drawDirectionButton) ofLine(lineEnd, lineEnd + spline.GetDirection(float(i)/lineSteps, index));
            lineStart = lineEnd;
        }
        
    }
    line.draw();
   
    ofSetColor(255, 0, 0);

    for(int i = 0; i < spline.points.size(); i++){
        ofSetColor(spline.modeColors[(int)spline.GetControlPointMode(i)]);
        ofDrawBox(spline.points[i], pointSize);
        
    }
}

void ofxSplineEditor::update(){
    if(addCurve) {
        spline.addCurve();
        addCurve = false;
    }
    editPointIndex.setup("editPointIndex",editPointIndex,0,spline.points.size());
}

void ofxSplineEditor::setControlPoint(ofVec3f point){
    spline.SetControlPoint(editPointIndex, point);
}
