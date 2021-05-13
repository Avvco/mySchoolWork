// NO UVA
// source https://www.programmersought.com/article/1065913355/

#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>
#include<map>
#include<set>
using namespace std;

char field[105][105];

int main()
{
	int m, n, t = 0;
	scanf("%d%d", &m, &n);
	while (m && n)
	{
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
				field[i][j] = '0';
		}
		for (int i = 0; i < m; i++)
		{
			getchar();//filter return
			for (int j = 0; j < n; j++)
			{
				char ch = getchar();
				if (ch == '*')
				{
					field[i][j] = '*';
					if (i - 1 >= 0 && j - 1 >= 0 && field[i - 1][j - 1] != '*')
						field[i - 1][j - 1]++;
					if (i - 1 >= 0 && field[i - 1][j] != '*')
						field[i - 1][j]++;
					if (i - 1 >= 0 && j + 1 < n && field[i - 1][j + 1] != '*')
						field[i - 1][j + 1]++;
					if (j - 1 >= 0 && field[i][j - 1] != '*')
						field[i][j - 1]++;
					if (j + 1 < n && field[i][j + 1] != '*')
						field[i][j + 1]++;
					if (i + 1 < m && j - 1 >= 0 && field[i + 1][j - 1] != '*')
						field[i + 1][j - 1]++;
					if (i + 1 < m && field[i + 1][j] != '*')
						field[i + 1][j]++;
					if (i + 1 < m && j + 1 < n && field[i + 1][j + 1] != '*')
						field[i + 1][j + 1]++;
				}
			}
		}
		if(t)
			printf("\n");
		printf("Field #%d:\n", ++t);
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
				printf("%c", field[i][j]);
			printf("\n");
		}
		scanf("%d%d", &m, &n);
	}
	return 0;
}
