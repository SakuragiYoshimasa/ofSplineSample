//
//  SplineWalker.hpp
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
    BezierSpline* spline;
    bool forward;
    ofVec3f position;
    float duration;
    float progress;
    int index;
    
    void setup(BezierSpline *sp, float dur){
        spline = sp;
        duration = dur;
        index = 1;
        forward = true;
    }
    
    void update(){
        if(forward){
            progress += 0.02 / duration;
            if(progress >= 1.0){
                if(spline->curveNum > index){
                    progress = 0.0;
                    index++;
                }else{
                    progress = 1.0;
                    forward = false;
                }
            }
        }else{
            progress -= 0.02 / duration;
            if(progress <= 0.0){
                if(1 < index){
                    progress = 1.0;
                    index--;
                }else{
                    progress = 0.0;
                    forward = true;
                }
            }
        }
        position = spline->GetPoint(progress, index);
    }
};
#endif