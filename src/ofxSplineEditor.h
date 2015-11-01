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
    BezierSpline spline;
   
    void setup();
    void draw();
    void drawgui();
    void update();
    
    ofxPanel gui;
    ofxIntSlider editPointIndex;
    ofxToggle drawDirectionButton;
    ofxToggle addCurve;
    ofxToggle editPointMode;
    ofxToggle savePoints;
    ofxToggle loadPoints;
    ofxFloatSlider pointSize;
    
    void setControlPoint(ofVec3f point);
    /*
     ofxIntSlider : 整数型 (int) のスライダー
     ofxFloatSlider : 浮動小数点型 (float) のスライダー
     ofxVec2Slider : 2次元ベクトルのスライダー
     ofxColorSlider : カラー生成スライダー
     ofxButton : ボタン
     ofxToggle : トグルスイッチ
     ofxLabel : ラベル (テキスト表示)
     ofxPanel : GUIの外枠
     */
    
    bool drawDirectionMode;
    ofxSplineEditor(){
        spline.reset();
    }
};
#endif
