# Crystal-Engine
Crystal Engine (An OpenGL simple game engine)

I used lodepng to load png files 
![lodepng](https://github.com/lvandeve/lodepng)


The Engine class provides a simple framework for creating and running games using OpenGL and GLUT. It handles window initialization, rendering, and user input. Additionally, it includes utility functions for drawing shapes and loading PNG images.
Features

- [X] Window initialization and management
- [X] Frame rendering and update callbacks
- [X] User input handling for mouse and keyboard
- [X] FPS (Frames Per Second) control
- [X] Fullscreen toggle support
- [X] Drawing functions for circles and rectangles
- [X] PNG image loading and display
- [ ] Sprite manager class
- [ ] Audio
- [ ] Animations (2D)
- [ ] IDK Quantom Physics?

Prerequisites

* OpenGL
* GLUT

Getting Started

To use the Engine in your game, follow these steps:

    Include the Engine.h header file in your project.
    Initialize the Engine by calling Engine::Init with the desired window title, width, and height.
    Implement your game logic by defining the Start, Render, and Update functions.
    Set the target FPS using Engine::SetTargetFPS if desired.
    Run the game by calling Engine::Start.

Usage
Initialization

To initialize the Engine, call the Engine::Init function with the following parameters:

    title: The title of the game window.
    width: The width of the game window.
    height: The height of the game window.
    gl_argc (optional): The number of command-line arguments (gl_argv) passed to GLUT.
    gl_argv (optional): Command-line arguments passed to GLUT.

Game Logic

Implement the following functions to define your game logic:

    Start: This function is called once at the beginning of the game. Use it to initialize your game state.
    Render: Use this function to render your shapes on the game screen.
    Update: This function runs in each frame of the game before the renderer. Use it to update your game state.

FPS Control

You can set a target FPS (Frames Per Second) for the game using the Engine::SetTargetFPS function. Pass 0 to disable FPS limiting.
Fullscreen Toggle

The Engine supports toggling between fullscreen and windowed mode. Call Engine::ToggleFullScreen to switch between the two.
Drawing Shapes

The Engine provides two drawing functions:

    Draw_Circle: Draws a circle on the game screen. Pass the center coordinates, radius, start angle, end angle, and the number of segments.
    Draw_Rectangle: Draws a rectangle on the game screen. Pass the top-left corner coordinates, width, and height.

User Input

The Engine handles user input for mouse and keyboard events. The following functions are available:

    onMouseMotion: Called when the mouse is moved. Receives the new mouse coordinates.
    onReshape: Called when the window is resized. Receives the new width and height.
    onMouseClick: Called when a mouse button is clicked. Receives the button, state, and mouse coordinates.
    onKeyPress: Called when a keyboard key is pressed. Receives the key code, and mouse coordinates.
    onKeyRelease: Called when a keyboard key is released. Receives the key code, and mouse coordinates.

PNG Image Loading

The Engine provides a PNG class for loading and displaying PNG images. Use the load function to load a PNG image from a file. The display function can be used to display the loaded image on the game screen.


Examples
```

#include "Engine.h"

void MyGame::Start()
{
    // Initialize game state
}

void MyGame::Render()
{
    // Render game objects
}

void MyGame::Update()
{
    // Update game logic
}

int main()
{
    Engine::Init("My Game", 800, 600);
    Engine::SetTargetFPS(60);

    MyGame game;
    Engine::Start();

    return 0;
}
```
