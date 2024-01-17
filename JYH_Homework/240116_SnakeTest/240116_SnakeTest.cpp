#include <iostream>
#include <ConsoleEngine/EngineCore.h>
#include "Head.h"
#include "BodyManager.h"
#include "GlobalValue.h"
#include "ContentsEnum.h"

int main()
{
    EngineCore EngineCore;
    EngineCore.Init({ 30, 30 });

    {
        // Player* NewObject = new Player();
        GBodyManager = EngineCore.CreateManager<BodyManager>(0);
        //GWinManager = EngineCore.CreateManager<WinManager>(1);
    }

    {
        Head* NewPlayer = EngineCore.CreateObject<Head>();
        NewPlayer->SetPos({ EngineCore.Screen.GetScreenX() / 2, EngineCore.Screen.GetScreenY() / 2 });
        int a = 0;
    }

    EngineCore.Start();
}
