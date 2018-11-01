#include "background.h"

void CBackground::Render()
{
	animations[0]->Render(x, y);
	//RenderBoundingBox();
}

void CBackground::GetBoundingBox(float &l, float &t, float &r, float &b)
{
	l = x;
	t = y;
	r = x + Background_BBOX_WIDTH;
	b = y + Background_BBOX_HEIGHT;
}