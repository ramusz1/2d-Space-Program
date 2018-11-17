#pragma once

class WindowEventHandler
{
public:

    virtual void eventHandler(int key, int scancode, int action, int mods) = 0;
};