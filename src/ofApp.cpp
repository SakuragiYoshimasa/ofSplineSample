#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    editor = *new ofxSplineEditor();
    editor.setup();
    walker.setup(&editor.spline, 1);
}

//--------------------------------------------------------------
void ofApp::update(){
    editor.update();
    walker.update();
    if(walkerMode){
        walkerCamera.setPosition(walker.position);
        walkerCamera.lookAt(walker.direction);
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(0);
    editor.drawgui();
    if(walkerMode){walkerCamera.begin();}else{cam.begin();}
    ofPushMatrix();
    if(!walkerMode) ofTranslate(-ofGetWidth()/2, -ofGetHeight()/2);
    editor.draw();
    ofSetColor(255, 0, 0);
    if(walkerMode) ofSetColor(200, 0, 0,100);
    ofDrawBox(walker.position, 10);
    ofPopMatrix();
    if(walkerMode){walkerCamera.end();}else{cam.end();}
    ofCircle(mouseX, mouseY, 2);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key == ' ') walkerMode = !walkerMode;
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    mouseX = x;
    mouseY = y;
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    editor.setControlPoint(ofVec3f(x,y,0));
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
