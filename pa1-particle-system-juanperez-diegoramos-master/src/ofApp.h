#pragma once

#include "ofMain.h"
#include "Particle.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
		void resetParticles();

		void keyPressed  (int key);
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
		
		particleMode currentMode;
		string currentModeStr; 

		bool pausedMode = false;
		bool increaseSize = false;
		bool decreaseSize = false;
		bool increaseVelocity = false;
		bool decreaseVelocity = false;
		bool isRecording = false;
		bool isReplaying = false;
		int counter = 150;
		int  index = 0;


		double increaseSizeLimit = 6;
		double decreaseSizeLimit = 0.22;
		double changeSizeFactor = 3;
		double increaseVelFactor = 4;
		double decreaseVelFactor = 0.25;
		double safeValue = 1;
		double IncreaseVelLimit = 256;
		double decreaseVelLimit = 0.015;
		
		vector<int> recordedKeys;
		vector <Particle> p;
		vector <glm::vec3> attractPoints;
		vector <glm::vec3> attractPointsWithMovement;
		
};
