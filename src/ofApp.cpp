#include "ofApp.h"

static int pts[] = {257,219,257,258,259,274,263,325,266,345,266,352,269,369,276,387,286,415,291,425,302,451,308,462,316,472,321,480,328,488,333,495,339,501,345,505,350,507,365,515,370,519,377,522,382,525,388,527,405,534,426,538,439,539,452,539,468,540,485,540,496,541,607,541,618,539,625,537,641,530,666,513,682,500,710,476,723,463,727,457,729,453,732,450,734,447,738,440,746,423,756,404,772,363,779,343,781,339,784,327,789,301,792,278,794,267,794,257,795,250,795,232,796,222,796,197,797,195,797,188,796,188};
static int nPts  = 61*2;

//--------------------------------------------------------------
void ofApp::setup() {
    
	ofSetVerticalSync(true);
    myImage.load("22 grain.png");
	ofBackgroundHex(0xa39b84);
	ofSetLogLevel(OF_LOG_NOTICE);
	
	bMouseForce = false;
	
	box2d.init();
	box2d.setGravity(0, 30);
	box2d.createGround();
	box2d.setFPS(60.0);
	box2d.registerGrabbing();
	
	// lets add a contour to start
    /*
	for(int i=0; i<nPts; i+=2) {
		float x = pts[i];
		float y = pts[i+1];
		edgeLine.addVertex(x, y);
	}
	*/
	// make the shape
	edgeLine.setPhysics(0.0, 0.5, 0.5);
	edgeLine.create(box2d.getWorld());
    myFont1.load("Akzidenz-Grotesk Next Light.otf", 100);
    myFont2.load("Akzidenz-Grotesk Next Light small.otf", 25);
    myFont3.load("Akzidenz-Grotesk Next Light smaller.otf", 25);

    sound1.load("1.wav");
    sound2.load("2.wav");
    sound3.load("3.wav");
    sound4.load("4.wav");
    sound5.load("5.wav");
    sound6.load("6.wav");
    sound7.load("7.wav");
    sound8.load("8.wav");
    drumBeat1.load("Drum1.mp3");
    drumBeat2.load("Drum2.wav");
    drumBeat3.load("Drum3.wav");
    drumBeat4.load("Drum4.wav");
    drumBeat5.load("Drum5.wav");
    drumBeat6.load("Drum6.wav");
    drumBeat7.load("Drum7.wav");
}

//--------------------------------------------------------------
void ofApp::update() {
	
	box2d.update();
	
	if(bMouseForce) {
		float strength = 8.0f;
		float damping  = 0.7f;
		float minDis   = 100;
		for(int i=0; i<circles.size(); i++) {
			circles[i].get()->addAttractionPoint(mouseX, mouseY, strength);
			circles[i].get()->setLinearDamping(damping);
		}
		for(int i=0; i<customParticles.size(); i++) {
			customParticles[i].get()->addAttractionPoint(mouseX, mouseY, strength);
			customParticles[i].get()->setLinearDamping(damping);
		}
	}
	
	// remove shapes offscreen
	ofRemove(boxes, ofxBox2dBaseShape::shouldRemoveOffScreen);
	ofRemove(circles, ofxBox2dBaseShape::shouldRemoveOffScreen);
	ofRemove(customParticles, ofxBox2dBaseShape::shouldRemoveOffScreen);
}


//--------------------------------------------------------------
void ofApp::draw() {{
    myImage.draw(-20, -260, 1512, 1937);
    //myFont.drawString("test", 100, 100);
    //ofColor colorOne(163, 155, 131);
       //ofColor colorTwo(79, 76, 69);

       //ofBackgroundGradient(colorOne, colorTwo, OF_GRADIENT_LINEAR);
         // Sets the background to a linear gradient
   }
    
    
    for(auto &circle : circles) {
		ofFill();
		ofSetHexColor(0xc8c8c8);
		circle->draw();
	}
	
    for(auto &box : boxes) {
		ofFill();
		ofSetHexColor(0x0a0a0a);
		box->draw();
	}
	
    for(auto &particle : customParticles) {
		particle->draw();
	}
	
	ofNoFill();
	ofSetHexColor(0x0a0a0a);
	if(drawing.size()==0) {
		edgeLine.draw();
	}
    else drawing.draw();
    ofSetColor(200, 200, 200);
    myFont3.drawString("Anni Alanen", 40, 70);
    myFont2.drawString("ImproPoster in a#", 40, 100);
    ofDrawBitmapString("Press [space] or arrow keys", 40, 130);
    ofDrawBitmapString("for drum tracks", 40, 140);
    ofDrawBitmapString("Press [1] for a", 40, 160);
    ofDrawBitmapString("Press [2] for b", 40, 170);
    ofDrawBitmapString("Press [3] for c", 40, 180);
    ofDrawBitmapString("Press [4] for d", 40, 190);
    ofDrawBitmapString("Press [5] for e", 40, 200);
    ofDrawBitmapString("Press [6] for f", 40, 210);
    ofDrawBitmapString("Press [7] for g", 40, 220);
    ofDrawBitmapString("Press [8] for a", 40, 230);
    
    /*
    string info = "";
    info += "Press [space bar or arrow keys] to select a drum track ["+ofToString(bDrawLines)+"]\n";
    info += "Press [f] to toggle Mouse Force ["+ofToString(bMouseForce)+"]\n";
   info += "Press [c] for circles\n";
    info += "Press [b] for blocks\n";
info += "Press [z] for custom particle\n";
   info += "Total Bodies: "+ofToString(box2d.getBodyCount())+"\n";
   info += "Total Joints: "+ofToString(box2d.getJointCount())+"\n\n";
    info += "FPS: "+ofToString(ofGetFrameRate())+"\n";
    ofSetHexColor(0x444342);
    ofDrawBitmapString(info, 40, 130);
     */
    
    /*
	else drawing.draw();
	
	string info = "";
	info += "Press [s] to draw a line strip ["+ofToString(bDrawLines)+"]\n"; 
	info += "Press [f] to toggle Mouse Force ["+ofToString(bMouseForce)+"]\n"; 
	info += "Press [c] for circles\n";
	info += "Press [b] for blocks\n";
	info += "Press [z] for custom particle\n";
	info += "Total Bodies: "+ofToString(box2d.getBodyCount())+"\n";
	info += "Total Joints: "+ofToString(box2d.getJointCount())+"\n\n";
	info += "FPS: "+ofToString(ofGetFrameRate())+"\n";
	ofSetHexColor(0x444342);
	ofDrawBitmapString(info, 30, 30);
     */
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
    if(key=='1'){
        sound1.play();
        myString="a";
        auto circle = make_shared<ofxBox2dCircle>();
        circle->setPhysics(3.0, 0.53, 0.1);
        circle->setup( myFont1, myString, box2d.getWorld(), ofRandom(0, ofGetWidth()), ofRandom(0), ofRandom(4, 20));
        circles.push_back(circle);
    }
    if(key=='2'){
        sound2.play();
        myString="b";
        auto circle = make_shared<ofxBox2dCircle>();
        circle->setPhysics(3.0, 0.53, 0.1);
        circle->setup( myFont1, myString, box2d.getWorld(), ofRandom(0, ofGetWidth()), ofRandom(0), ofRandom(4, 20));
        circles.push_back(circle);
    }
    if(key=='3'){
        sound3.play();
        myString="c";
        auto circle = make_shared<ofxBox2dCircle>();
        circle->setPhysics(3.0, 0.53, 0.1);
        circle->setup( myFont1, myString, box2d.getWorld(), ofRandom(0, ofGetWidth()), ofRandom(0), ofRandom(4, 20));
        circles.push_back(circle);
    }
    if(key=='4'){
        sound4.play();
        myString="d";
        auto circle = make_shared<ofxBox2dCircle>();
        circle->setPhysics(3.0, 0.53, 0.1);
        circle->setup( myFont1, myString, box2d.getWorld(), ofRandom(0, ofGetWidth()), ofRandom(0), ofRandom(4, 20));
        circles.push_back(circle);
    }
    if(key=='5'){
        sound5.play();
        myString="e";
        auto circle = make_shared<ofxBox2dCircle>();
        circle->setPhysics(3.0, 0.53, 0.1);
        circle->setup( myFont1, myString, box2d.getWorld(), ofRandom(0, ofGetWidth()), ofRandom(0), ofRandom(4, 20));
        circles.push_back(circle);
    }
    if(key=='6'){
        sound6.play();
        myString="f";
        auto circle = make_shared<ofxBox2dCircle>();
        circle->setPhysics(3.0, 0.53, 0.1);
        circle->setup( myFont1, myString, box2d.getWorld(), ofRandom(0, ofGetWidth()), ofRandom(0), ofRandom(4, 20));
        circles.push_back(circle);
    }
    if(key=='7'){
        sound7.play();
        myString="g";
        auto circle = make_shared<ofxBox2dCircle>();
        circle->setPhysics(3.0, 0.53, 0.1);
        circle->setup( myFont1, myString, box2d.getWorld(), ofRandom(0, ofGetWidth()), ofRandom(0), ofRandom(4, 20));
        circles.push_back(circle);
    }
    if(key=='8'){
        sound8.play();
        myString="a";
        auto circle = make_shared<ofxBox2dCircle>();
        circle->setPhysics(3.0, 0.53, 0.1);
        circle->setup( myFont1, myString, box2d.getWorld(), ofRandom(0, ofGetWidth()), ofRandom(0), ofRandom(4, 20));
        circles.push_back(circle);
    }
    if(key==' '){
        drumBeat1.setVolume(0.1);
        drumBeat1.play();
        drumBeat1.setLoop(true);
        drumBeat6.stop();
        drumBeat3.stop();
        drumBeat4.stop();
        drumBeat5.stop();
        
    }
    if(key==OF_KEY_LEFT){
        drumBeat2.setVolume(0.1);
        drumBeat6.play();
        drumBeat6.setLoop(true);
        drumBeat1.stop();
        drumBeat3.stop();
        drumBeat4.stop();
        drumBeat5.stop();
    }
    if(key==OF_KEY_RIGHT){
        drumBeat3.setVolume(0.1);
        drumBeat3.play();
        drumBeat3.setLoop(true);
        drumBeat1.stop();
        drumBeat6.stop();
        drumBeat4.stop();
        drumBeat5.stop();
    }
    if(key==OF_KEY_UP){
        drumBeat4.setVolume(0.3);
        drumBeat4.play();
        drumBeat4.setLoop(true);
        drumBeat1.stop();
        drumBeat6.stop();
        drumBeat3.stop();
        drumBeat5.stop();
    }
    if(key==OF_KEY_DOWN){
        drumBeat5.setVolume(0.1);
        drumBeat5.play();
        drumBeat5.setLoop(true);
        drumBeat1.stop();
        drumBeat6.stop();
        drumBeat3.stop();
        drumBeat4.stop();
    }
}
	/*
	if(key == 'b') {
		float w = ofRandom(4, 20);	
		float h = ofRandom(4, 20);
        auto box = make_shared<ofxBox2dRect>();
		box->setPhysics(3.0, 0.53, 0.1);
		box->setup(box2d.getWorld(), mouseX, mouseY, w, h);
        boxes.push_back(box);
	}
	
	if(key == 'z') {
        auto particle = make_shared<CustomParticle>(box2d.getWorld(), mouseX, mouseY);
        customParticles.push_back(particle);
	}	
		
	if(key == 'f') bMouseForce = !bMouseForce;
	if(key == 't') ofToggleFullscreen();
     */


//--------------------------------------------------------------
void ofApp::keyReleased(int key) {
	
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {
	
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {
	drawing.addVertex(x, y);
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {
	
    // if we have a body clear the line and destroy b2d object
	if(edgeLine.isBody()) {
		drawing.clear();
		edgeLine.destroy();
	}
	
	drawing.addVertex(x, y);
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {
	
	drawing.setClosed(false);
	drawing.simplify();
	
	edgeLine.addVertexes(drawing);
	//polyLine.simplifyToMaxVerts(); // this is based on the max box2d verts
	edgeLine.setPhysics(0.0, 0.5, 0.5);
	edgeLine.create(box2d.getWorld());
		
	drawing.clear();
}

//--------------------------------------------------------------
void ofApp::resized(int w, int h){
	
}
