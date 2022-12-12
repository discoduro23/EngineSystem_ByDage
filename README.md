# Engine_SDL

This project was made by:
- [Daniel Sanchez](mailto:alu.115081@usj.es)
- [German Aguilar](mailto:alu.115090@usj.es)

# Description of the engine
The engine structure has several managers:
## Engine Manager: 

It's the responsable of the flowchart, callign the updates, inits and destroys in order, it also controls the multithreading for the graphics.

## Graphic Manager: 

It's main function is to render all the objects and text on the screen, it also load the textures and text fonts.

## Input Manager:

Communicating user inputs to the engine and games.

## Object Manager:

It stores and update all the Objects int the game. It's the responsible of Updating the Game Manager.

## Physic Manager:

Check the collisions between objects.

## Save Manager:

Saves the game state in a file with the name of the project and ".MDyG" extension (made by us).

It also read the saved file and return the saved values.

## Sound Manager:

It can play, pause and stop background music and pieces of sound in multiple channels. It also allow to set the volume of every channel.

## Time Manager:

It's the responsible of the time. it have chronos and timers, among its getters and setters. It's also the responsible of the FPS.

# Description of the games
## BasicGame: SupraBasicBall
This game is a basic game, with balls that can be moved with the arrow keys, other with the wasd keys, and a third with a random function. It also check the collision between all the balls and show the collision booleans in the console.

## Game: Hide and Where
This game have a knight and a goblin. When the knight touch the goblin, will score a point, and the goblin will be teleported to a random position. Also, if the goblin survive 'x' seconds, the knight will lose a score.

The knight can be moved with the wasd keys, and the goblin with the arrow keys.

# Important notes

In the Hide and Where game, you can save and load the game points with the *K* key to save and *L* key to load.