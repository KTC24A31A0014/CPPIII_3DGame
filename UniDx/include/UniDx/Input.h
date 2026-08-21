#pragma once

#include <Keyboard.h>
#include <Mouse.h>
#include "UniDxDefine.h"


namespace UniDx
{

using DirectX::Keyboard;
using DirectX::Mouse;


// Input情報
class Input
{
public:
    static void initialize()
    {
        keyboard = std::make_unique<Keyboard>();
        mouse = std::make_unique<Mouse>();
    }

    static void update()
    {
        prevKeyState = nowKeyState;
        nowKeyState = keyboard->GetState();
        mouseState = mouse->GetState();
    }

    static bool GetKey(Keyboard::Keys key) { return nowKeyState.IsKeyDown(key); }
    static bool GetKeyDown(Keyboard::Keys key) { return prevKeyState.IsKeyUp(key) && nowKeyState.IsKeyDown(key); }
    static bool GetKeyUp(Keyboard::Keys key) { return prevKeyState.IsKeyDown(key) && nowKeyState.IsKeyUp(key); }
    static Mouse::State GetMouseState() { return mouseState; }
    static Mouse* GetMouse() { return mouse.get(); }

protected:
    static std::unique_ptr<Keyboard> keyboard;
    static Keyboard::State nowKeyState;
    static Keyboard::State prevKeyState;
    static std::unique_ptr<Mouse> mouse;
    static Mouse::State mouseState;
};

}
