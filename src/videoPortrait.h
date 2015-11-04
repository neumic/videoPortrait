#pragma once

#include "../../../openFrameworks/addons/ofxVideoRecorder/src/ofxVideoRecorder.h"
#include "../../../openFrameworks/libs/openFrameworks/app/ofBaseApp.h"
#include "../../../openFrameworks/libs/openFrameworks/events/ofEvents.h"
#include "../../../openFrameworks/libs/openFrameworks/video/ofVideoGrabber.h"
#include "ofMain.h"

class videoPortrait: public ofBaseApp {

public:
	int cameraHeight;
	int cameraWidth;

	ofVideoGrabber videoGrabber1;
	ofVideoGrabber videoGrabber2;
	ofVideoGrabber videoGrabber3;
	ofVideoGrabber videoGrabber4;

	ofPixels combinedImage;
	ofImage image;

	ofxVideoRecorder videoRecorder;

	void setup();
	void exit();
	void update();
	void draw();

	void keyPressed(int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y);
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void mouseEntered(int x, int y);
	void mouseExited(int x, int y);
	void windowResized(int w, int h);
	void dragEvent(ofDragInfo dragInfo);
	void gotMessage(ofMessage msg);

private:
	void initializeVideoIO();
};
