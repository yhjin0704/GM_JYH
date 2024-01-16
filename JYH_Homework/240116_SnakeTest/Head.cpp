#include "Head.h"
#include <conio.h>
#include <ConsoleEngine/EngineCore.h>
#include "BodyManager.h"
#include "Body.h"

// 
// 1. 내가 특정 방향으로 진행했다면 다음 입력때는 그 반대방향으로는 갈수가 없다.
//    내가 이동하는 방향의 반대방향으로는 가면 안된다.
// 2. 내가 이동을 해서 CurBody를 획득했다면 그 다음부터 그 바디는 나를 따라와야 한다.

Head::Head()
{
}

void Head::Update()
{
	int InputCount = _kbhit();
	if (0 == InputCount)
	{
		return;
	}

	int Select = _getch();

	// InputCount = _kbhit();

	// X Y
	// 1 0

	switch (Select)
	{
	case 'A':
	case 'a':
		if ('d' == PrevMove)
		{
		}
		else
		{
			PrevMove = 'a';
			PrevPos = GetPos();
			AddPos(Left);
		}
		break;
	case 'S':
	case 's':
		if ('w' == PrevMove)
		{
		}
		else
		{
			PrevMove = 's';
			PrevPos = GetPos();
			AddPos(Down);
		}
		break;
	case 'W':
	case 'w':
		if ('s' == PrevMove)
		{
		}
		else
		{
			PrevMove = 'w';
			PrevPos = GetPos();
			AddPos(Up);
		}
		break;
	case 'D':
	case 'd':
		if ('a' == PrevMove)
		{
		}
		else
		{
			PrevMove = 'd';
			PrevPos = GetPos();
			AddPos(Right);
		}
		break;
	case '1':
		GetCore()->EngineEnd();
		break;
	default:
		break;
	}

	if (nullptr == BodyManager::GetCurBody())
	{
		MsgBoxAssert("먹을수 있는 바디가 존재하지 않습니다.");
		return;
	}

	Body* CurBody = BodyManager::GetCurBody();

	if (CurBody->GetPos() == GetPos())
	{
		Back = CurBody;
		BodyManager::ResetBody();
		Body* NewBody = GetCore()->CreateObject<Body>();
		int a = 0;
	}
	
}