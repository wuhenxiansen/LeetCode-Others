// 514自由之路.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include<vector>
#include<string>
#include<map>
#include<algorithm>
#include<cmath>
using namespace std;
int dfs(string& ring, string& key, int index, int cur, map<char, vector<int>>& mp,int **solution)
{
	if (index == key.size())
	{
		return 0;
	}
	if (solution[cur][index] > 0)//已存值  直接返回
		return solution[cur][index];
	vector<int> t = mp[key[index]];
	int Min = INT_MAX;
	for (int j = 0; j < t.size(); j++)
	{
		/*int d=1;
		d+= abs(cur - index)<ring.size()-abs(cur - index)? abs(cur - index) : ring.size() - abs(cur - index);*/
		int d, d1, d2;
		if (t[j] > cur)
		{
			d1 = t[j] - cur;
			d2 = cur + ring.size() - t[j];
			d = min(d1, d2);
		}
		else {
			d1 = cur - t[j];
			d2 = t[j] + ring.size() - cur;
			d = min(d1, d2);
		}
		d++;
		int nextmin_step =dfs(ring, key, index + 1, t[j], mp, solution);
		Min = min(Min, nextmin_step + d);
	}
	solution[cur][index] = Min;
	return Min;	
}
int findRotateSteps(string ring, string key) {
	int m = ring.size();
	int n = key.size();
	int cur = 0;//初始12：00方向位置
	int i = 0;
	int ans = 0;
	int** solution = new int* [m];
	for (int i = 0; i < m; i++)
	{
		solution[i] = new int[n];
		for (int j = 0; j < n; j++)
			solution[i][j] = -1;
	}
	map<char, vector<int>> mp;
	for (int i = 0; i < m; i++)
	{
		if (mp.count(ring[i]) == 0)
		{
			vector<int> t;
			t.push_back(i);
			mp[ring[i]] = t;
		}
		else
		{
			mp[ring[i]].push_back(i);//vector 肯定是升序的
		}
	}
	ans = dfs(ring, key, 0, 0, mp,solution);
	return ans;
}
int main()
{
	string ring = "caotmcaataijjxi";
	string key = "oatjiioicitatajtijciocjcaaxaaatmctxamacaamjjx";
	cout << findRotateSteps(ring, key);
	system("pause");
	return 0;
}
// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单


// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
