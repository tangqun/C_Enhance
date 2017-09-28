#include<iostream>

using namespace std;

/*
��̬������ 3 ������
1��Ҫ�м̳�
2��Ҫ�к�����д C virtual �麯��
3��Ҫ�и���ָ�루�������ã�ָ���������
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
		cout << "Ӣ��Ӯ��" << endl;
	}
	else
	{
		cout << "����Ӯ��" << endl;
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