#include<iostream>
#include<queue>
#include<string.h>
using namespace std;
int dir[8][2] = { {2,1 }, { 2,-1 }, { -2,1 }, { -2,-1 }, { 1,2 }, { -1,2 }, { -1,-2 }, { 1,-2 } };
int Chess[9][9];
int Count;
struct node
{
	int x;
	int y;
	int move;
};

int bfs(node start, node end1)
{
	/*if (start.x == end1.x && start.y == end1.y)
		return start.move;*/
	queue<node>list;
	list.push(start);
	node temptop;
	node temppos;
	Chess[start.x][start.y] = -1;
	while (!list.empty())
	{
		temptop = list.front();
		if (temptop.x == end1.x && temptop.y == end1.y)
		{
			//cout << "³¤¶È£º" << list.size() << endl;
			return temptop.move;
		}
		list.pop();
		for (int i = 0; i < 8; i++)
		{
			temppos.x = temptop.x + dir[i][0];
			temppos.y = temptop.y + dir[i][1];
			temppos.move = temptop.move + 1;
			if (temppos.x < 0 || temppos.x >= 8 || temppos.y < 0 || temppos.y >= 8)
				continue;
			if (Chess[temppos.x][temppos.y] == 0)
			{
				list.push(temppos);
				Chess[temppos.x][temppos.y] = -1;
			}
		}
	}
	return 0;
}
int main()
{
	char start_x[3], end_x[3];
	while (cin >> start_x >> end_x)
	{
		memset(Chess, 0, sizeof(Chess));
		node start, end1;
		start.x = start_x[0] - 'a';
		start.y = start_x[1] - 49;
		end1.x = end_x[0] - 'a';
		end1.y = end_x[1] - 49;
		start.move = 0;
		int count = bfs(start, end1);
		cout << "To get from " << start_x << " to " << end_x << " takes " << count << " knight moves." << endl;
	}
	return 0;
}