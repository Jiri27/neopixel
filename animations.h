#ifndef __ANIMATIONS__
#define __ANIMATIONS__

#include "neopixel.h"

#define _aqua_ 0xff00ff
#define purple 0x00ffff
#define black_ 0x000000
#define __red_ 0x00ff00
#define green_ 0xff0000
#define _blue_ 0x0000ff

uint32_t checks_animation[2][65] = {
    {
        black_, purple, black_, purple, black_, purple, black_, purple,
        purple, black_, purple, black_, purple, black_, purple, black_,
        black_, purple, black_, purple, black_, purple, black_, purple,
        purple, black_, purple, black_, purple, black_, purple, black_,
        black_, purple, black_, purple, black_, purple, black_, purple,
        purple, black_, purple, black_, purple, black_, purple, black_,
        black_, purple, black_, purple, black_, purple, black_, purple,
        purple, black_, purple, black_, purple, black_, purple, black_, 0
    },
    {
        _aqua_, black_, _aqua_, black_, _aqua_, black_, _aqua_, black_,
        black_, _aqua_, black_, _aqua_, black_, _aqua_, black_, _aqua_,
        _aqua_, black_, _aqua_, black_, _aqua_, black_, _aqua_, black_,
        black_, _aqua_, black_, _aqua_, black_, _aqua_, black_, _aqua_,
        _aqua_, black_, _aqua_, black_, _aqua_, black_, _aqua_, black_,
        black_, _aqua_, black_, _aqua_, black_, _aqua_, black_, _aqua_,
        _aqua_, black_, _aqua_, black_, _aqua_, black_, _aqua_, black_,
        black_, _aqua_, black_, _aqua_, black_, _aqua_, black_, _aqua_, 0
    }
};
uint32_t smile_animation[3][65] = {
    {
        black_, black_, green_, green_, green_, green_, black_, black_,
        black_, green_, black_, black_, black_, black_, green_, black_,
        green_, black_, green_, black_, black_, green_, black_, green_,
        green_, black_, black_, black_, black_, black_, black_, green_,
        green_, black_, green_, black_, black_, green_, black_, green_,
        green_, black_, black_, green_, green_, black_, black_, green_,
        black_, green_, black_, black_, black_, black_, green_, black_,
        black_, black_, green_, green_, green_, green_, black_, black_,0
    },
    {
        black_, black_, __red_, __red_, __red_, __red_, black_, black_,
        black_, __red_, black_, black_, black_, black_, __red_, black_,
        __red_, black_, __red_, black_, black_, __red_, black_, __red_,
        __red_, black_, black_, black_, black_, black_, black_, __red_,
        __red_, black_, black_, __red_, __red_, black_, black_, __red_,
        __red_, black_, __red_, black_, black_, __red_, black_, __red_,
        black_, __red_, black_, black_, black_, black_, __red_, black_,
        black_, black_, __red_, __red_, __red_, __red_, black_, black_,0
    },
    {
        black_, black_, _blue_, _blue_, _blue_, _blue_, black_, black_,
        black_, _blue_, black_, black_, black_, black_, _blue_, black_,
        _blue_, black_, _blue_, black_, black_, _blue_, black_, _blue_,
        _blue_, black_, black_, black_, black_, black_, black_, _blue_,
        _blue_, black_, _blue_, _blue_, _blue_, _blue_, black_, _blue_,
        _blue_, black_, black_, black_, black_, black_, black_, _blue_,
        black_, _blue_, black_, black_, black_, black_, _blue_, black_,
        black_, black_, _blue_, _blue_, _blue_, _blue_, black_, black_,0
    }
};


#endif