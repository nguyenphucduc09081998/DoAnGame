#pragma once
#include "GameObject.h"
#include "Textures.h" 

#define Background_BBOX_WIDTH  770//16
#define Background_BBOX_HEIGHT 185//16 chi bao ngoai cua vao cham

class CBackground : public CGameObject
{
public:
	virtual void Render(float &xcamera, float &ycamera); //them x y trong render 
	virtual void GetBoundingBox(float &l, float &t, float &r, float &b);
};


class Background {
protected:
	int Stage;
	static Background * __instance;
public:
	static Background * GetInstance();
	static Background * GetInstance(int stage, int ID_Background, LPCWSTR Path_Background_Image, D3DCOLOR Color_Background, LPCWSTR Path_TXR_Background, int Screen_Width);
	Background(int Stage, int Id_Background, LPCWSTR Path_Background_Image, D3DCOLOR Color_Background, LPCWSTR Path_TXT_Background, int Screen_Width);

};