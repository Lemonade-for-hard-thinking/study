#include<iostream>
#include<queue>
using namespace std;
int Data[100][100];
int M, N;
int dir[8][2] = { {-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1} };
struct node
{
	int x;
	int y;
}start, end1;
bool Maze()
{
	queue<node>list;
	list.push(start);
	node temp;
	node start_temp;
	while (!list.empty())
	{
		start_temp = list.front();
		list.pop();
		if (start_temp.x == end1.x && start_temp.y == end1.y)
			return true;
		for (int i = 0; i < 8; i++)
		{
			temp.x = start_temp.x + dir[i][0];
			temp.y = start_temp.y + dir[i][1];
			if (Data[temp.x][temp.y] == 0)
			{
				Data[temp.x][temp.y] = -1;
				list.push(temp);
			}
		}
	}
	return false;
}

int main()
{
	cin >> M >> N;
	while (!(M == 0 && N == 0))
	{
		for (int i = 0; i < M; i++)
		{
			for (int j = 0; j < N; j++)
			{
				cin >> Data[i][j];
			}
		}
		cin >> start.x >> start.y;
		cin >> end1.x >> end1.y;
		if (Maze())
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
		cin >> M >> N;
	}
	return 0;
}