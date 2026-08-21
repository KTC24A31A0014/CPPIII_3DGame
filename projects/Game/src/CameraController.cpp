#include "CameraController.h"

#include <UniDx/Input.h>
#include <UniDx/Time.h>

#include "Player.h"

#include <algorithm>


using namespace DirectX;
using namespace UniDx;

void CameraController::OnEnable()
{
    Quaternion rot = Quaternion::AngleAxis(35, Vector3::right);
    transform->localRotation = rot;

    auto dir = player->transform->position - transform->position;
    float planar = std::sqrt(dir.x * dir.x + dir.z * dir.z);
    length = dir.magnitude();
    yaw = std::atan2(dir.x, dir.z) * Rad2Deg;
    pitch = std::abs(std::atan2(dir.y, planar) * Rad2Deg);
}


void CameraController::Update()
{
    OutputDebugStringA("CameraController Update called\n");

    const float mouseSensi = 0.2f;
    auto mouseState = Input::GetMouseState();

    yaw -= mouseState.x * mouseSensi;
    pitch = std::clamp(pitch - mouseState.y * mouseSensi, 0.0f, 90.0f);

    Quaternion rot = Quaternion::Euler(pitch, yaw, 0.0f);
    transform->rotation = rot;
    transform->position = (Vector3::forward * rot) * -length + player->transform->position;
}
