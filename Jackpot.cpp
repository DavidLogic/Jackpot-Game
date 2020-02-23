#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include "resource.h"

using namespace std;

//Issues：实现输入数字时倒计时功能
long i, j, life, maxrand;   
long c;
short backtime;
int t = 0;

void Start();         
void GetResults();
void couttime();



int main() {
	
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY |FOREGROUND_RED | FOREGROUND_GREEN);
	cout << "                                         " << "** ！！！Jackpot！！！ **"<<endl;
	cout << "                                                        " << "作者："<<"David Logic"<<"     "<<"更新时间:2020/1/25"<<"  "<<"版本：v1.5.4"<<endl<<endl;
	cout << "                                                        " << "项目主页：https://github.com/DavidLogic/Jackpot-Game" << endl;
	cout << "                        " << "使命：我们的使命是猜测一个数字。"<<endl	;
	cout << "                              " << "当然，我会告诉你";
	cout << "与要猜测的数字相距大小。"<<endl<<endl;
	cout << "                        " << "准备好了吗？"<<endl;
	cout << "                        " << "           I see your smile！"<<endl;
	cout << "                        " << "                            Let's win the Jackpot！"<<endl;
	Start();
	return 0;
}




void Start() {
	i = 0;
	j = 0;
	life = 0;
	maxrand = 6;
	cout << endl << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY |FOREGROUND_RED);
	cout << "       " << "选择一个困难级别:" << endl;
	cout << "       " << "1 : 学徒 (0-15)   （生命上限=3）" << endl;
	cout << "       " << "2 : 战士 (0-30)   （生命上限=3）"<<endl;
	cout << "       " << "3 : 将军 (0-50)   （生命上限=5）"<<endl;
	cout << "       " << "4 : 战神（0-300） （生命上限=7）"<<endl;
	cout << "       " << "5 : 欧皇（0-1000）（生命上限=10)"<<endl;
	cout << "       " << "6 : 探索者(自定义难度)" << endl;
	cout << "       " << "7 : 离开游戏"<<endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY |FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	c = 30;
	cout << endl;

	cout << "        " << "请输入您的选择:";
	cin >> c;                   
	cout <<endl;

	switch (c) {
	case 1:
		maxrand = 15; life = 3; backtime = 10;
		break;
	case 2:
		maxrand = 30; life = 3; backtime = 10;
		break;
	case 3:
		maxrand = 50; life = 5; backtime = 15;
		break;
	case 4:
		maxrand = 300; life = 7; backtime = 7;
		break;
	case 5:
		maxrand = 1000;	life = 10; backtime = 5;
		break;
	case 6:
		cout << "探索者模式:" << endl;
	num:cout << "请输入" << " ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY |
			FOREGROUND_BLUE);
		cout<< "数字的最大上限(范围：不能为小于等于一的数）：";
		cin  >> maxrand;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY |
			FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		if(maxrand>1)

		cout << ":)设置完成！";
		else
		{
			cout << "数字的最大上限非法，请重新设置！（范围：不能为小于等于一的数）" << endl;
			cout << endl;
			goto num;
		}
	lable: cout << "请输入"; 
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
		cout<< "生命上限（范围：0到您输入的数字之间）：";
		cin  >> life;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED |FOREGROUND_GREEN | FOREGROUND_BLUE);
		if(life<maxrand&&life>0)
		cout << ":)设置完成！开始游戏...";
		else
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
			cout << "生命上限非法，请重新设置！（范围：0到您输入的数字之间）"<<endl;
			cout << endl;
			goto lable;
		}
		break;

	default:
		cout << "已退出游戏 :( ,bye~~~";
		exit(0);
		break;
	}
		

	cout << "游戏开始！！！" << endl;
	srand((unsigned)time(NULL)); 
	j = rand() % maxrand;               

	GetResults();
}
void GetResults() {
	if (life <= 0) { 
		cout << " X_X 遗憾，头奖擦肩而过 /(ㄒoㄒ)/~~  "<<endl<<endl;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN);
			cout << "揭秘最终答案:" << j << endl;
		Start();
	}
	
	cout << "请输入一个数字: ";
	//
	cin >> i;
	//couttime();
	cout << t << endl;

	if ((i > maxrand) || (i < 0)) 
	{ 
		cout << "错误: 数字不在 0 和 " << maxrand << "之间" << " " << endl;
		GetResults();
	}

	if (i == j) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY |FOREGROUND_RED | FOREGROUND_GREEN);
		cout << "^0^ 恭喜，你赢得了头奖！\n\n"; 
		while (maxrand>=500)   //NEED  TO FIX THE Rule!
		{

			cout << "天选之人，请收下作者的膝盖！";
		
			if (maxrand >= 500 && maxrand < 1000)
				maxrand--;    //isn't a good rule!
			else if (maxrand >= 1000)
			{
				maxrand %= 10;
			}
		}
		
		exit(0);
	}
	else if (i > j) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_BLUE);
		cout << "太大了\n";
		life = life - 1;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
		cout << "您的剩余生命: " << life << "\n\n";
		GetResults();
	}
	else if (i < j) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN);
		cout << "太小了\n";
		life = life - 1;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
		cout << "您的剩余生命: " << life << "\n\n";
		GetResults();
	}
}
/*void couttime()
{
	
	while (t < backtime)
	{
		Sleep(1000);
		t++;
	}
	cout<<"输入超时！"<<endl;
	life--;
}
*/