#ifndef ENGINE_H
#define ENGINE_H
#include <GL/glut.h>
#include <vector>

/*
    Todo :
        Add Text Rendering

*/


class Engine {
public:
  static void Init(const char* title,const unsigned int width,const unsigned int height,int gl_argc = 0, char** gl_argv = nullptr);

  // The Engine call this function only once (At the beginning of the game)
  static void Start();
  // Use this function to render your shapes on the game screen
  static void Render();
  // This function runs in each frames of the game (Before the Renderer)
  static void Update();

  // Use this function to limit the Frames Per Second of the game screen's refresh rate
  // 0 means no limit
  static void SetTargetFPS(unsigned int FPS);

  static void ToggleFullScreen();

  static void PlayAudio(const char* path);


private:
    static bool full_screen;

    static unsigned int windowed_w,windowed_h;

    static unsigned int SCREEN_WIDTH;
    static unsigned int SCREEN_HEIGHT;
    static unsigned int refreshMillis;

    static int mouseX ;
    static int mouseY;
    static bool mouse[2];

    static bool keyStates[256];


    static void display();
    static void onMouseMotion(int x, int y);
    static void onReshape(int width, int height);
    static void onMouseClick(int button, int state, int x, int y);
    static void onKeyPress(unsigned char key, int x, int y);
    static void onKeyRelease(unsigned char key, int x, int y);
    static void update(int value);
};
void Draw_Circle(float centerX, float centerY, float radius, float angleStart, float angleEnd, int numSegments);


void Draw_Rectangle(float x, float y, float width, float height);

struct KeyCode
{
    static const unsigned short KEY_A = 'a';
    static const unsigned short KEY_B = 'b';
    static const unsigned short KEY_C = 'c';
    static const unsigned short KEY_D = 'd';
    static const unsigned short KEY_E = 'e';
    static const unsigned short KEY_F = 'f';
    static const unsigned short KEY_G = 'g';
    static const unsigned short KEY_H = 'h';
    static const unsigned short KEY_I = 'i';
    static const unsigned short KEY_J = 'j';
    static const unsigned short KEY_K = 'k';
    static const unsigned short KEY_L = 'l';
    static const unsigned short KEY_M = 'm';
    static const unsigned short KEY_N = 'n';
    static const unsigned short KEY_O = 'o';
    static const unsigned short KEY_P = 'p';
    static const unsigned short KEY_Q = 'q';
    static const unsigned short KEY_R = 'r';
    static const unsigned short KEY_S = 's';
    static const unsigned short KEY_T = 't';
    static const unsigned short KEY_U = 'u';
    static const unsigned short KEY_V = 'v';
    static const unsigned short KEY_W = 'w';
    static const unsigned short KEY_X = 'x';
    static const unsigned short KEY_Y = 'y';
    static const unsigned short KEY_Z = 'z';

    static const unsigned short KEY_0 = '0';
    static const unsigned short KEY_1 = '1';
    static const unsigned short KEY_2 = '2';
    static const unsigned short KEY_3 = '3';
    static const unsigned short KEY_4 = '4';
    static const unsigned short KEY_5 = '5';
    static const unsigned short KEY_6 = '6';
    static const unsigned short KEY_7 = '7';
    static const unsigned short KEY_8 = '8';
    static const unsigned short KEY_9 = '9';


    static const unsigned short KEY_SPACE = 32;
    static const unsigned short KEY_ENTER = 13;
    static const unsigned short KEY_SHIFT = 16;
    static const unsigned short KEY_CTRL = 17;

};


struct Pixel
{
    int x, y;
    unsigned short r, g, b, a;
};

class PNG
{
public:
    bool flip_h = false;
    bool flip_v = false;
    unsigned int width, height;
    std::vector<Pixel> pixels;

    bool load(const char* filename);

    void display(int x = 0,int y = 0);
};



#endif // ENGINE_H
