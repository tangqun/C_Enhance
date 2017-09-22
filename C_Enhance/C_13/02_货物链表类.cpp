#include "iostream"
using namespace std;

//��Ŀ�������ƣ�����������ģ��
//1 ƶѪģ��
//2 ��Ѫģ��

//������
class Goods
{
public:
	Goods(int  w) { weight = w;  total_weight += w; }
	~Goods() { total_weight -= weight; }
	int  Weight() { return  weight; };
	static  int  TotalWeight() { return  total_weight; }
	Goods *next;
private:
	int  weight;
	static  int  total_weight;
};

int  Goods::total_weight = 0;

//ҵ��������� ͨ��ȫ�ֺ���ʵ��
void purchase(Goods * &pHead, Goods * &pCur, int w)
{
	Goods *p = new Goods(w); //��new �ڶ��д�����
	p->next = NULL;
	if (pHead == NULL)
	{
		pHead = pCur = p;
	}
	else 
	{ 
		pCur->next = p;
		pCur = pCur->next; 
	}
}

//ҵ���������
void sale(Goods * &pHead, Goods * &pCur)
{
	if (pHead == NULL) 
	{ 
		cout << "No any goods!" << endl;  
		return; 
	}

	Goods *q = pHead;  
	pHead = pHead->next;  
	delete q;				//�Ӷ���ɾ����
	cout << "saled." << endl;
}

void main()
{
	Goods * pHead = NULL /*ͷ*/, *pCur = NULL;
	int  w;  int  choice;

	do
	{
		cout << "Please choice: " << endl;
		cout << "Key in 1 is purchase;" << endl;
		cout << "Key in 2 is sale;" << endl;
		cout << "Key in 0 is over." << endl;
		cin >> choice;

		switch (choice)		// ����ѡ��
		{
			case 1:                                               // ����1������1�����
			{  
				cout << "Input weight: ";
				cin >> w;
				purchase(pHead, pCur, w);          // �ӱ�β����1�����
				break;
			}
			case 2: 		            // ����2���۳�1�����
			{ 
				sale(pHead, pCur);    // �ӱ�ͷɾ��1�����
				break; 
			}       
			case 0:  break; 		            // ����0������
		}

		cout << "Now total weight is: " << Goods::TotalWeight() << endl;

	} while (choice);
}



