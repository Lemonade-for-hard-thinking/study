
#include <iostream>
#include<string.h>
using namespace std;
const int maxlen = 1001;

char str[maxlen];
int a[10000][10000];

int cost(int start, int tail)// ÆÕÍ¨µÝ¹éËã·¨
{
    int x, y;
    if (start >= tail) return 0;
    if (str[start] == str[tail])
    {
        if (a[start + 1][tail - 1] == -1)
        {
            a[start + 1][tail - 1] = cost(start + 1, tail - 1);
            return cost(start + 1, tail - 1);
        }
        else
            return a[start + 1][tail - 1];
    }
    if (a[start + 1][tail] == -1)
    {
        a[start + 1][tail] = cost(start + 1, tail);
        x = cost(start + 1, tail);

    }
    else x = a[start + 1][tail];

    if (a[start][tail - 1] == -1)
    {
        a[start][tail - 1] = cost(start, tail - 1);
        y = cost(start, tail - 1);
    }
    else y = a[start + 1][tail];

    if (x > y) return y + 1; else  return x + 1;
}

int main()
{
    memset(a, -1, sizeof(a));
    while (scanf("%s", str) != EOF)
    {
        int len;

        len = strlen(str);

        cout << cost(0, len - 1);


    }
    return 0;
}

