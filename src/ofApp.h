#pragma once

#include "ofMain.h"
#include "World.h"

#define DT 1.0f/60.0f

class ofApp : public ofBaseApp{

	public:
		World *world;
		void setup();
		void update();
		void draw();
		
		//***********
		float PlayerPosX = 700;
		float PlayerPosY = 100;


		//***********

		double accumulator;

		void onCollision(Contact &c);

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
		
};
