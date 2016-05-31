#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
	img.loadImage("japan.bmp");

	scale = 1;

	width = img.getWidth();
	height = img.getHeight();

	sWidth = (int)width / scale;
	sHeight = (int)height / scale;

	//Prepare quadric for sphere
	quadric = gluNewQuadric();
	gluQuadricTexture(quadric, GL_TRUE);
	gluQuadricNormals(quadric, GLU_SMOOTH);

	//Assigns length to array
	pixelin = new unsigned char[width* height * 3];
	pixelout = new unsigned char[sWidth* sHeight * 3];

	// we add this listener before setting up so the initial circle resolution is correct
	scale.addListener(this, &ofApp::scaleTex);

	gui.setup();
	gui.add(scale.setup("Scale", 1, 1, 6));

	//Place camera inside sphere at 0,0,0
	cam.setAutoDistance(false);
}

//--------------------------------------------------------------
void ofApp::scaleTex(int &circleResolution) {


}

//--------------------------------------------------------------
void ofApp::update() {

	sWidth = (int)width / scale;
	sHeight = (int)height / scale;
	pixelout = new unsigned char[sWidth* sHeight * 3];

	pixelin = img.getPixels();
	for (int i = 0; i < width; i += scale) {
		for (int j = 0; j < height; j += scale) {

			pointer = (j*width + i);
			sPointer = ((j / scale)*sWidth + (i / scale));

			pixelout[sPointer * 3 + 0] = pixelin[pointer * 3 + 0];//red
			pixelout[sPointer * 3 + 1] = pixelin[pointer * 3 + 1];//green
			pixelout[sPointer * 3 + 2] = pixelin[pointer * 3 + 2];//blue

		}
	}
	scaled.loadData(pixelout, sWidth, sHeight, GL_RGB);//Writes pixels to preview sequence
}

//--------------------------------------------------------------
void ofApp::draw() {

	scaled.draw(0, 0);
	gui.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {

	if (key == 'r') {

		//Prepare quadric for sphere
		quadric = gluNewQuadric();
		gluQuadricTexture(quadric, GL_TRUE);
		gluQuadricNormals(quadric, GLU_SMOOTH);

		scale = 1;

		img.loadImage("japan2.bmp");

		width = img.getWidth();
		height = img.getHeight();

		sWidth = (int)width / scale;
		sHeight = (int)height / scale;


		//Assigns length to array
		pixelin = new unsigned char[width* height * 3];
		pixelout = new unsigned char[sWidth* sHeight * 3];
	}

	for (i = 0; i < 7; i++) {
		char myChar = '0' + i;
		if (key == myChar)
			scale = i;
		sWidth = (int)width / scale;
		sHeight = (int)height / scale;
		pixelout = new unsigned char[sWidth* sHeight * 3];
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {

}
