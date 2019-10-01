#include "background.h"



//void CBackground::Render(float &xcamera, float &ycamera)
//{
//	animations[0]->Render(x - xcamera, y - ycamera);
//	//RenderBoundingBox();
//}
//
//void CBackground::GetBoundingBox(float &l, float &t, float &r, float &b)
//{
//	l = x;
//	t = y;
//	r = x + Background_BBOX_WIDTH;
//	b = y + Background_BBOX_HEIGHT;
//
//} 
///////////// neww



////////////
Background * Background::__instance = NULL;
Background * Background::GetInstance() {
	return __instance;
}
Background * Background::GetInstance(int giaidoan, int Id_Background, LPCWSTR Path_Background_Image, D3DCOLOR Color_Background, LPCWSTR Path_TXT_Background, int Screen_Width ) {
	__instance = new Background(giaidoan,  Id_Background,  Path_Background_Image,  Color_Background,  Path_TXT_Background, Screen_Width);
	return __instance;
}
Background::Background(int giaidoan, int Id_Background, LPCWSTR Path_Background_Image, D3DCOLOR Color_Background, LPCWSTR Path_TXT_Background, int Screen_Width) {
	this->giaidoan = giaidoan;
	CTextures * textures = CTextures::GetInstance();
	CSprites * sprites = CSprites::GetInstance();
	textures->Add(Id_Background, Path_Background_Image, Color_Background);//add background
	LPDIRECT3DTEXTURE9 texbackground = textures->Get(Id_Background);//add background
	switch (giaidoan)
	{
	case 0:
		break;
	case 1:
		textures->Add(Id_Background, Path_Background_Image, Color_Background);//add background
		for (int i = 0; i < 51; i++)
			sprites->Add(21000 + i, i * 16, 0, (i + 1) * 16, 16, texbackground);
		set_chieudai(864, chieudai_con);
		break;
	default:
		break;
	}
	// 
	if (giaidoan != 0) {
		ifstream filein;
		filein.open(Path_TXT_Background);
		filein >> width_b >> height_b;
		fileread = new int*[height_b];
		for (int i = 0; i < height_b; i++) {
			fileread[i] = new int[width_b];
		}
		for (int i = 0; i < height_b; i++)
		{
			for (int j = 0; j < width_b; j++)
			{
				filein >> fileread[i][j];
			}
		}

		////

		ifstream infile;
		infile.open(Path_TXT_Background);
		infile >> width_b >> height_b;
		fileread = new int*[height_b];
		for (int i = 0; i < height_b; i++) {
			fileread[i] = new int[width_b];
		}
		for (int i = 0; i < height_b; i++)
		{
			for (int j = 0; j < width_b; j++)
			{
				infile >> fileread[i][j];
			}
		}
		int soluongCong;
		infile >> soluongCong;
		for (int i = 0; i < soluongCong; i++) {
			Door doortemp;
			infile >> doortemp.id;
			infile >> doortemp.x;
			infile >> doortemp.y;
			infile >> doortemp.MapNext;
			infile >> doortemp.x_next;
			infile >> doortemp.y_next;
			door.push_back(doortemp);
		}

		infile.close();
		////
	}


}


void Background::Render(float x_cam) 
{
	CSprites * sprites = CSprites::GetInstance();
	int jj, ii;
	bientam_1 = chieudai_con / 2;
	for (int i = 0; i < height_b; i++)
	{
		ii = i * 16 + 55;
		for (int j = x_cam / 16 - 12; j < x_cam / 16 + 5; j++)
		{
			{
				jj = -x_cam + j * 16 + bientam_1;
				if (jj > -16 && jj < chieudai_con)
				{
					sprites->Get(21000 + fileread[i][j])->Draw(jj, ii);
				}
			}
		}
	}
}