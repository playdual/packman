#pragma once
#include"gameNode.h"
#include"scene1.h"
#include"loadingTest.h"
class mainGame :  public gameNode
{
private:
	
public:
	mainGame();
	~mainGame();

	virtual HRESULT init();	//�ʱ�ȭ
	virtual void release();//����
	virtual void update();//�����ϴ°�
	virtual void render(/*HDC hdc*/);//�׸��°�

	
};

