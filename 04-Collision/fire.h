#pragma once
#include "GameObject.h"

#define FIRE_BBOX_WIDTH  15//16
#define FIRE_BBOX_HEIGHT 35//16 chi bao ngoai cua vao cham

class CFire : public CGameObject
{
public:
	virtual void Render();
	virtual void GetBoundingBox(float &l, float &t, float &r, float &b);
};