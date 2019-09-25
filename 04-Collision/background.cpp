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


Background * Background::GetInstance() {
	return __instance;
}
Background * Background::GetInstance(int Stage, int Id_Background, LPCWSTR Path_Background_Image, D3DCOLOR Color_Background, LPCWSTR Path_TXT_Background, int Screen_Width ) {
	__instance = new Background( Stage,  Id_Background,  Path_Background_Image,  Color_Background,  Path_TXT_Background, Screen_Width);
	return __instance;
}
Background::Background(int Stage, int Id_Background, LPCWSTR Path_Background_Image, D3DCOLOR Color_Background, LPCWSTR Path_TXT_Background, int Screen_Width) {
	this->Stage = Stage;
	CTextures * textures = CTextures::GetInstance();
	CSprites * sprites = CSprites::GetInstance();
	textures->Add(Id_Background, Path_Background_Image, Color_Background);//add background
	LPDIRECT3DTEXTURE9 texbackground = textures->Get(Id_Background);//add background
	switch (Stage)
	{
	case 1:

		break;
	default:
		break;
	}
}