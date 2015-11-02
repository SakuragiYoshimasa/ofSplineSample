#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    editor = *new ofxSplineEditor();
    editor.setup();
    editor.setFileName("testPoint");
    walker.setup(editor.getSpline(), 5);
}

//--------------------------------------------------------------
void ofApp::update(){
    editor.update();
    walker.update();
    if(walkerMode){
        walkerCamera.setPosition(walker.getPosition());
        walkerCamera.lookAt(walker.getLookAt());
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
    ofDrawBox(walker.getPosition(), 10);
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
