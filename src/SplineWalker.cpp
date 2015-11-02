//
//  SplineWalker.cpp
//  ofSplineSample
//
//  Created by SakuragiYoshimasa on 2015/10/31.
//
//
#include "SplineWalker.h"

void SplineWalker::setup(BezierSpline *sp, float dur){
    spline = sp;
    duration = dur;
    index = 1;
    forward = true;
    forwardLook = true;
}

void SplineWalker::update(){
    if(forward){
        progress += 0.1 / duration;
    }else{
        progress -= 0.1 / duration;
    }
    updateProgress(index, progress, position, forward);
    
    if(forwardLook){
        progressLook = progress + 0.001;
    }else{
        progressLook = progress - 0.001;
    }
    updateProgress(indexLook, progressLook, loolAt, forwardLook);
}

void SplineWalker::updateProgress(int &i, float &p, ofVec3f &v, bool &f){
    if(f){
        if(p >= 1.0){
            if(spline->GetCurveNum() > i){
                p = 0.0;
                i++;
            }else{
                p = 1.0;
                f = false;
            }
        }
    }else{
        if(p <= 0.0){
            if(1 < i){
                p = 1.0;
                i--;
            }else{
                p = 0.0;
                f = true;
            }
        }
    }
    v = spline->GetPoint(p, i);
}

const ofVec3f SplineWalker::getPosition(){
    return position;
}

const ofVec3f SplineWalker::getLookAt(){
    return loolAt;
}