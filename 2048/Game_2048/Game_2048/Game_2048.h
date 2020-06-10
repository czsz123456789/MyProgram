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
	//��ʼ����Ϸ�����ӵ�
	Game();
	//��Ϸ��ʼ
	void Game_Start();
	//�ж���Ϸ�Ƿ����
	bool GameIsOver();
	//�ƶ�����
	void move(Directions dir);
	//�����µ���
	bool newrandnum(int num);
	//�ƶ���ϲ�
	void merge(Directions dir);
	//��ӡ���ֺ���
	void my_print();
	//��ӡ���溯��
	void print_screen();
	//��Ϸ���к�ȡ�ÿ�������
	void run();
private:
	std::vector<std::vector<int> > Game_Grid = std::vector<std::vector<int> > (4,std::vector<int>(4));
	bool flag;//��Ϸ���б�־
	int score; //����
	int num_count;//��ǰ���ָ���
};