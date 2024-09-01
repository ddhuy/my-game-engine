#include "Game.h"

#include <iostream>

#include <SDL2/SDL_image.h>

#include <glm/glm.hpp>


Game::Game()
{
    std::cout << "Game Constructor called!" << std::endl;
}

Game::~Game()
{
    std::cout << "Game Destructor called!" << std::endl;
}

void Game::Initialize()
{
    SDL_DisplayMode displayMode;

    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        std::cerr << "Error initializing SDL." << std::endl;
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
        std::cerr << "Error creating SDL window." << std::endl;
        return;
    }
    
    renderer = SDL_CreateRenderer(window, -1, SDL_WINDOW_FULLSCREEN);
    if (!renderer)
    {
        std::cerr << "Error creating SDL Renderer." << std::endl;
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

glm::vec2 playerPosition;
glm::vec2 playerVelocity;

void Game::Setup()
{
    playerPosition = glm::vec2{10.0, 20.0};
    playerVelocity = glm::vec2(0.5, 0.0);
}


void Game::Update()
{
    // if we are too fast, waste some time until we reach the MILLISECS_PER_FRAME
    while (!SDL_TICKS_PASSED(SDL_GetTicks(), millisecsPreviousFrame + MILLISECS_PER_FRAME))
        ;

    // Store the current frame time
    millisecsPreviousFrame = SDL_GetTicks();

    playerPosition.x += playerVelocity.x;
    playerPosition.y += playerVelocity.y;
}

void Game::Render()
{
    SDL_SetRenderDrawColor(renderer, 21, 21, 21, 255);
    SDL_RenderClear(renderer);

    // SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    // SDL_Rect player = {10, 10, 200, 200};
    // SDL_RenderFillRect(renderer, &player);

    // Load a PNG texture
    SDL_Surface* surface = IMG_Load("./assets/images/tank-tiger-right.png");
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    // What is the destination rectangle that we ant to place our texture
    SDL_Rect dstRect = {
        static_cast<int>(playerPosition.x),
        static_cast<int>(playerPosition.y),
        32,
        32};
    SDL_RenderCopy(renderer, texture, NULL, &dstRect);
    SDL_DestroyTexture(texture);

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
