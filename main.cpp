#include "Engine.h"
#include <iostream>

bool selecting = false;
int m1x = 0;
int m1y = 0;
int m2y,m2x;

void selectarea()
{
    if (selecting)
    {
        glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glColor4f(1.0, 0.0, 0.0, 0.5);

    glBegin(GL_TRIANGLES);
    glBegin(GL_TRIANGLES);
        glVertex2i(m1x, m1y);
        glVertex2i(m2x, m1y);
        glVertex2i(m1x, m2y);

        glVertex2i(m2x, m1y);
        glVertex2i(m2x, m2y);
        glVertex2i(m1x, m2y);
    glEnd();

    glDisable(GL_BLEND);
    }
}

void Engine::Start()
{
    Engine::SetTargetFPS(30);

}
void Engine::Update()
{
    if (keyStates[KeyCode::KEY_SPACE])
    {
        ToggleFullScreen();
    }
    if (mouse[0])
    {
        if (!selecting)
        {
            m1x = mouseX;
            m1y = mouseY;
            selecting = true;
        }
    }
    if (!mouse[0] && selecting)
    {
        selecting = false;
    }
    if (selecting)
    {
        m2x = mouseX;
        m2y = mouseY;
    }

}
void Engine::Render()
{
    selectarea();
}

int main(int argc, char** argv) {

    Engine::Init("Crystal Engine | Ali Nakhaee",800,600);
    return 0;
}
