#include<iostream>
#include<time.h>

using namespace std;

const int y = 10;
const int x = 8;
int HeroX = x / 2;
int HeroY = y - 1;
int row = 0;


void Print(char field[y][x]);
void Initialize(char field[y][x]);
void AddEnemy(char field[y][x], int count);
void MoveEnemy(char field[y][x]);
void MoveHeroLeft(char field[y][x]);
void MoveHeroRight(char field[y][x]);
void Fire(char field[y][x]);


void main()
{
	char field[y][x];

	int count = 8;

	Initialize(field);
	AddEnemy(field, count);
	MoveEnemy(field);
	MoveHeroLeft(field);
	MoveHeroRight(field);
	Fire(field);

	Print(field);

}

void Print(char field[y][x])
{
	for (size_t i = 0; i < y; i++)
	{
		for (size_t j = 0; j < x; j++)
		{
			cout << field[i][j] << " ";
		}
		cout << endl;
	}
}

void Initialize(char field[y][x])
{
	for (size_t i = 0; i < y; i++)
	{
		for (size_t j = 0; j < x; j++)
		{
			field[i][j] = '0';
		}
	}
	field[HeroY][HeroX] = 30;
}

void AddEnemy(char field[y][x], int count)
{
	srand(time(0));
	for (size_t i = 0; i < 1; i++)
	{
		for (size_t j = 0; j < count; j++)
		{
			int c = rand() % x;
			if (field[i][c] == '0')
			{
				field[i][c] = 'Q';
			}
			else
			{
				count++;
			}
		}
	}
}

void MoveEnemy(char field[y][x])
{
	for (size_t i = 0; i < 1; i++)//я когда пишу "	for (size_t i = 0; i < i + 1; i++)//" вывод вообще не срабатывает
	{
		for (size_t j = 0; j < x; j++)
		{
			swap(field[row][j], field[row + 1][j]);
		}
	}
	row++;
}

void MoveHeroLeft(char field[y][x])
{
	swap(field[HeroY][HeroX], field[HeroY][HeroX - 1]);
	HeroX--;
	//супер мега изменение!!!
}

void MoveHeroRight(char field[y][x])
{
	swap(field[HeroY][HeroX], field[HeroY][HeroX + 1]);
	HeroX++;
}

void Fire(char field[y][x])
{
	for (size_t i = 0; i < y - 1; i++)
	{
		for (size_t j = 0; j < 1; j++)
		{
			field[i][HeroX] = ' ';
		}
	}
}
