#include "Engine.h"
#include <iostream>


void Engine::Start()
{
    Engine::SetTargetFPS(30);

}
void Engine::Update()
{
    

}
void Engine::Render()
{
    
}

int main(int argc, char** argv) {

    Engine::Init("OpenGL Engine | Ali Nakhaee",800,600);
    return 0;
}
