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
#include<functional>

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
#define rall(v) v.rbegin(),v.rend()
#define EPS 1e-9
#define PI 3.14159265359
const ll mod = 1000000007;
const ll OO = (ll)1e9;
const int dx[] = { 0, 1, 0, -1, 1, -1, 1, -1 };
const int dy[] = { 1, 0, -1, 0, 1, -1, -1, 1 };
ll gcd(ll a, ll b){ if (b == 0){ return a; }return gcd(b, a % b); }
ll fast_power(ll base, ll power){
	if (power == 0)
		return 1;
	if (power == 1)
		return (base % mod);
	if (power % 2 == 0)
		return (fast_power(((base*base) % mod), power / 2LL) % mod);
	else return ((base*fast_power(((base*base) % mod) % mod, power / 2LL)) % mod);
}
//#pragma warning (disable : 4996)
void Qalbaz()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(2);
}
vi dfn, low, parent;
int grid[1001][1001];
int cnt;
void dfs(int u, int n)
{
	low[u] = dfn[u] = cnt++;
	for (int i = 1; i <= n; i++)
	{
		if (grid[u][i])
		{
			if (dfn[i] == -1)
			{
				parent[i] = u;
				dfs(i, n);
				low[u] = min(low[u], low[i]);
				if (low[i] <= dfn[u])
					grid[i][u] = 0;
			}
			else if (i != parent[u])
			{
				low[u] = min(low[u], dfn[i]);
				grid[i][u] = 0;
			}
		}
		
	}
	
}
void _fill(int n)
{
	memset(grid, 0, sizeof grid);
	dfn.clear();
	low.clear();
	parent.clear();
	cnt = 1;
	low.resize(n + 1, -1);
	dfn = parent = low;
}
int main(){

	Qalbaz();

	int n, m, u, v, test = 1;
	while (cin >> n >> m && n)
	{
		cout << test++ << "\n\n";
		_fill(n);
		for (int i = 0; i < m; i++)
		{
			cin >> u >> v;
			grid[u][v] = 1;
			grid[v][u] = 1;
		}
		dfs(1, n);
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (grid[i][j])
					cout << i << " " << j << "\n";
			}
		}
		cout << "#\n";
	}

	return 0;
}