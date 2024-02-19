#include <Windows.h>
#include <iostream>
#include "Drawer.h"

using namespace std;

void Drawer::CordXY(int x, int y)
{
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);

	COORD position{ };
	position.X = x;
	position.Y = y;

	SetConsoleCursorPosition(console, position);
}

void Drawer::DesignFirst(int x, int y, int z, int g)
{
	int a, b, c, d;
	a = x;
	b = y;
	c = z, d = g;
	// We draw FRAME for the bar
	for(int i = x; i < y; i++)
	{
		CordXY(i, z);
		cout << char(205); // 2 horizontal lines
		CordXY(i, g);
		cout << char(205);
	}
	for(int i = z + 1; i < g; i++) // 2 vertical lines
	{
		CordXY(a, i);
		cout << char(186);
		CordXY(b, i);
		cout << char(186);
	}
	CordXY(a, z); // top left
	cout << char(201);
	CordXY(b, z); // top right
	cout << char(187);
	CordXY(a, g); // bottom left
	cout << char(200);
	CordXY(b, g); // bottom right
	cout << char(188);
}

void Drawer::Line(int col)
{
	for(int i = 1; i <= col; i++)
	{
		if(i == 1 || i == col)
		{
			cout << "+";
		}
		else
		{
			cout << "-";
		}
	}
}