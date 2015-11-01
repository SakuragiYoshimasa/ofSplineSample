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
    bool dirFor;
    ofVec3f position;
    ofVec3f direction;
    float duration;
    float progress;
    float DirPro;
    int index;
    int dieInd;
    
    void setup(BezierSpline *sp, float dur){
        spline = sp;
        duration = dur;
        index = 1;
        forward = true;
        dirFor = true;
    }
    
    void update(){
        if(forward){
            progress += 0.005 / duration;
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
            progress -= 0.005 / duration;
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
        
        if(dirFor){
            DirPro = progress + 0.001;
            if(DirPro >= 1.0){
                if(spline->curveNum > dieInd){
                    DirPro = 0.0;
                    dieInd++;
                }else{
                    DirPro = 1.0;
                    dirFor = false;
                }
            }else{
                dieInd = index;
            }
        }else{
            DirPro = progress - 0.001;
            if(DirPro <= 0.0){
                if(1 < dieInd){
                    DirPro = 1.0;
                    dieInd--;
                }else{
                    DirPro = 0.0;
                    dirFor = true;
                }
            }
        }
        direction = spline->GetPoint(DirPro, dieInd);
        
    }
};
#endif
