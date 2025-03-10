//
// LTimer by lazyfoo (https://lazyfoo.net/tutorials/SDL/23_advanced_timers/index.php) on 22/2/25.
//

#ifndef LTIMER_H
#define LTIMER_H
#include <SDL.h>

//The application time based timer
class LTimer
{
public:
    //Initializes variables
    LTimer();

    //The various clock actions
    void start();
    void stop();
    void pause();
    void unpause();

    //Gets the timer's time
    Uint32 getTicks();

    //Checks the status of the timer
    bool isStarted();
    bool isPaused();

private:
    //The clock time when the timer started
    Uint32 mStartTicks;

    //The ticks stored when the timer was paused
    Uint32 mPausedTicks;

    //The timer status
    bool mPaused;
    bool mStarted;
};

#endif //LTIMER_H
