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
stack<int>st;
vi vis, vec;
vector<vi>adj;
void dfs(int u)
{
	vis[u] = 1;
	for (int i = 0; i < adj[u].size(); i++)
	{
		int v = adj[u][i];
		if (vis[v] == 0)
			dfs(v);
	}
	st.push(u);
}
void dfs2(int u)
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

	int t, n, m, u, v, cnt;
	cin >> t;
	while (t--)
	{
		cin >> n >> m;
		adj.clear();
		adj.resize(n + 1);
		while (m--)
		{
			cin >> u >> v;
			adj[u].push_back(v);
		}
		vis.clear();
		vis.resize(n + 1);
		for (int i = 1; i <= n; i++)
		{
			if (vis[i] == 0)
				dfs(i);
		}
		fill(all(vis), 0);
		cnt = 0;
		vec.clear();
		while (st.size() > 0)
		{
			vec.push_back(st.top());
			st.pop();
		}
		for (int i = 0; i < n; i++)
		{
			if (vis[vec[i]] == 0)
				dfs2(vec[i]), cnt++;
		}
		cout << cnt << "\n";
	}

	return 0;
}