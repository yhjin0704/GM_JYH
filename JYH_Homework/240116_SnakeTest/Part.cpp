#include "Part.h"

void Part::FollowFront(Part* _Part)
{
	Part* NextBody = _Part->Back;
	while (nullptr != NextBody)
	{
		NextBody->SetPrevPos(NextBody->GetPos());
		NextBody->SetPos((NextBody->GetFront())->GetPrevPos());
		NextBody = NextBody->Back;
	}
}