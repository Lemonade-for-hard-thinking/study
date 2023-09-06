#include<iostream>
using namespace std;
int s = 0;

void f(int n, int k, int now)
{
	int i;
	if (k == 1)
	{
		s++;
	}
	else
	{
		for (i = now; i <= n / k; i++)
		{
			f(n - i, k - 1, i);
		}
	}
}
int main()
{
	int n, k;
	cin >> n >> k;
	f(n, k, 1);
	cout << s << endl;
	return 0;
}