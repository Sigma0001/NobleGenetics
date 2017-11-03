#pragma once

#include "ofMain.h"
#include "World.h"
#include "Player.h"
#include "Actor.h"

#define DT 1.0f/60.0f

class ofApp : public ofBaseApp{

	public:
		World *world;
		void setup();
		void update();
		void draw();
		
		//***********
		ofVec2f playerPos;


		void addPlayer();
		//***********

		Actor actor;

		double accumulator;

		void onCollision(Contact &c);
		void addActor(Actor * act);

		vector<Actor*> actors;
		vector < Player*> mainplayer;
		Player * MainPlayer;

		void setPlayerPos();

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
