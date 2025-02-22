//Using SDL and standard IO
#include <SDL.h>
#include <cstdio>
#include <vector>
#include "Star.h"
#include "utils/Timer.h"

#define FPS 120

//Screen dimension constants
constexpr int SCREEN_WIDTH = 640;
constexpr int SCREEN_HEIGHT = 480;
constexpr int STARS_NUMBER = 100;

Uint64 lastTime = 0, currentTime;
double deltaTime;
float msFrame = 1 / (FPS / 1000.0f);
std::vector<Star> stars;

int main() {
    //The window we'll be rendering to
    SDL_Window *window = nullptr;

    //The surface contained by the window

    //Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
    } else {
        //Create window
        window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH,
                                  SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
        if (window == nullptr) {
            printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
        } else {
            SDL_Surface *screenSurface = nullptr;
            //Get window surface
            screenSurface = SDL_GetWindowSurface(window);

            //Hack to get window to stay up
            SDL_Event e;
            bool quit = false;

            // add some stars
            for (int i = 0; i < STARS_NUMBER; i++) {
                const int gray_color = static_cast<int>(random()) % 255;
                stars.emplace_back(
                    random() % SCREEN_WIDTH,
                    random() % SCREEN_HEIGHT,
                    SDL_MapRGB(screenSurface->format, gray_color, gray_color, gray_color)
                );
            }

            while (quit == false) {
                while (SDL_PollEvent(&e)) {
                    if (e.type == SDL_QUIT) quit = true;
                }

                Timer::GetInstance()->Tick();
                deltaTime = Timer::GetInstance()->GetDeltaTime();

                //Fill the surface black
                SDL_FillRect(screenSurface, nullptr, SDL_MapRGB(screenSurface->format, 0, 0, 0));

                // Paint the stars
                SDL_LockSurface(screenSurface);
                for (auto &star: stars) {
                    if (const int intended_movement = star.transform.x + static_cast<int>(ceil(1 * deltaTime));
                        intended_movement > SCREEN_WIDTH) {
                        star.move(0, static_cast<int>(random()) % SCREEN_HEIGHT);
                        const int gray_color = static_cast<int>(random()) % 255;
                        star.setColor(SDL_MapRGB(screenSurface->format, gray_color, gray_color, gray_color));
                    } else {
                        star.move(intended_movement, star.transform.y);
                    }
                    star.draw(screenSurface);
                }
                SDL_UnlockSurface(screenSurface);

                //Update the surface
                SDL_UpdateWindowSurface(window);

                if (deltaTime < msFrame) {
                    SDL_Delay(msFrame - deltaTime);
                }
            }
        }
    }

    //Destroy window
    SDL_DestroyWindow(window);

    //Quit SDL subsystems
    SDL_Quit();

    return 0;
}
