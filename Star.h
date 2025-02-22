//
// Created by Nino Dafonte on 22/2/25.
//

#ifndef STAR_H
#define STAR_H

#include <SDL.h>

class Star {
public:
    SDL_FRect transform{};
    Uint32 star_color;

    Star(const float x, const float y, const Uint32 color) {
        transform.x = x;
        transform.y = y;
        transform.w = 1;
        transform.h = 1;
        this->star_color = color;
    }

    void draw(const SDL_Surface *screenSurface) const {
        Uint32 *pixel = static_cast<Uint32 *>(screenSurface->pixels) + static_cast<long>(
                            transform.y * static_cast<float>(screenSurface->pitch) / 4 + transform.x);
        *pixel = star_color;
    }

    void move(const float x, const float y) {
        transform.x = x;
        transform.y = y;
    }

    void setColor(const Uint32 color) {
        this->star_color = color;
    }
};

#endif //STAR_H
