#include "Engine.h"
#include <math.h>
#include <windows.h>
#include "lodepng.h"

int Engine::SCREEN_WIDTH;
int Engine::SCREEN_HEIGHT;
unsigned int Engine::refreshMillis = 1000/60;
bool Engine::full_screen = false;
int Engine::mouseX = 0;
int Engine::mouseY = 0;
int Engine::windowed_w,Engine::windowed_h;
bool Engine::mouse[2];

bool Engine::keyStates[256];


void Engine::Init(const char* title,const unsigned int width,const unsigned int height,int gl_argc, char** gl_argv)
{
    glutInit(&gl_argc, gl_argv);

    SCREEN_WIDTH = width;
    SCREEN_HEIGHT = height;

    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutInitWindowSize(SCREEN_WIDTH, SCREEN_HEIGHT);
    glutInitWindowPosition(0, 0);
    glutCreateWindow(title);
    glutDisplayFunc(display);

    glutMotionFunc(onMouseMotion);
    glutPassiveMotionFunc(onMouseMotion);
    glutReshapeFunc(onReshape);
    glutMouseFunc(onMouseClick);

    glutKeyboardFunc(onKeyPress);
    glutKeyboardUpFunc(onKeyRelease);

    glClearColor(1.0, 1.0, 1.0, 1.0);
    glColor4f(1.0, 0.0, 0.0,0.0);
    glPointSize(1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, SCREEN_WIDTH-1, 0.0, SCREEN_HEIGHT-1);

    Start();
    glutTimerFunc(0, update, 0);
    glutMainLoop();

}
void Engine::display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    Render();

    glFlush();
}

void Engine::onReshape(int width, int height)
{
    // Update the SCREEN_WIDTH and SCREEN_HEIGHT when the window is resized
    SCREEN_WIDTH = width;
    SCREEN_HEIGHT = height;

    // Set the viewport and projection matrix accordingly
    glViewport(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, SCREEN_WIDTH, 0, SCREEN_HEIGHT, -1, 1);
    glMatrixMode(GL_MODELVIEW);
}



void Engine::update(int value)
{
    glutPostRedisplay();

    Update();

    glutTimerFunc(refreshMillis, update, 0);
}
void Engine::onMouseClick(int button, int state, int x, int y)
{
    mouse[button] = state == GLUT_DOWN;
    mouseX = x;
    mouseY = SCREEN_HEIGHT-y;
}


void Engine::onMouseMotion(int x, int y)
{
    mouseX = x;
    mouseY = SCREEN_HEIGHT-y;
}
void Engine::onKeyPress(unsigned char key, int x, int y)
{
    keyStates[key] = true;
}
void Engine::onKeyRelease(unsigned char key, int x, int y)
{
    keyStates[key] = false;
}
void Engine::SetTargetFPS(unsigned int FPS)
{
    if (FPS == 0)
    {
        refreshMillis = 0;
        return;
    }
    refreshMillis = 1000/FPS;
}

void Draw_Circle(float centerX, float centerY, float radius, float angleStart, float angleEnd, int numSegments)
{

    const float angleStep = (angleEnd - angleStart) / numSegments;

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(centerX, centerY); // Center point

    for (int i = 0; i <= numSegments; ++i)
    {
        const float angle = angleStart + i * angleStep;
        const float x = centerX + radius * cos(angle * M_PI / 180.0f);
        const float y = centerY + radius * sin(angle * M_PI / 180.0f);
        glVertex2f(x, y);
    }

    glEnd();

}
void Draw_Rectangle(float x, float y, float width, float height) {
    // Calculate the coordinates of the four corners of the rectangle
    float x1 = x;
    float y1 = y;
    float x2 = x + width;
    float x3 = x;
    float y3 = y + height;
    float x4 = x + width;
    float y4 = y + height;

    glBegin(GL_TRIANGLES);

    // First triangle (top-left, top-right, bottom-left)
    glVertex2f(x1, y1);
    glVertex2f(x2, y1);
    glVertex2f(x3, y3);

    // Second triangle (top-right, bottom-left, bottom-right)
    glVertex2f(x2, y1);
    glVertex2f(x3, y3);
    glVertex2f(x4, y4);

    glEnd();
}

void Engine::ToggleFullScreen()
{

    full_screen = !full_screen;
    if (full_screen)
    {
        windowed_w = SCREEN_WIDTH;
        windowed_h = SCREEN_HEIGHT;
        glutFullScreen();
    }
    else
    {
        glutReshapeWindow(windowed_w,windowed_h);
    }
}
bool PNG::load(const char* filename)

{
    // Read PNG file using WinAPI
    HANDLE file = CreateFile(filename, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
    if (file == INVALID_HANDLE_VALUE)
    {
        return false;
    }

    DWORD fileSize = GetFileSize(file, NULL);
    std::vector<BYTE> fileData(fileSize);
    DWORD bytesRead;
    ReadFile(file, fileData.data(), fileSize, &bytesRead, NULL);
    CloseHandle(file);

    // Decode PNG image using lodepng
    std::vector<unsigned char> image;
    unsigned int width, height;
    unsigned int error = lodepng::decode(image, width, height, fileData.data(), fileData.size());
    if (error)
    {
        return false;
    }

    // Convert image data to Pixel objects
    this->width = static_cast<int>(width);
    this->height = static_cast<int>(height);

    for (size_t i = 0; i < image.size(); i += 4)
    {
        Pixel pixel;
        pixel.x = static_cast<int>(i / 4) % this->width;
        pixel.y = this->height - static_cast<int>(i / 4) / this->width;
        pixel.r = image[i];
        pixel.g = image[i + 1];
        pixel.b = image[i + 2];
        pixel.a = image[i + 3];
        if (pixel.a == 0)
        {
            continue;
        }
        pixels.push_back(pixel);
    }

    return true;
}
void PNG::display(int x,int y)
{
    //glClear(GL_COLOR_BUFFER_BIT);

    //glMatrixMode(GL_MODELVIEW);
    //glLoadIdentity();


    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glPointSize(1.0);
    glPushMatrix();

    // Calculate the center point of the shape
    float centerX = static_cast<float>(width) / 2.0f;
    float centerY = static_cast<float>(height) / 2.0f;

    // Apply scaling and translation
    glTranslatef(centerX+x, centerY+y, 0.0f);

    glScalef(flip_h ? -1 : 1, flip_v ? -1 : 1, 1.0f); // Flip the image vertically by negating the scaling factor for the y-axis
    glTranslatef(-centerX, -centerY, 0.0f);

    glBegin(GL_POINTS);

    // Iterate over pixels and set colors
    for (const auto& pixel : pixels)
    {
        glColor4ub(pixel.r, pixel.g, pixel.b, pixel.a);

        //glVertex2i((flip_h ? (x/width)-(width*2) : x)+pixel.x, (flip_v ? y-(height*2) : y)+pixel.y);
        glVertex2i(pixel.x, pixel.y);

    }
    glEnd();
    glDisable(GL_BLEND);
    glPopMatrix();
    //glutSwapBuffers();
}
