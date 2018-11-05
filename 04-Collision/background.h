#pragma once
#include "GameObject.h"

#define Background_BBOX_WIDTH  100//16
#define Background_BBOX_HEIGHT 15//16 chi bao ngoai cua vao cham

class CBackground : public CGameObject
{
public:
	virtual void Render(float &xcamera, float &ycamera); //them x y trong render 
	virtual void GetBoundingBox(float &l, float &t, float &r, float &b);
};