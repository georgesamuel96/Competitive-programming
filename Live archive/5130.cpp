#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<sstream>
#include<vector>
#include<algorithm>
#include<string.h>
#include<set>
#include<fstream>
#include<map>
#include<string>
#include <stdio.h>
#include<bitset>
#include<queue>
#include<iomanip>
#include<cmath>
#include<stack>
#include<climits>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<ll>vl;
typedef vector<int>vi;
typedef vector<bool>vb;
typedef vector<double>vd;
typedef vector<char>vc;
typedef vector<string>vs;
#define MP make_pair
#define all(v) v.begin(),v.end()
#define EPS 1e-9
#define PI 3.14159265359
const ll mod = 1000000007;
const ll OO = (ll)1e18;
const int dx[] = { 0, 1, -1, 0, 1, -1, 1, -1 };
const int dy[] = { 1, 0, 0, -1, 1, -1, -1, 1 };
ll gcd(ll a, ll b){ if (b == 0){ return a; }return gcd(b, a % b); }
ll fast_power(ll base, ll power){
	if (power == 1)
		return base;
	if (power % 2 == 0)
		return fast_power((base*base), power / 2);
	else return(base*fast_power((base*base), power / 2));
}
//#pragma warning (disable : 4996)
void Qalbaz()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(4);
}

int arr[200][200];
int n, m;
map<char, string>mp;
map<int, int>mpp;
void fll()
{
	mp['0'] = "0000";
	mp['1'] = "0001";
	mp['2'] = "0010";
	mp['3'] = "0011";
	mp['4'] = "0100";
	mp['5'] = "0101";
	mp['6'] = "0110";
	mp['7'] = "0111";
	mp['8'] = "1000";
	mp['9'] = "1001";
	mp['a'] = "1010";
	mp['b'] = "1011";
	mp['c'] = "1100";
	mp['d'] = "1101";
	mp['e'] = "1110";
	mp['f'] = "1111";
}
void dfs(int r, int c)
{
	if (r < 0 || r == n || c < 0 || c == m || arr[r][c] == -1 || arr[r][c] == 1)
		return;
	arr[r][c] = -1;
	dfs(r + 1, c);
	dfs(r - 1, c);
	dfs(r, c + 1);
	dfs(r, c - 1);
}
void dfs(int r, int c, int cnt)
{
	if (r < 0 || r == n || c < 0 || c == m || arr[r][c] == -1 || arr[r][c] == 0 || arr[r][c] != 1)
		return;
	arr[r][c] = cnt;
	dfs(r + 1, c, cnt);
	dfs(r - 1, c, cnt);
	dfs(r, c + 1, cnt);
	dfs(r, c - 1, cnt);
}
void dfs2(int r, int c, int &cnt)
{
	if (r < 0 || r == n || c < 0 || c == m)
		return;
	if (arr[r][c] != 0)
	{
		cnt = max(cnt, arr[r][c]);
		return;
	}
	arr[r][c] = -2;
	dfs2(r + 1, c, cnt);
	dfs2(r - 1, c, cnt);
	dfs2(r, c + 1, cnt);
	dfs2(r, c - 1, cnt);
}

int main(){

	Qalbaz();
	fll();
	char ch;
	int x, cnt, test = 1;
	string str;
	while (cin >> n >> m && n > 0)
	{
		memset(arr, 0, sizeof arr);
		x = 0;
		cnt = 2;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				cin >> ch;
				for (int k = 0; k < 4; k++)
				{
					arr[i][x] = mp[ch][k] - '0';
					x++;
				}
			}
			x = 0;
		}
		m = m * 4;
		x = m;
		for (int i = 0; i < m; i++)
		{
			if (arr[0][i] == 0)
				dfs(0, i);
			if (arr[n - 1][i] == 0)
				dfs(n - 1, i);
		}
		for (int i = 0; i < n; i++)
		{
			if (arr[i][0] == 0)
				dfs(i, 0);
			if (arr[i][x - 1] == 0)
				dfs(i, x - 1);
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < x; j++)
			{
				if (arr[i][j] == 1)
				{
					dfs(i, j, cnt);
					cnt++;
				}
			}
		}
		for (int i = 2; i < cnt; i++)
		{
			mpp[i] = 0;
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < x; j++)
			{
				if (arr[i][j] == 0)
				{
					cnt = -1;
					dfs2(i, j, cnt);
					mpp[cnt]++;
				}
			}
		}
		cout << "Case " << test++ << ": ";
		for (map<int, int>::iterator it = mpp.begin(); it != mpp.end(); it++)
		{
			if (it->second == 0)
				str.push_back('W');
			else if (it->second == 1)
				str.push_back('A');

			else if (it->second == 2)
				str.push_back('K');
			else if (it->second == 3)
				str.push_back('J');

			else if (it->second == 4)
				str.push_back('S');
			else if (it->second == 5)
				str.push_back('D');
		}
		sort(all(str));
		cout << str;
		str.clear();
		cout << '\n';
		mpp.clear();
	}
	
	return 0;
}