#include "BoardForm.h"

BoardForm::BoardForm()
{
	form[0][0] = 0; form[0][1] = 1; form[0][2] = 1; form[0][3] = 0;
	form[1][0] = 1; form[1][1] = 1; form[1][2] = 1; form[1][3] = 1;
	form[2][0] = 0; form[2][1] = 1; form[2][2] = 1; form[2][3] = 0;
	form[3][0] = 0; form[3][1] = 1; form[3][2] = 1; form[3][3] = 0;
}

void BoardForm::SetPosition(float x1, float y1, float xBoardStart,float yBoardStart, int bsize)
{
	position.x = x1;
	position.y = y1;

	for (int y = 0; y < 4; y++)
		for (int x = 0; x < 4; x++)
		{
			sprite[y][x].setPosition(xBoardStart + (x+x1) * bsize, yBoardStart + (y+y1) * bsize);
		}
}
