#include<iostream>

using namespace std;

/*
多态成立的 3 个条件
1、要有继承
2、要有函数重写 C virtual 虚函数
3、要有父类指针（父类引用）指向子类对象
*/
class HeroFighter
{
public:
	HeroFighter()
	{

	};
	~HeroFighter()
	{

	};

	virtual int power()
	{
		return 10;
	}

private:

};

class AdvHeroFighter : public HeroFighter
{
public:
	AdvHeroFighter()
	{

	};
	~AdvHeroFighter()
	{

	};

	int power()
	{
		return 20;
	}

private:

};

class EnemyFighter
{
public:
	EnemyFighter()
	{

	};
	~EnemyFighter()
	{

	};

	int power()
	{
		return 15;
	}

private:

};

void play(HeroFighter *pHF, EnemyFighter *pEF)
{
	if (pHF->power() > pEF->power())
	{
		cout << "英雄赢了" << endl;
	}
	else
	{
		cout << "敌人赢了" << endl;
	}
}

void main06()
{
	HeroFighter hf;
	AdvHeroFighter ahf;
	EnemyFighter ef;

	play(&hf, &ef);
	play(&ahf, &ef);

	system("pause");
}