#include "stdafx.h"
#include "scene1.h"


scene1::scene1()
{
}


scene1::~scene1()
{
}

HRESULT scene1::init()
{
	enemyarrow = 0;
	isBase = true;
	isLeft = false;
	isRight = false;
	isUp = false;
	isDown = false;

	grade = 0;
	_bg=IMAGEMANAGER->addImage("배경", "images/map_2.bmp", WINSIZEX, WINSIZEY,true, RGB(255,0,255));
	_okbg = IMAGEMANAGER->addImage("검사배경", "images/map_ok.bmp", WINSIZEX, WINSIZEY,true,RGB(255,0,255));


	packman = RectMakeCenter(WINSIZEX / 2, WINSIZEY / 2+50, 40, 40);

	_packmanbase=IMAGEMANAGER->addFrameImage("팩맨기본", "images/packmanbase.bmp", 40, 40, 1, 1, true, RGB(255, 0, 255));
	_packmanmove=IMAGEMANAGER->addFrameImage("팩맨이동", "images/packmanmove.bmp", 63, 140, 2, 4, true, RGB(255, 0, 255));

	_enemy[0] = IMAGEMANAGER->addFrameImage("적1", "images/적1.bmp", 84, 160, 2, 4, true, RGB(0, 0, 0));
	enemy[0] = RectMakeCenter(WINSIZEX / 2, WINSIZEY / 2 - 100, 40, 40);

	return S_OK;
}

void scene1::release()
{
}

void scene1::update()
{


	for (int i = packman.left + (packman.right - packman.left) / 2 - 5; i < packman.left + (packman.right - packman.left) / 2 + 5; i++)
	{
		for (int j = packman.top + (packman.bottom - packman.top) / 2 - 5; j < packman.top + (packman.bottom - packman.top) / 2 + 5; j++)

		{
			COLORREF colorgrade = GetPixel(_bg->getMemDC(), i, j);
			if (colorgrade == RGB(255, 183, 174))
			{
				HBRUSH MyBrush, OldBrush;
				MyBrush = CreateSolidBrush(RGB(0, 0, 0));
				OldBrush = (HBRUSH)SelectObject(_bg->getMemDC(), MyBrush);
				SelectObject(_bg->getMemDC(), MyBrush);
				SelectObject(_bg->getMemDC(), GetStockObject(NULL_PEN));
				EllipseMakeCenter(_bg->getMemDC(), packman.left + (packman.right - packman.left) / 2, packman.top + (packman.bottom - packman.top) / 2, 40, 40);
				DeleteObject(SelectObject(_bg->getMemDC(), OldBrush));
				grade += 1;
			}
		}
	}

	//충돌검사
	//아래검사
	for (int i = packman.bottom - 1; i < packman.bottom + 1; i++)
	{
		COLORREF colorMovebot = GetPixel(_okbg->getMemDC(), packman.left + (packman.right - packman.left) / 2, i);

		if (!(colorMovebot == RGB(255, 0, 255)))
		{
			packman.top = i - (packman.bottom - packman.top);
			packman.bottom = i;
		}
	}
	//위검사
	for (int i = packman.top + 1; i > packman.top - 1; i--)
	{
		COLORREF colorMovetop = GetPixel(_okbg->getMemDC(), packman.left + (packman.right - packman.left) / 2, i);

		if (!(colorMovetop == RGB(255, 0, 255)))
		{
			packman.bottom = i + (packman.bottom - packman.top);
			packman.top = i;
		}
	}
	//오른쪽검사
	for (int i = packman.right - 1; i < packman.right + 1; i++)
	{
		COLORREF colorMoverig = GetPixel(_okbg->getMemDC(), i, packman.top + (packman.bottom - packman.top) / 2);

		if (!(colorMoverig == RGB(255, 0, 255)))
		{
			packman.left = i - (packman.right - packman.left);
			packman.right = i;
		}
	}
	//왼쪽검사
	for (int i = packman.left + 1; i > packman.left - 1; i--)
	{
		COLORREF colorMovelef = GetPixel(_okbg->getMemDC(), i, packman.top + (packman.bottom - packman.top) / 2);

		if (!(colorMovelef == RGB(255, 0, 255)))
		{
			packman.right = i + (packman.right - packman.left);
			packman.left = i;
		}
	}



	//적 충돌검사
	for (int k = 0; k <= num; k++)
	{
		if (enemyarrow == 0)
		{
			enemy[0].left -= 1;
			enemy[0].right -= 1;
		}
		else if (enemyarrow == 1)
		{
			enemy[0].left += 1;
			enemy[0].right += 1;
		}
		else if (enemyarrow == 2)
		{
			enemy[0].top -= 1;
			enemy[0].bottom -= 1;
		}
		else if (enemyarrow == 3)
		{
			enemy[0].top += 1;
			enemy[0].bottom += 1;
		}
		//아래검사
		for (int i = enemy[0].bottom - 1; i < enemy[0].bottom + 1; i++)
		{
			COLORREF colorMoveeb = GetPixel(_okbg->getMemDC(), enemy[0].left + (enemy[0].right - enemy[0].left) / 2, i);

			if (!(colorMoveeb == RGB(255, 0, 255)))
			{

				enemy[0].top = i - (enemy[0].bottom - enemy[0].top);
				enemy[0].bottom = i;
				enemyarrow = 2;
			}
		}
		//위검사
		for (int i = enemy[0].top + 1; i > enemy[0].top - 1; i--)
		{
			COLORREF colorMoveet = GetPixel(_okbg->getMemDC(), enemy[0].left + (enemy[0].right - enemy[0].left) / 2, i);

			if (!(colorMoveet == RGB(255, 0, 255)))
			{
				enemy[0].bottom = i + (enemy[0].bottom - enemy[0].top);
				enemy[0].top = i;
				enemyarrow = 0;
			}
		}
		//오른쪽검사
		for (int i = enemy[0].right - 1; i < enemy[0].right + 1; i++)
		{
			COLORREF colorMoveer = GetPixel(_okbg->getMemDC(), i, enemy[0].top + (enemy[0].bottom - enemy[0].top) / 2);

			if (!(colorMoveer == RGB(255, 0, 255)))
			{
				enemy[0].left = i - (enemy[0].right - enemy[0].left);
				enemy[0].right = i;
				enemyarrow = 3;
			}
		}
		//왼쪽검사
		for (int i = enemy[0].left + 1; i > enemy[0].left - 1; i--)
		{
			COLORREF colorMoveel = GetPixel(_okbg->getMemDC(), i, enemy[0].top + (enemy[0].bottom - enemy[0].top) / 2);

			if (!(colorMoveel == RGB(255, 0, 255)))
			{
				enemy[0].right = i + (enemy[0].right - enemy[0].left);
				enemy[0].left = i;
				enemyarrow = 1;
			}
		}
	}
		/*}*/


		if (KEYMANAGER->isStayKeyDown(VK_LEFT))
		{
			isBase = false;
			isLeft = true;
			isRight = false;
			isUp = false;
			isDown = false;
			packman.left -= 1;
			packman.right -= 1;
		}
		if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
		{
			isBase = false;
			isLeft = false;
			isRight = true;
			isUp = false;
			isDown = false;
			packman.left += 1;
			packman.right += 1;
		}
		if (KEYMANAGER->isStayKeyDown(VK_UP))
		{
			isBase = false;
			isLeft = false;
			isRight = false;
			isUp = true;
			isDown = false;
			packman.top -= 1;
			packman.bottom -= 1;
		}
		if (KEYMANAGER->isStayKeyDown(VK_DOWN))
		{
			isBase = false;
			isLeft = false;
			isRight = false;
			isUp = false;
			isDown = true;
			packman.top += 1;
			packman.bottom += 1;
		}

		if (isRight)
		{
			movecount++;
			_packmanmove->setFrameY(0);
			if (movecount % 5 == 0)
			{
				movecount = 0;
				moveindex--;

				if (moveindex < 0)
				{
					moveindex = 2;
				}
				_packmanmove->setFrameX(moveindex);
			}
		}
		if (isLeft)
		{
			movecount++;
			_packmanmove->setFrameY(1);
			if (movecount % 5 == 0)
			{
				movecount = 0;
				moveindex--;
				if (moveindex < 0)
				{
					moveindex = 2;
				}
				_packmanmove->setFrameX(moveindex);
			}
		}

		if (isUp)
		{
			movecount++;
			_packmanmove->setFrameY(2);
			if (movecount % 5 == 0)
			{
				movecount = 0;
				moveindex--;
				if (moveindex < 0)
				{
					moveindex = 2;
				}
				_packmanmove->setFrameX(moveindex);
			}
		}
		if (isDown)
		{
			movecount++;
			_packmanmove->setFrameY(3);
			if (movecount % 5 == 0)
			{
				movecount = 0;
				moveindex--;
				if (moveindex < 0)
				{
					moveindex = 2;
				}
				_packmanmove->setFrameX(moveindex);
			}
		}
	
}

void scene1::render()
{
	IMAGEMANAGER->render("배경", getMemDC());
	//IMAGEMANAGER->render("검사배경", getMemDC());


	if (isBase) //기본
	{
	_packmanbase->frameRender(getMemDC(), packman.left, packman.top);
	}
	else if(!isBase)
	{
	_packmanmove->frameRender(getMemDC(), packman.left, packman.top);
	}

	Rectangle(getMemDC(), enemy[0].left, enemy[0].top, enemy[0].right, enemy[0].bottom);
	_enemy[0]->frameRender(getMemDC(), enemy[0].left, enemy[0].top);

	//Rectangle(getMemDC(), packman.left, packman.top, packman.right, packman.bottom);
}
