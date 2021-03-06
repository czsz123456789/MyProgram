// Game_2048.cpp: 定义控制台应用程序的入口点。
//

#include "Game_2048.h"

inline Game::Game()
{

}

bool Game::GameIsOver()
{
	for(int i = 0 ;i < 4;i++)
		for (int j = 0; j < 4; j++)
		{
			if (Game_Grid[i][j] == 0)
				return false;
		}
	//还要判断能否合并
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
		{
			if (Game_Grid[i][j] == Game_Grid[i + 1][j] || Game_Grid[i][j] == Game_Grid[i][j + 1])
				return false;
		}
	return true;
}
void Game::move(Directions dir)
{
	switch (dir)
	{
	case up://一列一列从上到下搜索
		for (int col = 0; col < 4;col++)//列
			for (int row = 2; row >= 0;row--)
			{
				//找不为零的数
				while (row >= 0 && Game_Grid[row][col] == 0)
					row--;
				if (row < 0)
					break;
				
				//找一行放这个数
				int i = 3;
				while (i > row)
				{
					if (Game_Grid[i][col] == 0)
					{
						Game_Grid[i][col] = Game_Grid[row][col];
						Game_Grid[row][col] = 0;
						//row = i;
						break;
					}
					i--;
				}	
			}
		break;
	case down:
		for (int col = 0; col < 4;col++)//列
			for (int row = 1; row < 4; row++)
			{
				//找第一个不为零的数
				while (row < 4 && Game_Grid[row][col] == 0)
					row++;
				if (row >= 4)
					break;
				int i = 0;
				while (i < row)
				{
					if (Game_Grid[i][col] == 0)
					{
						Game_Grid[i][col] = Game_Grid[row][col];
						Game_Grid[row][col] = 0;
						break;
					}
					i++;
				}
			}
		break;
	case left:
		for(int row = 0;row < 4;row++)//行
			for (int col = 1; col < 4; col++)
			{
				while (col < 4 && Game_Grid[row][col] == 0)
					col++;
				if (col >= 4)
					break;
				int i = 0;
				while (i < col)
				{
					if (Game_Grid[row][i] == 0)
					{
						Game_Grid[row][i] = Game_Grid[row][col];
						Game_Grid[row][col] = 0;
						break;
					}
					i++;
				}
			}
		break;
	case right:
		for (int row = 0; row < 4; row++)//行
			for (int col = 2; col >= 0 ; col--)
			{
				while (col >= 0 && Game_Grid[row][col] == 0)
					col--;
				if (col < 0)
					break;
				int i = 3;
				while (i > col)
				{
					if (Game_Grid[row][i] == 0)
					{
						Game_Grid[row][i] = Game_Grid[row][col];
						Game_Grid[row][col] = 0;
						break;
					}
					i--;
				}
			}
		break;
	default:
		break;
	}
}

void Game::merge(Directions dir) //先合并再移动
{
	switch (dir)
	{
	case up://一列一列从下到上搜索
		for (int col = 0; col < 4; col++)
		{
			for (int row = 0; row < 4; )
			{
				while (row < 4 && Game_Grid[row][col] == 0)//第一个非零的数
					row++;
				if (row >= 4)
					break;
				int sec_row = row + 1;
				while (sec_row < 4 && Game_Grid[sec_row][col] == 0)//第二个非零的数
					sec_row++;
				if (sec_row >= 4)
					break;
				else//找到
				{
					if (Game_Grid[sec_row][col] == Game_Grid[row][col]) //两个数相同就合并
					{
						Game_Grid[sec_row][col] *= 2;
						score += Game_Grid[sec_row][col];
						Game_Grid[row][col] = 0;
						//当前数字的总数减一
						num_count--;

						break;//只合并一次
					}
					else
					{
						row = sec_row;//不同则以第二个数为起点向后搜索
					}
				}
			}
		}
		move(up);
		break;
	case down:
		for (int col = 0; col < 4; col++)
		{
			for (int row = 3; row >= 0; )
			{
				while (row >= 0 && Game_Grid[row][col] == 0)//第一个非零的数
					row--;
				if (row < 0)
					break;
				int sec_row = row - 1;
				while (sec_row >= 4 && Game_Grid[sec_row][col] == 0)//第二个非零的数
					sec_row--;
				if (sec_row < 0)
					break;
				else//找到
				{
					if (Game_Grid[sec_row][col] == Game_Grid[row][col]) //两个数相同就合并
					{
						Game_Grid[sec_row][col] *= 2;
						score += Game_Grid[sec_row][col];
						Game_Grid[row][col] = 0;

						num_count--;
						break;//只合并一次
					}
					else
					{
						row = sec_row;//不同则以第二个数为起点向后搜索
					}
				}
			}
		}
		move(down);
		break;
	case left:
		for (int row = 0; row < 4; row++)
			for (int col = 3; col >= 0;)//从右到左搜索
			{
				while (col >= 0 && Game_Grid[row][col] == 0)
					col--;
				if (col < 0)
					break;
				int sec_col = col - 1;
				while (sec_col >= 0 && Game_Grid[row][sec_col] == 0)
					sec_col--;
				if (sec_col < 0)
					break;
				else
				{
					if (Game_Grid[row][col] == Game_Grid[row][sec_col])
					{
						Game_Grid[row][sec_col] *= 2;
						score += Game_Grid[row][sec_col];
						Game_Grid[row][col] = 0;

						num_count--;
						break;//只合并一次
					}
					else
					{
						col = sec_col;
					}
				}
			}
		move(left);
		break;
	case right:
		for (int row = 0; row < 4; row++)
			for (int col = 0; col < 4;)//从左到右搜索
			{
				while (col < 4 && Game_Grid[row][col] == 0)
					col++;
				if (col >= 4)
					break;
				int sec_col = col + 1;
				while (sec_col < 4 && Game_Grid[row][sec_col] == 0)
					sec_col++;
				if (sec_col >= 4)
					break;
				else
				{
					if (Game_Grid[row][col] == Game_Grid[row][sec_col])
					{
						Game_Grid[row][sec_col] *= 2;
						score += Game_Grid[row][sec_col];
						Game_Grid[row][col] = 0;

						num_count--;
						break;//只合并一次
					}
					else
					{
						col = sec_col;
					}
				}
			}
		move(right);
		break;
	default:
		break;
	}
	newrandnum(1);
}

void Game::my_print()
{
	//查cout的格式化输出宽度等
	for (int row = 3; row >= 0 ;row--) //视觉效果，数组的最后一行显示在顶部
	{
		std::cout << "-------";
		for (int col = 0; col < 4; col++)
		{
			if (Game_Grid[row][col] == 0)
				std::cout <<"|" << std::setw(4);
			else
				std::cout << "|"<<std::setw(2)<<Game_Grid[row][col]<<" ";
		}
		std::cout << "|" << std::setw(4);
		std::cout << "-------";
		std::cout << std::endl;
	}
}

void Game::run()
{
	my_print();
	char p;
	while (flag)
	{
		flag = !GameIsOver();
		if (flag == false)
			break;
		p = _getch();
		switch (p)
		{
		case('w'):
			merge(up);
			break;
		case('s'):
			merge(down);
			break;
		case('a'):
			merge(left);
			break;
		case('d'):
			merge(right);
			break;
		case(27):
			flag = false;
			break;
		default:
			break;
		}
		system("cls");        //清屏刷新
		print_screen();
		my_print();
	}
}

void Game::Game_Start()
{
	while (1)
	{
		num_count = 0;
		score = 0;
		//初始化随机种子
		srand((unsigned)time(NULL));
		flag = 1;
		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 4; j++)
				Game_Grid[i][j] = 0;
		newrandnum(2);

		run();

		std::cout << "游戏结束,你的最终分数是：" << score << std::endl;
		std::cout << "输入r重新开始" << std::endl;
		
		char p = '\0';
		std::cin >> p;
		if (p != 'r')
			break;
	}
	
}

void Game::print_screen()
{
	std::cout << "-----Game ---- 2048-----" << std::endl <<std::endl;
	std::cout << " w ：上移" << std::endl;
	std::cout << " s ：下移" << std::endl;
	std::cout << " a ：左移" <<"      "<<"分数："<<score<<std::endl;
	std::cout << " d ：右移" << std::endl;
	std::cout << "esc：退出" << std::endl;

	std::cout << std::endl << std::endl;
	//增加打印计分等功能
}

bool Game::newrandnum(int num)//num：新增几个数
{
	if (num > 16 - num_count) //空格子不够就不加新数了
	{
		std::cout << "这样走就没了！" << std::endl;
		return false;
	}
		
	int count = 0;
	while (count < num) //不能写成死循环
	{
		int row = rand() % 4;
		int col = rand() % 4;
		if (Game_Grid[row][col] == 0)
		{
			if (rand() % 9 <= 4)
				Game_Grid[row][col] = 2;
			else
				Game_Grid[row][col] = 4;
			count++;
			num_count++;
		}
	}
	return true;
}

int main()
{
	Game A;
	A.print_screen();

	A.Game_Start();
	system("pause");
    return 0;
}

