#include "background.h"

void CBackground::Render(float &xcamera, float &ycamera)
{
	animations[0]->Render(x - xcamera, y - ycamera);
	//RenderBoundingBox();
}

void CBackground::GetBoundingBox(float &l, float &t, float &r, float &b)
{
	l = x;
	t = y;
	r = x + Background_BBOX_WIDTH;
	b = y + Background_BBOX_HEIGHT;

}