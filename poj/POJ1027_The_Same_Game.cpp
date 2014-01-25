// http://blog.csdn.net/ahfywff/article/details/7294000 
/*
 * =====================================================================================
 *
 *       Filename:  poj1027_The_Same_Game.cpp
 *
 *    Description:  简单模拟题
 *
 *        Version:  1.0
 *        Created:  2012年02月24日 20时22分41秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  ahfywff (), ahfywff@163.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>

using namespace std;

char map[20][20];
bool vis[20][20];
int leave, score;
int rx, ry, rn, cnt;
int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

bool inMap(int x, int y)
{
	return (x >= 0 && x < 10 && y >= 0 && y < 15);
}

void dfs(int x, int y)
{
	vis[x][y] = true;
	cnt++;
	for (int i = 0; i < 4; ++i)
	{
		int nx = x + dir[i][0];
		int ny = y + dir[i][1];
		if (inMap(nx, ny) && map[nx][ny] == map[x][y] && !vis[nx][ny])
		{
			dfs(nx, ny);
		}
	}
}

bool choose()
{
	memset(vis, false, sizeof(vis));
	rn = 0;
	for (int i = 0; i < 15; ++i)
	{
		for (int j = 9; j >= 0; --j)
		{
			if (map[j][i] == ' ' || vis[j][i]) continue;
			cnt = 0;
			dfs(j, i);
			if (cnt > rn)
			{
				rx = j; ry = i;
				rn = cnt;
			}
		}
	}
	return rn >= 2;
}

void remove(int x, int y)
{
	char color = map[x][y];
	map[x][y] = ' ';
	for (int i = 0; i < 4; ++i)
	{
		int nx = x + dir[i][0];
		int ny = y + dir[i][1];
		if (inMap(nx, ny) && map[nx][ny] == color)
			remove(nx, ny);
	}
}

void shift()
{
	for (int i = 0; i < 15; ++i)
	{
		int pos = 9;
		for (int j = 9; j >= 0; --j)
		{
			if (map[j][i] != ' ')
				map[pos--][i] = map[j][i];
		}
		while (pos >= 0)
		{
			map[pos][i] = ' ';
			pos--;
		}
	}
	int pos = 0;
	for (int i = 0; i < 15; ++i)
	{
		if (map[9][i] != ' ')
		{
			for (int j = 0; j < 10; ++j)
			{
				map[j][pos] = map[j][i];
			}
			pos++;
		}
	}
	while (pos < 15)
	{
		for (int i = 0; i < 10; ++i)
			map[i][pos] = ' ';
		pos++;
	}
}

int main()
{
	int t;
	scanf("%d", &t);
	for (int cas = 1; cas <= t; ++cas)
	{
		leave = 10 * 15;
		score = 0;
		int step = 0;
		for (int i = 0; i < 10; ++i)
		{
			scanf("%s", map[i]);
		}
		printf("Game %d:\n\n", cas);
		while (choose())
		{
			step++;
			printf("Move %d at (%d,%d): removed %d balls of color %c, got %d points.\n", step, 10 - rx, ry + 1, rn, map[rx][ry], (rn - 2) * (rn - 2));
			score += (rn - 2) * (rn - 2);
			leave -= rn;
			remove(rx, ry);
			shift();
		}
		if (leave == 0) score += 1000;
		printf("Final score: %d, with %d balls remaining.\n", score, leave);
		if (cas != t) printf("\n");
	}
}


