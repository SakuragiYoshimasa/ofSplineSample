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
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    editor.draw();
    ofSetColor(255, 0, 0);
    ofCircle(mouseX, mouseY, 2);
    
    ofCircle(walker.position, 10);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

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
