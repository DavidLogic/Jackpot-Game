#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include "resource.h"
#include "Class.h"
#include <wininet.h>
#include <string>
#include <TlHelp32.h>
#include <Shlwapi.h>
#include <Psapi.h>
#include <CommCtrl.h>
#pragma comment(lib,"winmm.lib")
#pragma comment( lib, "wininet.lib" ) 


using namespace std;
class overflow {};
class underflow {};

//Issues：实现输入数字时倒计时功能
long i, j, life, maxrand;   
int c;
long f;
long e;
long a;

short N,Y;
int t = 0;
char* input;
char aci = 3;
string  draw_love;


void Start();         
void GetResults();
void _continue();
void draw(string str);
void _playsound();
void drawpic();
void randraw();
void _sleep();



int main() 
{
	system("mode con cols=200 lines=1000");
	_playsound();
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY |FOREGROUND_RED | FOREGROUND_GREEN);//调整文字颜色
	cout << "                                                      " << "J";
	_sleep();
	cout << "a";
	_sleep();
	cout << "c";
	_sleep();
	cout << "k";
	_sleep();
	cout << "p";
	_sleep();
	cout << "o";
	_sleep();
	cout<< "t" << endl;
	cout << "                                                        " << "作者：";
	_sleep();
	cout<< "David Logic" << "     " << "更新时间:2020/9/6" << "  " << "版本：v2.12" << endl << endl;
	cout << "                                                        " << "项目主页：https://github.com/DavidLogic/Jackpot" << endl;
	cout << "                        " << "规则：猜测一个数字，是的，这听起来很简单，但很考验你的欧气值。"<<endl	;
	cout << "                              " << "当然，无论是欧皇还是非酋我都会告诉你";
	cout << "与要猜测的数字相距大小哦。"<<endl<<endl;
	cout << "                        " << "准备好了吗？"<<endl;
	cout << "                        " << "           我已经看到你的微笑了哦！"<<endl;
	cout << "                        " << "                            Let's win the Jackpot！"<<endl;
	
	Start();
	return 0;
}




void Start() {
	i = 0;
	j = 0;
	life = 0;
	maxrand = 6;
	string ask;
	cout << endl << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY |FOREGROUND_RED);//调整文字颜色
	cout << "       " << "请选择一个操作:" << endl;
	Sleep(1000 * 10e-1);
	cout << "       " << "1 : 开始游戏：" << endl;
	Sleep(1000*10e-1);
	cout << "       " << "2 : 其他功能：" << endl;
	Sleep(1000 * 10e-1);
	cout << "       " << "3 : 离开游戏"<<endl;
	
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY |FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);//调整文字颜色
	c = 30;
	cout << endl;

	cout << "        " << "请输入您的选择:";
	cin >> f;                   
	cout <<endl;
	switch (f)
	{
		case 1:
			cout << "       " << "1 : 学徒 (0-15)   （生命上限=3）" << endl;
			Sleep(1000 * 10e-1);
			cout << "       " << "2 : 战士 (0-30)   （生命上限=3）" << endl;
			Sleep(1000 * 10e-1);
			cout << "       " << "3 : 将军 (0-50)   （生命上限=5）" << endl;
			Sleep(1000 * 10e-1);
			cout << "       " << "4 : 战神（0-300） （生命上限=7）" << endl;
			Sleep(1000 * 10e-1);
			cout << "       " << "5 : 欧皇（0-1000）（生命上限=10)" << endl;
			Sleep(1000 * 10e-1);
			cout << "       " << "6 : 探索者(自定义难度)" << endl;
			Sleep(1000 * 10e-1);
			cout << "       " << "7 : 生死局 ：D" << endl;
			Sleep(1000 * 10e-1);
			cout << "       " << "按其他任意键返回" << endl;
			Sleep(1000 * 10e-1);
			cout << "        " << "请输入您的选择:";
			cin >> c;
			 

			switch (c)
			{
			case 1:
				maxrand = 15; life = 3; 
				//PlaySound(TEXT(".\\BGM\\AreYouReady.wav"), NULL, SND_FILENAME | SND_SYNC /*| SND_NOSTOP| SND_LOOP */ | SND_NODEFAULT);
				_continue();
				
				break;
			case 2:
				maxrand = 30; life = 3; 
				//PlaySound(TEXT(".\\BGM\\AreYouReady.wav"), NULL, SND_FILENAME | SND_SYNC /*| SND_NOSTOP| SND_LOOP */ | SND_NODEFAULT);
				_continue();
				break;
			case 3:
				maxrand = 50; life = 5; 
				//PlaySound(TEXT(".\\BGM\\AreYouReady.wav"), NULL, SND_FILENAME | SND_SYNC /*| SND_NOSTOP| SND_LOOP */ | SND_NODEFAULT);
				_continue();
				break;
			case 4:
				maxrand = 300; life = 7; 
				//PlaySound(TEXT(".\\BGM\\AreYouReady1.wav"), NULL, SND_FILENAME | SND_SYNC /*| SND_NOSTOP| SND_LOOP */ | SND_NODEFAULT);
				_continue();
				break;
			case 5:
				maxrand = 1000;	life = 10; 
				//PlaySound(TEXT(".\\BGM\\AreYouReady.wav"), NULL, SND_FILENAME | SND_SYNC /*| SND_NOSTOP| SND_LOOP */ | SND_NODEFAULT);
				_continue();
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
					{
						cout << ":)设置完成！开始游戏...";
						PlaySound(TEXT(".\\BGM\\AreYouReady.wav"), NULL, SND_FILENAME | SND_ASYNC /*| SND_NOSTOP| SND_LOOP */ | SND_NODEFAULT);
						_continue();
					}
					else
					{
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);//调整文字颜色
						cout << "生命上限非法，请重新设置！（范围：0到您输入的数字之间）" << endl;
						cout << endl;
						goto lable;

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
			case 7:
				cout << "are you ready ?";
				cin >> ask;
				if (ask=="yes" && ask== "YES", "yes", "Yes", "yEs", "yeS")
				{
				
                maxrand = 15; life = 3;
				MessageBox(NULL, L"Are you ready?", L"Jackpot", MB_OK | MB_ICONWARNING | MB_SETFOREGROUND);
				MessageBox(NULL,L"Enjoy it ，Haha！", L"Jackpot", MB_OK|MB_ICONWARNING|MB_SETFOREGROUND);
				_continue();
				}
				
				else
				{
					Start();
				}
				

				break;
			default:
				Start();
	}
	break;
		

	
	case 2:
			cout << "       " << "1: 彩蛋" << endl;
			Sleep(1000 * 10e-1);
			cout << "       " << "2：打开项目主页" << endl;
			Sleep(1000 * 10e-1);
			cout << "        " << "请输入您的选择:";
			cin >> e;
			switch (e)
			{
			case 1:
				randraw();
				Start();
			case 2:

				ShellExecuteA(NULL, "open", "https://github.com/DavidLogic/Jackpot", NULL, NULL, SW_SHOWDEFAULT);
				cout << "已成功打开网页！" << endl;

				Start();
			case 3:
				cout << "返回" << endl;
				Start();
				break;
			default :
				Start();
				
			}
			break;
		default:
			cout << "已退出游戏 :( ,bye~~~";
			Sleep(1000 * 2);
			exit(0);
	}
		
	
	
}
void GetResults() {
	if (c == 7 and life <= 0)
	{
		MessageBox(NULL, L"See you next time", L"Jackpot", MB_OK | MB_ICONERROR | MB_SETFOREGROUND);
		cout << "bye!";
		//say something
		Sleep(1000 * 3);
		ShellExecuteA(NULL, "open", "not your fault.exe", NULL, NULL, SW_SHOWDEFAULT);
	}
	if (life <= 0) { 
		cout << " X_X 遗憾，头奖擦肩而过 /(ㄒoㄒ)/~~  "<<endl<<endl;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN);//调整文字颜色
			cout << "揭秘最终答案:" << j << endl<< endl;
			cout << "Tips:偶遇水逆?没有问题，那就再来一局！";
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
	

	if ((i > maxrand) || (i < 0)) 
	{ 
		cout << "错误: 数字不在 0 和 " << maxrand << "之间" << " " << endl;
		GetResults();
	}

	if (i == j)  //胜利
	{
		PlaySound(TEXT(".\\BGM\\Jackpot.wav"), NULL, SND_FILENAME | SND_ASYNC  | SND_NODEFAULT);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY |FOREGROUND_RED | FOREGROUND_GREEN);//调整文字颜色
		MessageBox(NULL, L"Gamer Gamer Jackpot Winner！", L"Jackpot", MB_OK | MB_ICONHAND | MB_SETFOREGROUND);
		cout << "^0^ Gamer Gamer Jackpot Winner！\n\n"; 
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
void _continue()
{
	cout << "游戏开始！！！" << endl;
	srand((unsigned)time(NULL));
	j = rand() % maxrand;
	/*cout << j;*/
	GetResults();
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

void _playsound()
{
	srand((unsigned)time(NULL));
	N = 1+rand() % 7;
	if (N == 1)
	{
		PlaySound(TEXT(".\\BGM\\BGM1.wav"), NULL, SND_FILENAME | SND_ASYNC /*| SND_NOSTOP| SND_LOOP */| SND_NODEFAULT);
	}
	else if (N ==2 )
	{
		PlaySound(TEXT(".\\BGM\\BGM2.wav"), NULL, SND_FILENAME | SND_ASYNC /*| SND_NOSTOP | SND_LOOP */| SND_NODEFAULT);
	}
	else if (N == 3)
	{
		PlaySound(TEXT(".\\BGM\\BGM3.wav"), NULL, SND_FILENAME  | SND_ASYNC /*| SND_NOSTOP | SND_LOOP*/ | SND_NODEFAULT);
	}
	else if (N == 4)
	{
		PlaySound(TEXT(".\\BGM\\BGM4.wav"), NULL, SND_FILENAME  | SND_ASYNC /* | SND_NOSTOP| SND_LOOP */| SND_NODEFAULT);
	}
	else if (N == 5)
	{
		PlaySound(TEXT(".\\BGM\\BGM5.wav"), NULL, SND_FILENAME | SND_ASYNC /*| SND_NOSTOP | SND_LOOP */| SND_NODEFAULT);
	}
	else if (N==6)
	{
		PlaySound(TEXT(".\\BGM\\BGM6.wav"), NULL, SND_FILENAME  | SND_ASYNC  /*| SND_NOSTOP| SND_LOOP */| SND_NODEFAULT);
	}
	else if (N == 7)
	{
		PlaySound(TEXT(".\\BGM\\Jackpot.wav"), NULL, SND_FILENAME | SND_ASYNC /*| SND_NOSTOP | SND_LOOP */| SND_NODEFAULT);
	}
}

void drawpic()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN);//调整文字颜色
	cout <<endl<< "滑天下之大稽 :D  ~~~" << endl<<"自动滑稽中..."<<endl;
	Sleep(1000 * 5);
	cout <<
		"MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n" <<
		"MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNNNNNNNNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n" <<
		"MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNys + omNmmdddddddddddmmNh / +shMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n" <<
		"MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMmMNmh + ydddddmmmmmddddd + odmNMmMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n" <<
		"MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNmddddhmmmmmmmmmmmmmmddddddmNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n" <<
		"MMMMMMMMMMMMMMMMMMMMMMMMMMMMdo + dmmmmmmddddmmmmmmmdo + ymmmmmmddmmNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n" <<
		"MMMMMMMMMMMMMMMMMMMMMMMMMMMh / ymmmmmmmNMMhdmmmmhs / mmmmmmmmNMNdMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n" <<
		"MMMMMMMMMMMMMMMMMMMMMMMMMMMmhhddddddmmmddddmmmmmmdhdmmmddddddhhdNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n" <<
		"MMMMMMMMMMMMMMMMMMMMMMMMMMNdddddhhhddmmmmmmmmmmmmmmmmmddhhhdddddNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n" <<
		"MMMMMMMMMMMMMMMMMMMMMMMMMMmdddmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmdddmMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n" <<
		"MMMMMMMMMMMMMMMMMMMMMMMMMNmddmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmddmMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n" <<
		"MMMMMMMMMMMMMMMMMMMMMMMMMNmddmdmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmdddmNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n" <<
		"MMMMMMMMMMMMMMMMMMMMMMMMMNmdddhmmmmmmmmmmmmmmmmmmmmmmmmmmmmmhdddmMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n" <<
		"MMMMMMMMMMMMMMMMMMMMMMMMMMmdddhhmmmmmmmmmmmmmmmmmmmmmmmmmmmdhdddmMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n" <<
		"MMMMMMMMMMMMMMMMMMMMMMMMMMNmdddhhmmmmmmmmmmmmmmmmmmmmmmmmmdydddmNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n" <<
		"MMMMMMMMMMMMMMMMMMMMMMMMMMMNddddhsdmmmmmmmmmmmmmmmmmmmmmdyydddmNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n" <<
		"MMMMMMMMMMMMMMMMMMMMMMMMMMMMNmddddysydmmmmmmmmmmmmmmmmhssddddmNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n" <<
		"MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMmddddmhsoosyhhdddhhysooshdddddmMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n" <<
		"MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNmdddddmmdhysooossydmddddddmNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n" <<
		"MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNmdddddddddddddddddddmNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n" <<
		"MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNNmmmdddddddmmmNNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n";
}

void randraw()
{
	srand((unsigned)time(NULL));
	Y = 1 + rand() % 2;
	if (Y == 1)
	{
		drawpic();
	}
	else if (Y==2)
	{
		cout << "说些什么吧：" << endl;
		cin >> draw_love;
		cout << "系统绘制中..." << endl;
		Sleep(1000 * 5);
		draw(draw_love);
		Sleep(1000 * 3);
	}
}

void _sleep()
{
	Sleep(1000 * 10e-2);
}

