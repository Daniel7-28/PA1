# PA1: Particle System
This project is based on the OpenFrameworks Particle System example which has different modes that the particles changes their behaviors pressing different types of keys. This repository is part of a Programming Assignment for the Advanced Programming Course (ICOM4015).
 
## Setup
1. Clone this project inside an OpenFrameworks installation's "apps/myApps/" directory
2. Run the command "make" in the terminal or the "Build" Task in VSCode.

## Specs

### Phase 1 
The specs for this phase will act as a warm-up.
• The background color of the application must be changed.
• The Particle colors must be randomized on all modes.
• Pressing the ‘A’ key toggles pause. When Particles are “paused” they are suspended in the air.

### Phase 2 
The focus of this phase will be to tie certain functionalities to keyboard keys.
• Increase Size: Pressing the ‘I’ key triples the size of all particles.
• Decrease Size: Pressing the ‘D’ thirds the size of all particles. That is to say that if the original size of the particle is 3, the resulting size after pressing ‘D’ should be 1.
• Increase Velocity: Pressing the ‘F’ key quadruples the velocity of all particles.
• Decrease Velocity: Pressing the ‘S’ quarters the velocity of all particles.

### Phase 3
The focus of this phase will be to implement a Record/Replay feature.
• Record: Pressing the ‘R’ key will start recording or saving all the keys pressed afterwards in order until it is pressed again. The actions associated to the keys should be performed anyway during recording.
• There must be an indicator for when the program is recording. This indicator should only appear when the program is recording.
• Replay: Pressing the ‘P’ key will replay all the recorded keys and their associated actions at fixed intervals. That is to say, that while recording you do not need to keep in mind time because when you replay them, there will be a fixed amount of time between the actions. This amount of time is up to you, but should be enough so that they can be noticed. 
NOTE: While in replay mode, the program should not listen to any key presses until the replay is finished or cancelled.
• Cancel Replay: Pressing the ‘C’ key cancels a playing replay.
• There must be an indicator for when the program is replaying. This indicator should only appear when the program is replaying.