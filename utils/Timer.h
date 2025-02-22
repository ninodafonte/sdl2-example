//
// Created by Nino Dafonte on 22/2/25.
// Based on: https://www.youtube.com/watch?v=XnUMm-uNmvY
//

#ifndef TIMER_H
#define TIMER_H

constexpr int TARGET_FPS = 60;
constexpr float TARGET_DELTATIME = 1.0f / TARGET_FPS;

class Timer {
public:
    void Tick();

    [[nodiscard]] inline float GetDeltaTime() const { return deltaTime; }
    static Timer *GetInstance() { return instance = (instance != nullptr) ? instance : new Timer(); }

private:
    Timer() = default;

    static Timer *instance;
    float deltaTime = 0.0f;
    float lastTime = 0;
};


#endif //TIMER_H
