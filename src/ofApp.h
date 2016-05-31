#pragma once

#include "ofMain.h"
#include "ofxGui.h"

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
		void scaleTex(int & circleResolution);

		//Renders the sphere
		GLUquadricObj *quadric;

		unsigned char * pixelout;
		unsigned char * pixelin;
		unsigned char * pixels;

		int pointer, sPointer;

		int width, height, sWidth, sHeight;
		
		int i, j, u;

		ofImage img;
		ofTexture scaled;

		ofxPanel gui;

		ofxIntSlider scale;
		
		ofEasyCam cam;
};
