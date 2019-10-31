#include "stdafx.h"
#include "Graphics.h"
#include <string>


Graphics::Graphics(HINSTANCE hInst)
{
	std::wstring baseName = L"img\\texture_";
	for (int i = 0; i < BLOCK_COUNT; i++)
	{
		blockTextures[i] = (HBITMAP)LoadImage(hInst, (baseName + std::to_wstring(i) + L".bmp").c_str(), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
		if (!blockTextures[i])
		{
			throw std::exception(("Failed to load image \"texture_" + std::to_string(i) + "\"").c_str());
		}
	}
}

void Graphics::Draw(HDC hdc, Grid* grid, int score)
{
	DrawBackground(hdc);
	DrawScore(hdc, score);
	HDC hdcMem[BLOCK_COUNT];
	HGDIOBJ oldBitmap[BLOCK_COUNT];
	for (int i = 0; i < BLOCK_COUNT; i++)
	{
		hdcMem[i] = CreateCompatibleDC(hdc);
		oldBitmap[i] = SelectObject(hdcMem[i], blockTextures[i]);
	}
	for (int i = 0; i < TETRIS_WIDTH; i++)
	{
		for (int j = 0; j < TETRIS_HEIGHT; j++)
		{
			BitBlt(hdc, playZoneX + i*BLOCK_SIZE, playZoneY + j*BLOCK_SIZE, BLOCK_SIZE, BLOCK_SIZE, hdcMem[grid->grid[i][j]], 0, 0, SRCCOPY);
		}
	}
	for (int i = 0; i < BLOCK_COUNT; i++)
	{
		SelectObject(hdcMem[i], oldBitmap[i]);
		DeleteDC(hdcMem[i]);
	}
}

Graphics::~Graphics()
{
}

void Graphics::DrawBackground(HDC hdc)
{
	const int borderWidth = 20;
	HBRUSH hbrush = CreateSolidBrush(RGB(0, 0, 0));
	RECT rect;
	rect.left = playZoneX - borderWidth;
	rect.top = playZoneY;
	rect.right = playZoneX;
	rect.bottom = playZoneY + playZoneHeight;
	FillRect(hdc, &rect, hbrush); //fill left border

	rect.left = playZoneX + playZoneWidth;
	rect.top = playZoneY;
	rect.right = playZoneX + playZoneWidth + borderWidth;
	rect.bottom = playZoneY + playZoneHeight;
	FillRect(hdc, &rect, hbrush); //fill right border

	rect.left = playZoneX - borderWidth;
	rect.top = playZoneY - borderWidth;
	rect.right = playZoneX + playZoneWidth + borderWidth;
	rect.bottom = playZoneY;
	FillRect(hdc, &rect, hbrush); //fill top border

	rect.left = playZoneX - borderWidth;
	rect.top = playZoneY + playZoneHeight;
	rect.right = playZoneX + playZoneWidth + borderWidth;
	rect.bottom = playZoneY + playZoneHeight + borderWidth;
	FillRect(hdc, &rect, hbrush); //fill bottom border
}

void Graphics::DrawScore(HDC hdc, int score)
{
	RECT rect;
	rect.left = 650;
	rect.top = 300;
	rect.bottom = 400;
	rect.right = 850;
	auto scoreStr = "Score: " + std::to_string(score);
	DrawTextA(hdc, scoreStr.c_str(), scoreStr.length(), &rect, DT_WORDBREAK | DT_WORD_ELLIPSIS);
}
