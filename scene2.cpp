#include "stdafx.h"
#include "scene2.h"
scene2::scene2()
{
}

scene2::~scene2()
{
}

HRESULT scene2::init()
{
	IMAGEMANAGER->addImage("�糪", "images/�糪.bmp", WINSIZEX, WINSIZEY, true, RGB(255, 0, 255));

	return S_OK;
}
void scene2::release()
{
}

void scene2::update()
{
	if (KEYMANAGER->isOnceKeyDown('1'))
	{
		//��ü����
		SCENEMANAGER->changeScene("scene1");
	}
}

void scene2::render()
{
	IMAGEMANAGER->render("�糪", getMemDC());
}
