#ifndef ENGINE_H
#define ENGINE_H
#include <GL/glut.h>
#include <vector>

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


private:
    static bool full_screen;

    static int windowed_w,windowed_h;

    static int SCREEN_WIDTH;
    static int SCREEN_HEIGHT;
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
    static const int KEY_A = 'a';
    static const int KEY_B = 'b';
    static const int KEY_C = 'c';
    static const int KEY_D = 'd';
    static const int KEY_E = 'e';
    static const int KEY_F = 'f';
    static const int KEY_G = 'g';
    static const int KEY_H = 'h';
    static const int KEY_I = 'i';
    static const int KEY_J = 'j';
    static const int KEY_K = 'k';
    static const int KEY_L = 'l';
    static const int KEY_M = 'm';
    static const int KEY_N = 'n';
    static const int KEY_O = 'o';
    static const int KEY_P = 'p';
    static const int KEY_Q = 'q';
    static const int KEY_R = 'r';
    static const int KEY_S = 's';
    static const int KEY_T = 't';
    static const int KEY_U = 'u';
    static const int KEY_V = 'v';
    static const int KEY_W = 'w';
    static const int KEY_X = 'x';
    static const int KEY_Y = 'y';
    static const int KEY_Z = 'z';

    static const int KEY_0 = '0';
    static const int KEY_1 = '1';
    static const int KEY_2 = '2';
    static const int KEY_3 = '3';
    static const int KEY_4 = '4';
    static const int KEY_5 = '5';
    static const int KEY_6 = '6';
    static const int KEY_7 = '7';
    static const int KEY_8 = '8';
    static const int KEY_9 = '9';


    static const int KEY_SPACE = 32;
    static const int KEY_ENTER = 13;
    static const int KEY_SHIFT = 16;
    static const int KEY_CTRL = 17;

};


struct Pixel
{
    int x, y;
    int r, g, b, a;
};

class PNG
{
public:
    bool flip_h = false;
    bool flip_v = false;
    int width, height;
    std::vector<Pixel> pixels;

    bool load(const char* filename);

    void display(int x = 0,int y = 0);
};



#endif // ENGINE_H
