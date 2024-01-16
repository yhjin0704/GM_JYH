#include "Head.h"
#include <conio.h>
#include <ConsoleEngine/EngineCore.h>
#include "BodyManager.h"
#include "Body.h"
#include "ContentsEnum.h"

// 
// 1. ���� Ư�� �������� �����ߴٸ� ���� �Է¶��� �� �ݴ�������δ� ������ ����.
//    ���� �̵��ϴ� ������ �ݴ�������δ� ���� �ȵȴ�.
// 2. ���� �̵��� �ؼ� CurBody�� ȹ���ߴٸ� �� �������� �� �ٵ�� ���� ����;� �Ѵ�.

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
			FollowFront(this);
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
			FollowFront(this);
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
			FollowFront(this);
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
			FollowFront(this);
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
		MsgBoxAssert("������ �ִ� �ٵ� �������� �ʽ��ϴ�.");
		return;
	}

	Body* CurBody = BodyManager::GetCurBody();

	if (CurBody->GetPos() == GetPos())
	{
		BodyManager::ResetBody();
		Body* NewBody = GetCore()->CreateObject<Body>(SnakeType::Body, SnakeType::Body);
		if (nullptr == Back)
		{
			Back = NewBody;
			NewBody->SetFront(this);
			NewBody->SetPos(PrevPos);
		}
		else
		{
			// BackCheck == ù �ٵ��� Back
			Part* BackCheck = Back;
			while (nullptr != BackCheck->GetBack())
			{
				BackCheck = BackCheck->GetBack();
			}
			NewBody->SetFront(BackCheck);
			BackCheck->SetBack(NewBody);
			NewBody->SetPos(BackCheck->GetPrevPos());
		}
	}
	
}