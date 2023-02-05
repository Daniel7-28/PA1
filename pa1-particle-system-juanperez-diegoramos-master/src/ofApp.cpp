#include "ofApp.h"
#include "Particle.h"
//--------------------------------------------------------------
void ofApp::setup(){
	ofSetVerticalSync(true);
	
	int num = 1500;
	p.assign(num, Particle());
	currentMode = PARTICLE_MODE_ATTRACT;

	currentModeStr = "1 - PARTICLE_MODE_ATTRACT: attracts to mouse"; 

	resetParticles();
}

//--------------------------------------------------------------
void ofApp::resetParticles(){

	//these are the attraction points used in the fourth demo 
	attractPoints.clear();
	for(int i = 0; i < 4; i++){
		attractPoints.push_back( glm::vec3( ofMap(i, 0, 4, 100, ofGetWidth()-100) , ofRandom(100, ofGetHeight()-100) , 0) );
	}
	
	attractPointsWithMovement = attractPoints;
	
	for(unsigned int i = 0; i < p.size(); i++){
		p[i].setMode(currentMode);		
		p[i].setAttractPoints(&attractPointsWithMovement);;
		p[i].reset();
	}	
}

//--------------------------------------------------------------
void ofApp::update(){
	if (!pausedMode){
		for (unsigned int i = 0; i < p.size(); i++) {
			if (increaseSize && (p[i].scale < increaseSizeLimit)){
				for (unsigned int k = 0; k < p.size(); k++)
				{
					p[k].scale *= changeSizeFactor;
				}
				increaseSize = false;
			}
			if (decreaseSize && (p[i].scale > decreaseSizeLimit)){
				for (unsigned int k = 0; k < p.size(); k++){
					p[k].scale /= changeSizeFactor;	
				}
				decreaseSize = false;
			}
			if (increaseVelocity && (safeValue <= IncreaseVelLimit)){
					safeValue *= increaseVelFactor;
				for (unsigned int k = 0; k < p.size(); k++){
					p[k].setFactor(safeValue);
				}
					increaseVelocity = false;
			}
			if (decreaseVelocity && safeValue >= decreaseVelLimit){
				safeValue *= decreaseVelFactor;
				for (unsigned int r = 0; r < p.size(); r++){
					p[r].setFactor(safeValue);
				}
				decreaseVelocity = false;
			}
	

			
				
			

			p[i].setMode(currentMode);
			p[i].update();
		}
		if(isReplaying){
				counter--;
				if(recordedKeys.empty()){
					isReplaying = false;
					counter = 150;
				}else if(counter == 0){
					counter = 150;
					keyPressed(recordedKeys.back());
					recordedKeys.pop_back();		
				}
				
						
			}

		//lets add a bit of movement to the attract points
		for (unsigned int i = 0; i < attractPointsWithMovement.size(); i++)
		{
			attractPointsWithMovement[i].x = attractPoints[i].x + ofSignedNoise(i * 10, ofGetElapsedTimef() * 0.7) * 12.0;
			attractPointsWithMovement[i].y = attractPoints[i].y + ofSignedNoise(i * -10, ofGetElapsedTimef() * 0.7) * 12.0;
		}
	}	
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackgroundGradient(ofColor(243,255,67), ofColor(10,10,10));

	for(unsigned int i = 0; i < p.size(); i++){
		p[i].draw();
	}
	
	ofSetColor(190);
	if( currentMode == PARTICLE_MODE_NEAREST_POINTS ){
		for(unsigned int i = 0; i < attractPoints.size(); i++){
			ofNoFill();
			ofDrawCircle(attractPointsWithMovement[i], 10);
			ofFill();
			ofDrawCircle(attractPointsWithMovement[i], 4);
		}
	}

	ofSetColor(230);	
	ofDrawBitmapString(currentModeStr + "\n\nSpacebar to reset. \nKeys 1-4 to change mode. \nA key to pause.", 10, 20);
	ofDrawBitmapString("\n\n\n\n\nI and D keys to change size\nof particles. \nF and S keys to change velocity\nof particles.", 10, 20);
	if(isRecording){
		ofFill();
        ofSetColor(255,0,0);
        ofDrawCircle(ofGetWindowWidth()- 50, ofGetWindowHeight()- 50, 20);
        ofDrawBitmapString("Recording...", ofGetWindowWidth() - 200, ofGetWindowHeight() - 50); 
	}
	if(isReplaying){
		ofFill();
        ofSetColor(0,0,255);
        ofDrawCircle(ofGetWindowWidth()- 50, ofGetWindowHeight()- 100, 20);
        ofDrawBitmapString("Replaying...", ofGetWindowWidth() - 200, ofGetWindowHeight() - 100); 
	}

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if(isRecording){
		if(key == 'r' || key == 'R'){
			isRecording = false;
			return;
		}else{
			vector <int>::iterator it = recordedKeys.begin();
			recordedKeys.insert(it,key);
			
			
			
		}
	}
	
	if(key == 'r'|| key == 'R'){
		isRecording = true;
	}

	
	if( key == '1'){
		currentMode = PARTICLE_MODE_ATTRACT;
		currentModeStr = "1 - PARTICLE_MODE_ATTRACT: attracts to mouse"; 		
	}
	if( key == '2'){
		currentMode = PARTICLE_MODE_REPEL;
		currentModeStr = "2 - PARTICLE_MODE_REPEL: repels from mouse"; 				
	}
	if( key == '3'){
		currentMode = PARTICLE_MODE_NEAREST_POINTS;
		currentModeStr = "3 - PARTICLE_MODE_NEAREST_POINTS:"; 						
	}
	if( key == '4'){
		currentMode = PARTICLE_MODE_NOISE;
		currentModeStr = "4 - PARTICLE_MODE_NOISE: snow particle simulation"; 						
		resetParticles();
	}	

	if( key == ' ' ){
		resetParticles();
	}

	if((key == 'A' || key == 'a') && !pausedMode){
		pausedMode = true;
	} else {
		pausedMode=false;
	}

	if(key == 'I' || key =='i'){
		increaseSize = true;
	}
	if(key == 'D' || key == 'd'){
		decreaseSize = true;
	}

	if(key == 'F'|| key == 'f'){
		increaseVelocity = true;
	}
	if(key == 'S'|| key == 's'){
		decreaseVelocity = true;
	}
	if((key == 'P' || key == 'p') && !isReplaying){
		isReplaying = true;
		
	}
	if(key == 'C'|| key == 'c'){
		isReplaying = false;
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

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
