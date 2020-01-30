#pragma once
#include"gameNode.h"
#include"bullet.h"
#include"progressBar.h"
#define PLAYERSPEED 5


//���� :  ��������� ���� ������ ������ �ӵ��� ���ϵȴ�.
/*
	class A�� a.h�ְ� class B�� b.h�� �ִµ�
	B�� A�� ����ϰ� A�� B�� ����� ��� :���谡 �߸��Ǿ��ٰ� ���� �ִ�.
	����ڷ� �ϸ� �����ϱ⵵ ����� ������ �����.

	���̴� ���� �����͸� �˱����ؼ� ���� ������ �˾ƾ��ϰ� �� �� ����� ��Ŭ��� �ؾ��Ѵ�.
	������ �񿡼� �̹� ���̶�� ����� ��Ŭ��带 �ϰ� �ֱ⿡ ���̿��� ���� ����� ��Ŭ��� �ϸ� ��ȣ ���� ������ �ȴ�.
	������ �ٲ��� ������ ��Ŭ��� �Ҽ� ����.
	���̿��� �� ��Ŭ��� �Ѵٰ� �Ҷ� ���� �� ����� �����Ǹ� ��Ŭ��� �κе� 
	�̿����� �ޱ� ������ ������ ���������� ������ �ӵ��� ���ϵȴ�.
	�̰��� �ذ��ϱ� ���� ����� ���漱���̴�.
	(���� :  �����Ϸ��� ������Ͽ� ������ ���ܵ� �����ϴ� ������Ͽ����� ���������� �̷�� ���� �ʴ´�.)
	�� ���� �ؾ� ���� :  ���漱���� ��� �� Ŭ���� ���� ��ü�� ������������ �����ؾ� �Ѵ�.
	���� ���������� �ƴ� ��ü�� ������ ��� ���漱���� Ư¡�� �� ��ü�� ũ�⸦ ��Ȯ�� �ľ��Ͽ� �Ҵ��� �����ֱ�
	�����̴�.(�ش� Ŭ������ �ִٴ� ������ ����� �𸥴�.)
*/

//��ȣ������ �� �Ŵ��� Ŭ���� ���漱��
class enemyManager;
class rocket :public gameNode
{
private:

	image * _player;
	missile* _missile;
	nuclear* _nuclear;
	RECT rc;

	//���α׷����� 
	progressBar* _hpBar;
	float _maxHP;
	float _currentHP;


	enemyManager* _em;		//�� �Ŵ��� Ŭ���� ����

public:
	rocket();
	~rocket();

	HRESULT init();
	void release();
	void update();
	void render();

	//�̽� ����
	void removeMissile(int arrNum);
	//�浹�Լ�
	void collision();
	//�Ǳ�� �Լ�
	void hitDamage(float damage);

	//��Ŭ���� ��������
	nuclear* getMissile() { return _nuclear; }
	//���� �̹��� ��������
	image* getRocketImage() { return _player; }

	void setEnemyMemoryLink(enemyManager* em) { _em = em; }
};

