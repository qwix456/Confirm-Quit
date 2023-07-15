#pragma once

#include "includes.h"

namespace PlayLayerNew
{
    inline void (*onQuit)(PlayLayer*);
    void onQuitHooks(PlayLayer* self);

    void Quit();
}