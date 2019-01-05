#include <string>
#include <iostream>
#include <ctime> 
#include<algorithm>
#include<vector>
using namespace std;
void dfs(int start_x, int start_y, int end_x, int end_y, int m, int n, vector<int>&temp, vector<vector<int>>&res, vector<vector<int>>flag, vector<vector<int>>&visited,int &minstep)
{
	if (start_x == end_x&&start_y == end_y)
	{
		res.push_back(temp);
		if (temp.size()<minstep) minstep = temp.size();
		return;
	}
	if (start_x >n|| start_y > m||start_x<0||start_y<0)
	{
		return;
	}
	if (flag[start_x][start_y] == 1||visited[start_x][start_y]==1)
	{
		return;
	}
	if (temp.size()>=minstep-2) return;//剪枝策略
	visited[start_x][start_y] = 1;
	temp.push_back(start_x);
	temp.push_back(start_y);
	dfs(start_x + 1, start_y, end_x, end_y, m, n, temp, res, flag, visited,minstep);
	dfs(start_x , start_y+1, end_x, end_y, m, n, temp, res, flag, visited,minstep);
	dfs(start_x -1, start_y, end_x, end_y, m, n, temp, res, flag, visited,minstep);
	dfs(start_x , start_y-1, end_x, end_y, m, n, temp, res, flag, visited,minstep);
	temp.pop_back();
	temp.pop_back();
	visited[start_x][start_y] = 0;
	return;
	
}
int main()
{
	int n, m, start_x, start_y, end_x, end_y, obstacle_num;
	cin >> n >> m>>start_x>>start_y>>end_x>>end_y>>obstacle_num;
	vector<vector<int>>v(obstacle_num,vector<int>(2));
	
	for (int i = 0; i < obstacle_num; i++)
	{
		cin >> v[i][0] >> v[i][1];
	}
	vector<vector<int>>flag(n+1,vector<int>(m+1,0));//是否是障碍点
	vector<vector<int>>visited(n + 1, vector<int>(m + 1,0));
	for (int i = 0; i < obstacle_num; i++)
	{
		flag[v[i][0]][v[i][1]] = 1;
	}
	int minstep = INT_MAX;
	vector<int>temp;
	vector<vector<int>>res;
	dfs(start_x, start_y, end_x, end_y, m, n, temp, res, flag, visited,minstep);
	if (res.size() == 0) 
	{ cout << "no way out" << endl; 
		return 0;
	}
	int count = INT_MAX;
	int index = -1;
	for (int i = 0; i < res.size(); i++)
	{
		int step = res[i].size();
		if (step < count)
		{
			count = step;
			index = i;
		}
	}
	for (int j = 0; j < res[index].size()/2; j++)
	{
		cout << "[" << res[index][2 * j] << "," << res[index][2 * j + 1] << "]";
	}
	cout << "[" <<end_x << "," << end_y << "]"<<endl;
	
	return 0;
}
