#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetBackgroundColor(0);
	ofSetFrameRate(60);
	world = World::getInstance();
	world->addFloor();

	//world->addRectangle(PlayerPosX, PlayerPosY, 20, 20);

	ofAddListener(world->onCollide, this,&ofApp::onCollision);

	

}

//--------------------------------------------------------------
void ofApp::update(){
	accumulator += ofGetLastFrameTime();

	accumulator = ofClamp(0.0f, 0.1f, accumulator);
	while (accumulator >= DT)
	{
		world->update();
		accumulator -= DT;
	}	

	PlayerPosX = mouseX + PlayerPosX;
	PlayerPosY = mouseY + PlayerPosY;
//	world->addRectangle(PlayerPosX, PlayerPosY, 20, 20);
	
}

//--------------------------------------------------------------
void ofApp::draw(){
	world->draw();
	ofDrawBitmapString(ofToString(ofGetFrameRate()),20, 20);

	//world->addPlayer(mouseX, mouseY);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
//	world->addRectangle(mouseX, mouseY, 20, 20);
	
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

	if (button == OF_MOUSE_BUTTON_LEFT)
	{
		world->addCircle(x, y, 20);
	}
	if (button == OF_MOUSE_BUTTON_RIGHT)
	{
		world->addRectangle(x, y, 20,20);
	}
	//int max = ofRandom(5, 10);
	//for (int i = 0; i < max; i++)
	//{
		//int posx = ofRandom(0, ofGetWidth());
		//int posy = ofRandom(y, y + 30);
		//world.addCircle(posx, posy, ofRandom(5, 10));
	//}
	//world.addRectangle(x,y,30,20);
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}

void ofApp::onCollision(Contact &c)
{
	//cout << "Colision" << endl;
}