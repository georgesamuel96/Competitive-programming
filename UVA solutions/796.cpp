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
	cout << fixed << setprecision(3);
}
vector<vi>adj;
vi dfn, low, parent, vis;
int cnt;
vector<pair<int, int>>vec;
void dfs(int u)
{
	vis[u] = 1;
	dfn[u] = low[u] = ++cnt;
	for (int i = 0; i < adj[u].size(); i++)
	{
		int v = adj[u][i];
		if (!vis[v])
		{
			parent[v] = u;
			dfs(v);
			low[u] = min(low[u], low[v]);
			if (low[v] > dfn[u])
				vec.push_back(MP(min(u, v), max(u, v)));
		}
		else if (v != parent[u])
			low[u] = min(low[u], dfn[v]);
	}
}
int main(){

	Qalbaz();

	int n, node, number, m;
	char ch;
	while (cin >> n)
	{
		adj.clear();
		adj.resize(n);
		for (int i = 0; i < n; i++)
		{
			cin >> node >> ch >> number >> ch;
			for (int j = 0; j < number; j++)
			{
				cin >> m;
				adj[node].push_back(m);
				adj[m].push_back(node);
			}
		}
		vec.clear();
		vis.clear();
		vis.resize(n);
		parent = dfn = low = vis;
		cnt = 0;
		for (int i = 0; i < n; i++)
		{
			if (vis[i] == 0)
			{
				dfs(i);
			}
		}
		sort(all(vec));
		cout << (int)vec.size() << " critical links\n";
		for (int i = 0; i < vec.size(); i++)
			cout << vec[i].first << " - " << vec[i].second << "\n";
		cout << "\n";
	}

	return 0;
}