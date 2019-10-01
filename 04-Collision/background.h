#pragma once
#include "GameObject.h"
#include "Textures.h" 
#include <fstream>
#include <Windows.h>
#include <d3dx9.h>
#include <vector>

#include "debug.h"
#include "Sprites.h"
#include "Textures.h"
#include "GameObject.h"
#include "Brick.h"
#include "Cam.h"
#include <iostream>

#define Background_BBOX_WIDTH  770//16
#define Background_BBOX_HEIGHT 185//16 chi bao ngoai cua vao cham

//class CBackground : public CGameObject
//{
//public:
//	virtual void Render(float &xcamera, float &ycamera); //them x y trong render 
//	virtual void GetBoundingBox(float &l, float &t, float &r, float &b);
//};

/////////////


class Door {
public:
	int x, y, id;
	int MapNext, x_next, y_next;
};

class Background {
protected:
	int giaidoan;
	int chieudai_con;
	int chieudai_map;
	int width_b, height_b;
	int **fileread;
	float bientam_1, bientam_2;

	vector<Door> door;
	bool NextMap;
	
	int MapNext;
	int NewXSimon, NewYSimon;
	static Background * __instance;
	Cam *cam;
public:
	static Background * GetInstance();
	static Background * GetInstance(int giaidoan, int ID_Background, LPCWSTR Path_Background_Image, D3DCOLOR Color_Background, LPCWSTR Path_TXT_Background, int chieudai_con);
	Background(int giaidoan, int Id_Background, LPCWSTR Path_Background_Image, D3DCOLOR Color_Background, LPCWSTR Path_TXT_Background, int chieudai_con);

	void set_chieudai(int chieudaicon, int chieudaimap) {
		this->chieudai_con = chieudaicon;
		this->chieudai_map = chieudaimap;
	}
	int getchieudaimap() {
		return chieudai_map;
	}
	int getchieudaicon() {
		return chieudai_con;
	}
	void setgiaidoan(int gd) {
		this->giaidoan = gd; 
	}
	int getgiaidoan() {
		return giaidoan;
	}
	void Render(float x_cam);
	//void Update(float x_simon, float y_simon, vector<LPGAMEOBJECT>* Brick, float x_cam);
};

