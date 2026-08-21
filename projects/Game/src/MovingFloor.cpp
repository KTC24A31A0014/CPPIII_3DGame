#include "MovingFloor.h"

#include <UniDx/Time.h>

using namespace UniDx;

void MovingFloor::OnEnable()
{
	basePos = transform->localPosition; // 開始位置を記録
}

void MovingFloor::Update()
{
	float t = std::sin(Time::time * speed);
	transform->localPosition = basePos + axis * (t * amplitude);
}