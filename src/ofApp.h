#pragma once

#include "ofMain.h"
#include "ofxLiquidFun.h"
#include "ofxGui.h"
#include "ofxOPC.h"

#define LEDS 19

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

    ofxBox2d box2d;
    vector <ofPtr<ofxBox2dCircle> >	circles;		  //	default box2d circles
    vector <ofPtr<ofxBox2dRect> > boxes;			  //	defalut box2d rects
    ofxBox2dParticleSystem particles;			      //    LiquidFun particle system
    int particleCount = 2000;
    float factor = 5;
    
    ofxPanel gui;
    ofxIntSlider hue;
    ofxIntSlider saturation;
    ofxIntSlider brightness;
    ofxIntSlider force;
    ofxIntSlider gravity;
    
    ofxOPC client;
};
