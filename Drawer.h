#pragma once

#include <Windows.h>
#include <iostream>

using namespace std;

class Drawer
{
public:
	void CordXY(int x, int y);
	void DesignFirst(int x, int y, int z, int g);
	void Line(int col);
};