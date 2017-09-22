#include "iostream"
using namespace std;

//类的开发和设计，出现了两个模型
//1 贫血模型
//2 充血模型

//货物类
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

//业务操作函数 通过全局函数实现
void purchase(Goods * &pHead, Goods * &pCur, int w)
{
	Goods *p = new Goods(w); //用new 在堆中创建。
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

//业务操作函数
void sale(Goods * &pHead, Goods * &pCur)
{
	if (pHead == NULL) 
	{ 
		cout << "No any goods!" << endl;  
		return; 
	}

	Goods *q = pHead;  
	pHead = pHead->next;  
	delete q;				//从堆上删除。
	cout << "saled." << endl;
}

void main()
{
	Goods * pHead = NULL /*头*/, *pCur = NULL;
	int  w;  int  choice;

	do
	{
		cout << "Please choice: " << endl;
		cout << "Key in 1 is purchase;" << endl;
		cout << "Key in 2 is sale;" << endl;
		cout << "Key in 0 is over." << endl;
		cin >> choice;

		switch (choice)		// 操作选择
		{
			case 1:                                               // 键入1，购进1箱货物
			{  
				cout << "Input weight: ";
				cin >> w;
				purchase(pHead, pCur, w);          // 从表尾插入1个结点
				break;
			}
			case 2: 		            // 键入2，售出1箱货物
			{ 
				sale(pHead, pCur);    // 从表头删除1个结点
				break; 
			}       
			case 0:  break; 		            // 键入0，结束
		}

		cout << "Now total weight is: " << Goods::TotalWeight() << endl;

	} while (choice);
}



