#pragma once
#include"gameNode.h"
#define num 3
class scene1 : public gameNode
{
private:
	image* _packmanbase;
	image* _packmanmove;

	image* _okbg;
	image* _bg;

	image* _enemy[num];

	RECT packman;
	RECT enemy[num];

	bool isBase;

	bool isLeft;
	bool isRight;
	bool isUp;
	bool isDown;

	int moveindex;
	int movecount;

	int grade;
	
	int enemyarrow;


public:
	scene1();
	~scene1();

	HRESULT init();
	void release();
	void update();
	void render();
};

