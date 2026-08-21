#pragma once

#include <UniDx.h>
#include <UniDx/Behaviour.h>

class MovingFloor : public UniDx::Behaviour
{
	public:
		UniDx::Vector3 axis = UniDx::Vector3::right;
		float amplitude = 10.0f;
		float speed = 1.0f;

		virtual void OnEnable() override;
		virtual void Update() override;

	private:
		UniDx::Vector3 basePos;

};

