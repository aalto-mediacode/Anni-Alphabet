#pragma once
#include "ofMain.h"
#include "ofxBox2d.h"

// ------------------------------------------------- a simple extended box2d circle
class CustomParticle : public ofxBox2dCircle {
public:
	ofColor color;
    
    /*
    CustomParticle(b2World * world, float x, float y) {
        setPhysics(0.4, 0.53, 0.31);
        setup(world, x, y, ofRandom(3, 10));
        color.r = ofRandom(20, 100);
        color.g = 0;
        color.b = ofRandom(150, 255);
	}
     */
	
	void draw() {
		float radius = getRadius();
		
		ofPushMatrix();
		ofTranslate(getPosition());
		ofSetColor(color);
		ofFill();
		ofDrawCircle(0, 0, radius);
		ofPopMatrix();
	}
};

// -------------------------------------------------
class ofApp : public ofBaseApp {
	
public:
	
	void setup();
	void update();
	void draw();
	
	void keyPressed(int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y);
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void resized(int w, int h);
	
	float                                   px, py;
	bool                                    bDrawLines;
	bool                                    bMouseForce;
	
    ofImage myImage;
	ofxBox2d                                box2d;           // the box2d world
	ofPolyline                              drawing;         // we draw with this first
	ofxBox2dEdge                            edgeLine;        // the box2d edge/line shape (min 2 points)
	vector    <shared_ptr<ofxBox2dCircle> > circles;         // default box2d circles
	vector    <shared_ptr<ofxBox2dRect> >   boxes;           // default box2d rects
	vector    <shared_ptr<CustomParticle> > customParticles; // this is a custom particle the extends a cirlce
    
    ofTrueTypeFont myFont1, myFont2, myFont3;
    string myString;
    ofSoundPlayer sound1,sound2,sound3,sound4,sound5,sound6,sound7,sound8;
    ofSoundPlayer drumBeat1,drumBeat2,drumBeat3,drumBeat4,drumBeat5,drumBeat6,drumBeat7;
   
};
