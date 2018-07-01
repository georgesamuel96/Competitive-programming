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
vi vec, vis, dfn, ap, low, parent;
vector<vi>adj;
int cnt;
void dfs(int u, int par)
{
	int child = 0;
	vis[u] = 1;
	dfn[u] = low[u] = ++cnt;
	for (int i = 0; i < adj[u].size(); i++)
	{
		int v = adj[u][i];
		if (!vis[v])
		{
			child++;
			parent[v] = u;
			dfs(v, u);
			low[u] = min(low[u], low[v]);
			if (parent[u] == 0 && child > 1)
				ap[u] = 1;
			if (parent[u] != 0 && low[v] >= dfn[u])
				ap[u] = 1;
		}
		else if (v != parent[u])
			low[u] = min(low[u], dfn[v]);
	}
}
int main(){

	Qalbaz();

	string str, num;
	int n;
	while (getline(cin, str))
	{
		if (str[0] == '0')
			break;
		n = stoi(str);
		adj.resize(n + 1);
		while (getline(cin, str))
		{
			if (str[0] == '0')
				break;
			stringstream ss;
			ss << str;
			while (ss >> num)
			{
				vec.push_back(stoi(num));
			}
			for (int i = 1; i < vec.size(); i++)
			{
				adj[vec[0]].push_back(vec[i]);
				adj[vec[i]].push_back(vec[0]);
			}
			vec.clear();
		}
		vec.clear();
		vec.resize(n + 1);
		vis = dfn = low = ap = parent = vec;
		for (int i = 1; i <= n; i++)
		{
			if (vis[i] == 0)
			{
				dfs(i, 0);
			}
		}
		cnt = 0;
		for (int i = 1; i <= n; i++)
		{
			if (ap[i])
				cnt++;
		}
		cout << cnt << "\n";
		adj.clear();
		vec.clear();
	}

	return 0;
}