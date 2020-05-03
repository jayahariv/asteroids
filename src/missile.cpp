#include "missile.h"

void Missile::Update()
{
    // todo: include angle !!
    x += _speed;
    y -= _speed;
}