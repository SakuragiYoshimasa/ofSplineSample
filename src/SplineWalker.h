//
//  SplineWalker.h
//  ofSplineSample
//
//  Created by SakuragiYoshimasa on 2015/10/31.
//
//
#ifndef SplineWalker_h
#define SplineWalker_h
#include "BezierSpline.h"

class SplineWalker {
public:
    void setup(BezierSpline *sp, float dur);
    void update();
    const ofVec3f getPosition();
    const ofVec3f getLookAt();
    
private:
    void updateProgress(int &i, float &p, ofVec3f &v, bool &f);
    
    int index;
    int indexLook;
    bool forward;
    bool forwardLook;
    float duration;
    float progress;
    float progressLook;
   
    ofVec3f position;
    ofVec3f loolAt;
    BezierSpline* spline;
};
#endif
