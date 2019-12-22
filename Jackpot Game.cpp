#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

void Start();
void GetResults();

int i, j, life, maxrand;
char c;


void Start() {
	i = 0;
	j = 0;
	life = 0;
	maxrand = 6;

	cout <<"       "<< "选择一个困难级别:\n"; // 用户必须选择一个困难级别
	cout <<"       "<< "1 : 学徒 (0-15)   （生命上限=3）\n";
	cout <<"       "<< "2 : 战士 (0-30)   （生命上限=3）\n";
	cout <<"       "<< "3 : 将军 (0-50)   （生命上限=5）\n";
	cout <<"       "<< "4 : 战神（0-300） （生命上限=7）\n";
	cout <<"       "<< "5 : 欧皇（0-1000）（生命上限=10）（据说欧皇的胜利方式很不同哦！）\n";
	cout <<"       "<< "6 : 按任意键退出游戏\n";
	c = 30;
	cout<<"\n";
    cout<<"        "<<"请输入您的困难级别:"; 
	cin >> c;                   // read the user's choice 
	cout << "\n";

	switch (c) {
	case '1':
		maxrand = 15;life = 3;  // the random number will be between 0 and maxrand
		break;
	case '2':
		maxrand = 30;life = 3;
		break;
	case '3':
		maxrand = 50;life = 5;
		break;
	case '4':
			maxrand = 300;life = 7;
			break;
	case'5':
		maxrand = 1000;
		life = 10;
			break;
		default:
			exit(0);
			break;
	}

         // number of lifes of the player
	srand((unsigned)time(NULL)); // init Rand() function
	j = rand() % maxrand;  // j get a random value between 0 and maxrand

	GetResults();
}

void GetResults() {
	if (life <= 0) { // if player has no more life then he loses
		cout << "遗憾，头奖距你仅差一步 !\n\n";
		Start();
	}

	cout << "请输入一个数字: \n";
	cin >> i;

	if ((i > maxrand) || (i < 0)) { // if the user number isn't correct, restart
		cout << "错误: 数字不在 0 和 " << maxrand<<"之间"<<" "<<endl;
		GetResults();
	}

	if (i == j) {
		cout << "The Jackpot is yours!\n\n"; // the user found the secret number
		while(c=='5')
		{cout<<"!!!Jackpot!!!"; } 
	
		Start();
	}
	else if (i > j) {
		cout << "太大了\n";
		life = life - 1;
		cout << "您的剩余生命: " << life << "\n\n";
		GetResults();
	}
	else if (i < j) {
		cout << "太小了\n";
		life = life - 1;
		cout << "您的剩余生命: " << life << "\n\n";
		GetResults();
	}
}

int main() {
	cout <<"                             "<< "** ！！！Jackpot！！！ **\n";
	cout <<"                                                        "<< "作者：David Logic"   "更新时间:22/12/2019""版本：v1.0""\n";
	cout <<"                                                        "<<"项目主页：https://github.com/DavidLogic/Jackpot-Game"<<endl; 
	cout <<"                        "<< "游戏规则：我们的目标是猜测一个数字。\n";
	cout <<"                        "<< "Jackpot会告诉你";
	cout << "与要猜测的数字相距大小。\n\n";
	cout <<"                        "<< "准备好了吗？\n";
	cout <<"                        "<< "头脑风暴开始！！！\n";
	cout <<"                        "<< "Let's win the Jackpot！\n";
		Start();
	return 0;
}


