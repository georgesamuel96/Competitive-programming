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
vs vec;
map<string, int> dfn, low;
map<string, bool>ap, vis;
map<string, string>parent;
map<string, vs>adj;
int cnt;
void dfs(string u, string _parent)
{
	int child = 0;
	vis[u] = true;
	dfn[u] = low[u] = ++cnt;
	for (int i = 0; i < adj[u].size(); i++)
	{
		string v = adj[u][i];
		if (!vis[v])
		{
			child++;
			parent[v] = u;
			dfs(v, u);
			low[u] = min(low[u], low[v]);
			if (parent[u] == "" && child > 1)
				ap[u] = true;
			if (parent[u] != "" && low[v] >= dfn[u])
				ap[u] = true;
		}
		else if (v != parent[u])
			low[u] = min(low[u], dfn[v]);
	}
}
int main(){

	Qalbaz();

	string str, str1, str2;
	int n, test = 1, m;
	while (cin >> n)
	{
		if (n == 0)
			break;
		if (test > 1)
			cout << "\n";
		for (int i = 0; i < n; i++)
		{
			cin >> str;
			ap[str] = false;
		}
		cin >> m;
		for (int i = 0; i < m; i++)
		{
			cin >> str1 >> str2;
			adj[str1].push_back(str2);
			adj[str2].push_back(str1);
		}
		cnt = 0;
		for (auto it : ap)
		{
			if (!vis[it.first])
			{
				dfs(it.first, "");
			}
		}
		cnt = 0;
		for (auto it : ap)
		{
			if (it.second)
			{
				cnt++;
				vec.push_back(it.first);
			}
		}
		sort(all(vec));
		cout << "City map #" << test++ << ": " << cnt << " camera(s) found\n";
		for (int i = 0; i < cnt; i++)
			cout << vec[i] << "\n";

		vec.clear();
		dfn.clear(), low.clear();
		ap.clear(), vis.clear();
		parent.clear();
		adj.clear();
	}

	return 0;
}