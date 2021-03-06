﻿#pragma once
#include <Windows.h>
#include <d3d9.h>
#include <d3dx9.h>

#define DIRECTINPUT_VERSION 0x0800
#include <dinput.h>

#define KEYBOARD_BUFFER_SIZE 1024
/*
class to define keyboard event handlers
*/
class CKeyEventHandler
{
public:
	virtual void KeyState(BYTE *state) = 0;
	virtual void OnKeyDown(int KeyCode) = 0;
	virtual void OnKeyUp(int KeyCode) = 0;
};

typedef CKeyEventHandler * LPKEYEVENTHANDLER;

class CGame
{
	static CGame * __instance;					// tạo ra một lớp, đảm bảo là một đối tượng duy nhất được chạy trong lớp này
	HWND hWnd;									// Window handle: mã số của cửa sổ

	LPDIRECT3D9 d3d = NULL;						// Direct3D handle: con trỏ đến thư viện
	LPDIRECT3DDEVICE9 d3ddv = NULL;				// Direct3D device object: con trỏ đến thư viện để vẽ

	LPDIRECT3DSURFACE9 backBuffer = NULL;		// trỏ đến backbuffer
	LPD3DXSPRITE spriteHandler = NULL;			// Sprite helper library to help us draw 2D image on the screen 

	LPDIRECTINPUT8       di;		// The DirectInput object         
	LPDIRECTINPUTDEVICE8 didv;		// The keyboard device 

	BYTE  keyStates[256];			// DirectInput keyboard state buffer , danh sach nhung ban phim
	DIDEVICEOBJECTDATA keyEvents[KEYBOARD_BUFFER_SIZE];		// Buffered keyboard data , 

	LPKEYEVENTHANDLER keyHandler;//gom cac phuong thuc ảo, de truyen đói tượng vào game của mình

public:
	void InitKeyboard(LPKEYEVENTHANDLER handler);
	void Init(HWND hWnd);			//
	void Draw(float x, float y, LPDIRECT3DTEXTURE9 texture, int left, int top, int right, int bottom, int alpha = 255);

	int IsKeyDown(int KeyCode);
	void ProcessKeyboard();

	static void SweptAABB(
		float ml,			// move left 
		float mt,			// move top
		float mr,			// move right 
		float mb,			// move bottom
		float dx,			// quãng đương đi dktrong thoi gian dt
		float dy,			// 
		float sl,			// static left
		float st, 
		float sr, 
		float sb,
		float &t, 
		float &nx,  // là vector phuong
		float &ny);

	LPDIRECT3DDEVICE9 GetDirect3DDevice() { return this->d3ddv; }
	LPDIRECT3DSURFACE9 GetBackBuffer() { return backBuffer; }
	LPD3DXSPRITE GetSpriteHandler() { return this->spriteHandler; }

	static CGame * GetInstance();	//muốn truy cập đến các hàm trong lớp game thì cần hàm này, 

	~CGame();
};


