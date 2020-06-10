#pragma once

#include <iostream>
#include <vector>
#include "conio.h"    //for getch()
#include <stdlib.h>
#include <time.h>
#include <iomanip>

//using namespace std;


enum Directions
{
	up,down,left,right
};

class Game
{
public:
	//初始化游戏，格子等
	Game();
	//游戏开始
	void Game_Start();
	//判断游戏是否结束
	bool GameIsOver();
	//移动函数
	void move(Directions dir);
	//生成新的数
	bool newrandnum(int num);
	//移动后合并
	void merge(Directions dir);
	//打印数字函数
	void my_print();
	//打印界面函数
	void print_screen();
	//游戏运行和取得控制命令
	void run();
private:
	std::vector<std::vector<int> > Game_Grid = std::vector<std::vector<int> > (4,std::vector<int>(4));
	bool flag;//游戏运行标志
	int score; //分数
	int num_count;//当前数字个数
};