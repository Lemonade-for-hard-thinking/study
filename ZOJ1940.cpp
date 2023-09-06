#include<iostream>
#include<queue>
using namespace std;

int L, R, C;
char Dungeon[40][40][40];
int dir[6][3] = { {1,0,0},{0,1,0},{0,0,1},{-1,0,0},{0,-1,0},{0,0,-1} };

struct node
{
	int l, r, c;
	int moves;
}start, exit1;

int BFS()
{
	queue<node>list;
	list.push(start);
	Dungeon[start.l][start.r][start.c] = '#';
	node temptop, temppos;
	while (!list.empty())
	{
		temptop = list.front();
		list.pop();
		if (temptop.l == exit1.l && temptop.r == exit1.r && temptop.c == exit1.c)
			return temptop.moves;
		for (int i = 0; i < 6; i++)
		{
			temppos.l = temptop.l + dir[i][0];
			temppos.r = temptop.r + dir[i][1];
			temppos.c = temptop.c + dir[i][2];
			temppos.moves = temptop.moves + 1;
			if (temppos.l < 0 || temppos.l >= L || temppos.r < 0 || temppos.r >= R || temppos.c < 0 || temppos.c >= C)
				continue;
			if (Dungeon[temppos.l][temppos.r][temppos.c] == '#')
				continue;
			list.push(temppos);
			Dungeon[temppos.l][temppos.r][temppos.c] = '#';
		}
	}
	return -1;
}

int main()
{
	while (cin >> L >> R >> C)
	{
		if (L == 0 && R == 0 && C == 0)
			break;;
		for (int i = 0; i < L; i++)
		{
			for (int j = 0; j < R; j++)
			{
				for (int k = 0; k < C; k++)
				{
					cin >> Dungeon[i][j][k];
					if (Dungeon[i][j][k] == 'S')
					{
						start.l = i;
						start.r = j;
						start.c = k;
						start.moves = 0;
					}
					if (Dungeon[i][j][k] == 'E')
					{
						exit1.l = i;
						exit1.r = j;
						exit1.c = k;
					}
				}
			}
		}
		int temp = BFS();
		if (temp == -1)
			cout << "Trapped!" << endl;
		else
			cout << "Escaped in " << temp << " minute(s)." << endl;
	}
	return 0;
}