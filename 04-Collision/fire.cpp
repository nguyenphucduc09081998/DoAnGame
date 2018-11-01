#include "fire.h"

void CFire::Render()
{
	animations[0]->Render(x, y);
	//RenderBoundingBox();
}

void CFire::GetBoundingBox(float &l, float &t, float &r, float &b)
{
	l = x;
	t = y;
	r = x + FIRE_BBOX_WIDTH;
	b = y + FIRE_BBOX_HEIGHT;
}