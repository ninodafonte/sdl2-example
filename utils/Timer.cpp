//
// Created by Nino Dafonte on 22/2/25.
//

#include "Timer.h"
#include <SDL.h>

Timer* Timer::instance = nullptr;

void Timer::Tick() {
    deltaTime = (SDL_GetTicks() - lastTime) * (TARGET_FPS / 1000.0f);

    if (deltaTime > TARGET_DELTATIME) {
        deltaTime = TARGET_DELTATIME;
    }

    lastTime = SDL_GetTicks();
}
