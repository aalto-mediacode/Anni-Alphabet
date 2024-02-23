#include "ofMain.h"
#include "ofApp.h"

int main() {
	ofSetupOpenGL(720, 1280, OF_WINDOW);
	return ofRunApp(std::make_shared<ofApp>());
}
