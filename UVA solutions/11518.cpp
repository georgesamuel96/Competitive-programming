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
vi vis;
void dfs(int u)
{
	vis[u] = 1;
	for (int i = 0; i < adj[u].size(); i++)
	{
		int v = adj[u][i];
		if (vis[v] == 0)
			dfs(v);
	}
}
int main(){

	Qalbaz();

	int t, n, m, l, u, v;
	cin >> t;
	while (t--)
	{
		cin >> n >> m >> l;
		adj.clear();
		adj.resize(n + 1);
		for (int i = 0; i < m; i++)
		{
			cin >> u >> v;
			adj[u].push_back(v);
		}
		vis.clear();
		vis.resize(n + 1);
		for (int i = 0; i < l; i++)
		{
			cin >> u;
			if (vis[u] == 0)
				dfs(u);
		}
		int cnt = 0;
		for (int i = 1; i < n + 1; i++)
		{
			cnt += vis[i];
		}
		cout << cnt << "\n";
	}

	return 0;
}