#include "videoPortrait.h"

#include "../../../openFrameworks/libs/openFrameworks/app/ofAppRunner.h"
#include "../../../openFrameworks/libs/openFrameworks/graphics/ofGraphics.h"

void videoPortrait::initializeVideoIO() {
	cameraHeight = 400;
	cameraWidth = 640;
	int imageWidth = cameraWidth * 2;
	int imageHeight = cameraHeight * 2;

	int framesPerSeconds = 30;
	ofSetFrameRate(30);

	combinedImage.allocate(imageWidth, imageHeight, 3);
	image.clear();
	image.setUseTexture(false);
	image.allocate(imageWidth, imageHeight, OF_IMAGE_COLOR);

	videoGrabber1.setDeviceID(3);
	videoGrabber1.setDesiredFrameRate(30);
	videoGrabber1.initGrabber(cameraWidth, cameraHeight);

	videoGrabber2.setDeviceID(1);
	videoGrabber2.setDesiredFrameRate(30);
	videoGrabber2.initGrabber(cameraWidth, cameraHeight);
	videoGrabber3.setDeviceID(4);
	videoGrabber3.setDesiredFrameRate(30);
	videoGrabber3.initGrabber(cameraWidth, cameraHeight);
	videoGrabber4.setDeviceID(5);
	videoGrabber4.setDesiredFrameRate(30);
	videoGrabber4.initGrabber(cameraWidth, cameraHeight);

	videoRecorder.setup("foo.mov", imageWidth, imageHeight, framesPerSeconds);
	videoRecorder.start();
//	videoRecorder.setVideoCodec("mpeg4");
//	videoRecorder.setVideoBitrate("800k");
//	videoRecorder.setAudioCodec("mp3");
//	videoRecorder.setAudioBitrate("192k");
}

//--------------------------------------------------------------
void videoPortrait::setup() {
	initializeVideoIO();

	ofSetVerticalSync(true);
}

void videoPortrait::exit() {
	videoRecorder.close();
}

//--------------------------------------------------------------
void videoPortrait::update() {
	ofBackground(100, 100, 100);
	videoGrabber1.update();
	videoGrabber2.update();
	videoGrabber3.update();
	videoGrabber4.update();

	videoGrabber1.getPixels().pasteInto(combinedImage, 0, 0);
	videoGrabber2.getPixels().pasteInto(combinedImage, cameraWidth, 0);
	videoGrabber3.getPixels().pasteInto(combinedImage, 0, cameraHeight);
	videoGrabber4.getPixels().pasteInto(combinedImage, cameraWidth,
			cameraHeight);

	image.clear();
	image.setFromPixels(combinedImage);
	image.update();

	bool success = videoRecorder.addFrame(combinedImage);
}

//--------------------------------------------------------------
void videoPortrait::draw() {
	ofSetHexColor(0xffffff);

	image.draw(0, 0);
}

//--------------------------------------------------------------
void videoPortrait::keyPressed(int key) {
	if (key == 'c') {
		videoRecorder.close();
	}
}

//--------------------------------------------------------------
void videoPortrait::keyReleased(int key) {

}

//--------------------------------------------------------------
void videoPortrait::mouseMoved(int x, int y) {

}

//--------------------------------------------------------------
void videoPortrait::mouseDragged(int x, int y, int button) {

}

//--------------------------------------------------------------
void videoPortrait::mousePressed(int x, int y, int button) {

}

//--------------------------------------------------------------
void videoPortrait::mouseReleased(int x, int y, int button) {

}

//--------------------------------------------------------------
void videoPortrait::mouseEntered(int x, int y) {

}

//--------------------------------------------------------------
void videoPortrait::mouseExited(int x, int y) {

}

//--------------------------------------------------------------
void videoPortrait::windowResized(int w, int h) {

}

//--------------------------------------------------------------
void videoPortrait::gotMessage(ofMessage msg) {

}

//--------------------------------------------------------------
void videoPortrait::dragEvent(ofDragInfo dragInfo) {

}
