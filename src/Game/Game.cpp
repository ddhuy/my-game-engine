#include <iostream>

#include <SDL2/SDL_image.h>
#include <glm/glm.hpp>

#include "Game.h"
#include "../Logger/Logger.h"
#include "../ECS/ECS.h"


Game::Game()
{
    Logger::Log("Game Constructor called!");
}

Game::~Game()
{
    Logger::Log("Game Destructor called!");
}

void Game::Initialize()
{
    SDL_DisplayMode displayMode;

    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        Logger::Err("Error initializing SDL.");
        return;
    }

    SDL_GetDisplayMode(0, 0, &displayMode);
    windowWidth = displayMode.w;
    windowHeigh = displayMode.h;
    window = SDL_CreateWindow("My Game Engine",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        windowWidth,
        windowHeigh,
        SDL_WINDOW_BORDERLESS);
    if (!window)
    {
        Logger::Err("Error creating SDL window.");
        return;
    }
    
    renderer = SDL_CreateRenderer(window, -1, SDL_WINDOW_FULLSCREEN);
    if (!renderer)
    {
        Logger::Err("Error creating SDL Renderer.");
        return;
    }

    SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN);
    isRunning = true;
}

void Game::ProcessInput()
{
    SDL_Event sdlEvent;
    
    while (SDL_PollEvent(&sdlEvent))
    {
        switch (sdlEvent.type)
        {
        case SDL_QUIT:
            isRunning = false;
            break;

        case SDL_KEYDOWN:
            if (sdlEvent.key.keysym.sym == SDLK_ESCAPE)
                isRunning = false;
            break;

        default:
            break;
        }
    }
}

void Game::Setup()
{
    // TODO:
    // Entity tank = registry.CreateEntity();
    // tank.AddComponent<TransformComponent>();
    // tank.AddComponent<BoxColliderComponent>();
    // tank.AddComponent<SpriteComponent>("./assets/images/tank.png");
}


void Game::Update()
{
    // if we are too fast, waste some time until we reach the MILLISECS_PER_FRAME
    // while (!SDL_TICKS_PASSED(SDL_GetTicks(), millisecsPreviousFrame + MILLISECS_PER_FRAME))
    //     ;
    // Another method to save CPU resource than using dummy while loop
    // int timeToWait = MILLISECS_PER_FRAME - (SDL_GetTicks() - millisecsPreviousFrame);
    // if (timeToWait > 0 && timeToWait <= MILLISECS_PER_FRAME)
    //     SDL_Delay(timeToWait);

    // The difference in ticks since the last frame, converted to seconds;
    double deltaTime = (SDL_GetTicks() - millisecsPreviousFrame) / 1000.0;

    // Store the current frame time
    millisecsPreviousFrame = SDL_GetTicks();

    // TODO:
    // MovementSystem.Update();
    // CollisionSystem.Update();
    // DamageSystem.Update();
}

void Game::Render()
{
    SDL_SetRenderDrawColor(renderer, 21, 21, 21, 255);
    SDL_RenderClear(renderer);

    // TODO: Render game objects...

    SDL_RenderPresent(renderer);
}


void Game::Run()
{
    Setup();
    while (isRunning)
    {
        ProcessInput();
        Update();
        Render();
    }
}

void Game::Destroy()
{
    if (renderer)
        SDL_DestroyRenderer(renderer);
    if (window)
        SDL_DestroyWindow(window);
    SDL_Quit();
}
