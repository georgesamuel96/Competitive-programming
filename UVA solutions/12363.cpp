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
vector<vi>adj;
vi dfn, low, parent, vec;
int cnt;
vector<pair<int, int>>bridge;
void dfs(int u, int par)
{
	low[u] = dfn[u] = ++cnt;
	for (int i = 0; i < adj[u].size(); i++)
	{
		int v = adj[u][i];
		if (v == par)
			continue;
		if (dfn[v] == -1)
		{
			dfs(v, u);
			low[u] = min(low[u], low[v]);

			if (low[v] > dfn[u])
				bridge.push_back(MP(u, v));
		}
		else
			low[u] = min(low[u], dfn[v]);
	}
}
int find_parent(int x)
{
	if (parent[x] == x)
		return x;
	return parent[x] = find_parent(parent[x]);
}
void link(int x, int y)
{
	if (vec[x] > vec[y])
		swap(x, y);
	parent[x] = y;
	if (vec[x] == vec[y])
		vec[y]++;
}
void DSU(int x, int y)
{
	x = find_parent(x), y = find_parent(y);
	if (x != y)
	{
		link(x, y);
	}
}
int main(){

	Qalbaz();

	int n, m, q, u, v;
	while (cin >> n >> m >> q && n)
	{
		adj.clear();
		adj.resize(n + 1);
		for (int i = 0; i < m; i++)
		{
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		dfn.clear(), low.clear();
		dfn.resize(n + 1, -1);
		low = dfn;
		cnt = 0;
		parent.clear();
		parent.resize(n + 1);
		bridge.clear();
		vec.clear();
		vec = parent;
		for (int i = 1; i <= n; i++)
		{
			if (dfn[i] == -1)
				dfs(i, i);
		}
		for (int i = 1; i <= n; i++)
		{
			vec[i] = 1;
				parent[i] = i;
		}
		for (int i = 0; i < bridge.size(); i++)
		{
			DSU(bridge[i].first, bridge[i].second);
		}
		for (int i = 0; i < q; i++)
		{
			cin >> u >> v;
			if (find_parent(u) == find_parent(v))
				cout << "Y\n";
			else
				cout << "N\n";
		}
		cout << "-\n";
	}

	return 0;
}