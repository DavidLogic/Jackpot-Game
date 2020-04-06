#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include "resource.h"
#include "Class.h"
//#include <string>

using namespace std;
class overflow {};
class underflow {};

//Issues：实现输入数字时倒计时功能
long i, j, life, maxrand;   
long c;
short backtime;
int t = 0;
char* input;
string  draw_love;

void Start();         
void GetResults();
void draw(string str);



int main() {
	
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY |FOREGROUND_RED | FOREGROUND_GREEN);//调整文字颜色
	cout << "                                         " << "** ！！！Jackpot！！！ **"<<endl;
	cout << "                                                        " << "作者："<<"David Logic"<<"     "<<"更新时间:2020/3/27"<<"  "<<"版本：v1.5.6"<<endl<<endl;
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
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY |FOREGROUND_RED);//调整文字颜色
	cout << "       " << "选择一个困难级别:" << endl;
	cout << "       " << "1 : 学徒 (0-15)   （生命上限=3）" << endl;
	cout << "       " << "2 : 战士 (0-30)   （生命上限=3）"<<endl;
	cout << "       " << "3 : 将军 (0-50)   （生命上限=5）"<<endl;
	cout << "       " << "4 : 战神（0-300） （生命上限=7）"<<endl;
	cout << "       " << "5 : 欧皇（0-1000）（生命上限=10)"<<endl;
	cout << "       " << "6 : 探索者(自定义难度)" << endl;
	cout << "       " << "7 : 离开游戏"<<endl;
	cout << "       " << "8 : 彩蛋" << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY |FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);//调整文字颜色
	c = 30;
	cout << endl;

	cout << "        " << "请输入您的选择:";
	cin >> c;                   
	cout <<endl;

	switch (c)
	{
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
		try {
			cout << "探索者模式:" << endl;
		num:cout << "请输入" << " ";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_BLUE);//调整文字颜色
			cout << "数字的最大上限(范围：不能为小于等于一的数）：";
			cin >> maxrand;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);//调整文字颜色
			if (maxrand >= 10e8)
			{
				throw overflow();
			}
			if (maxrand <= 0)
			{
				throw underflow();

			}
			if (maxrand > 1)

				cout << ":)设置完成！";
			else
			{
				cout << "数字的最大上限非法，请重新设置！（范围：不能为小于等于一的数）" << endl;
				cout << endl;
				goto num;
			}
		lable: cout << "请输入";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);//调整文字颜色
			cout << "生命上限（范围：0到您输入的数字之间）：";
			cin >> life;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);//调整文字颜色
			if (life >= 10e8)
			{
				throw overflow();
			}
			if (life <= 0)
			{
				throw underflow();

			}
			if (life < maxrand && life>0)
				cout << ":)设置完成！开始游戏...";
			else
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);//调整文字颜色
				cout << "生命上限非法，请重新设置！（范围：0到您输入的数字之间）" << endl;
				cout << endl;
				goto lable;

			}
		}
		//	
		
		catch (overflow)//上溢
		{
			cout << "输入值过大，程序堆栈溢出，程序将在3秒后自动退出  X_X";
			cin >> input;
			if (input == "继续")
			{
				GetResults();

			}
			else
			{
				Sleep(1000 * 3);
				exit(1);
			}
		}
		catch (underflow)//下溢
		{
			cout << "输入值过小，程序堆栈溢出，程序将在3秒后自动退出  X_X";
			cin >> input;
			if (input == "继续")
			{
				GetResults();

			}
			else
			{
				Sleep(1000 * 3);
				exit(1);
			}
		}
		catch (...)
		{
			cout << "发生未知错误！程序将在3秒后自动退出  X_X";
			Sleep(1000 * 3);
			exit(1);

		}
	
		break;

	case 8:
		cout << "说些什么吧：" << endl;
		cin >> draw_love;
		cout << "系统绘制中..." << endl;
		Sleep(1000 * 6);
		draw(draw_love);
		Sleep(1000 * 3);
		Start();
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

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN);//调整文字颜色
			cout << "揭秘最终答案:" << j << endl;
		Start();
	}
	try
	{

	
	
	cout << "请输入一个数字: ";
	//
	cin >> i;
	if (i >= 10e8)
	{
		throw overflow();
	}
	if (i <= 0)
	{
		throw underflow();

	}
	//couttime();
	//cout << t << endl;

	if ((i > maxrand) || (i < 0)) 
	{ 
		cout << "错误: 数字不在 0 和 " << maxrand << "之间" << " " << endl;
		GetResults();
	}

	if (i == j)  //胜利
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY |FOREGROUND_RED | FOREGROUND_GREEN);//调整文字颜色
		cout << "^0^ 恭喜，你赢得了头奖！\n\n"; 
		Start();
		while (maxrand>=500)   //NEED  TO FIX THE Rule!
		{

			cout << "天选之人，请收下作者的膝盖！";
		
			if (maxrand >= 500 && maxrand < 1000)
				maxrand--;    //isn't a good rule!
			else if (maxrand >= 1000)
			{
				maxrand %= 10;
			}
		Start();
		}
		
		exit(0);
	}
	else if (i > j) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_BLUE);//调整文字颜色
		cout << "太大了\n";
		life = life - 1;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);//调整文字颜色
		cout << "您的剩余生命: " << life << "\n\n";
		GetResults();
	}
	else if (i < j) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN);//调整文字颜色
		cout << "太小了\n";
		life = life - 1;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);//调整文字颜色
		cout << "您的剩余生命: " << life << "\n\n";
		GetResults();
	}
	}
	catch (overflow)//上溢
	{
		cout << "输入值过大，程序堆栈溢出，程序将在3秒后自动退出  X_X";
		cin >> input;
		if (input == "继续")
		{
			GetResults();

		}
		else
		{
			Sleep(1000 * 3);
			exit(1);
		}
	}
	catch (underflow)//下溢
	{
		cout << "输入值过小，程序堆栈溢出，程序将在3秒后自动退出  X_X";
		cin>> input;
		if (input == "继续")
		{
			GetResults();
		
		}
		else
		{
			Sleep(1000 * 3);
			exit(1);
		}
	}
	catch (...)
	{
		cout << "发生未知错误！程序将在3秒后自动退出  X_X";
		Sleep(1000 * 3);
		exit(1);

	}
	
}
void draw(string str) 
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
	long temp = 0;
	long minus = 0;
	for (double y = 1.3; y >= -1.1; y -= 0.06) {
		for (double x = -1.1; x <= 1.1; x += 0.025) {
			if (x * x + pow(5.0 * y / 4.0 - sqrt(fabs(x)), 2) - 1 <= 0.0) {
				cout << str.at(temp);
				temp = (temp + 1) % str.length();
			}
			else {
				for (int i = temp; i >= 0; i--) {
					if (((int)str.at(i)) < 0)
						minus++;
					else break;
				}
				if ((minus == 0) || (minus % 2 == 1)) {
					cout << " ";
					minus = 0;
				}
				else {
					cout << str.at(temp);
					temp = (temp + 1) % str.length();
					minus = 0;
				}
			}
		}
		cout << endl;
	}
}

