#include<iostream>
#include<queue>
using namespace std;
char Moligpy[210][210];
int b[210][210];
int dir[4][2] = { {-1,0},{0,-1},{0,1},{1,0} };
int N, M;
struct node
{
	int x, y;
	int moves;
}start, end;
void BFS()
{
	queue<node>list;
	list.push(start);
	node temptop, temppos;
	while (!list.empty())
	{
		temptop = list.front();
		list.pop();
		for (int i = 0; i < 4; i++)
		{
			temppos.x = temptop.x + dir[i][0];
			temppos.y = temptop.y + dir[i][1];
			temppos.moves = temptop.moves + 1;
			if (Moligpy[temppos.x][temppos.y] == 'x')
				temppos.moves += 1;
			if (temppos.x < 0 || temppos.x >= N || temppos.y < 0 || temppos.y >= M || b[temppos.x][temppos.y] <= temppos.moves)
				continue;
			if (Moligpy[temppos.x][temppos.y] != '#')
			{
				b[temppos.x][temppos.y] = temppos.moves;
				list.push(temppos);
			}
		}
	}
}
int main()
{
	while (cin >> N >> M)
	{
		int a_x, a_y;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				cin >> Moligpy[i][j];
				b[i][j] = 10000000;
				if (Moligpy[i][j] == 'r')
				{
					start.x = i;
					start.y = j;
					start.moves = 0;
				}
				if (Moligpy[i][j] == 'a')
				{
					a_x = i;
					a_y = j;
				}
			}
		}
		BFS();
		if (b[a_x][a_y] != 10000000)
			cout << b[a_x][a_y] << endl;
		else
			cout << "Poor ANGEL has to stay in the prison all his life." << endl;
	}
	return 0;
}