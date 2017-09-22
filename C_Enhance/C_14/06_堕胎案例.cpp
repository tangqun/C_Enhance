#include<iostream>

using namespace std;

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
		cout << "Ó¢ÐÛÓ®ÁË" << endl;
	}
	else
	{
		cout << "µÐÈËÓ®ÁË" << endl;
	}
}

void main()
{
	HeroFighter hf;
	AdvHeroFighter ahf;
	EnemyFighter ef;

	play(&hf, &ef);
	play(&ahf, &ef);

	system("pause");
}