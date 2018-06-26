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
#define EPS 1e-9
#define PI 3.14159265359
const ll mod = 1000000007;
const ll OO = (ll)1e9;
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
vi vis;
vector<vector<pair<int, int>>>adj;
priority_queue < pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
int solve(int src, int dist)
{
	while (!pq.empty())
		pq.pop();
	pq.push(MP(0, src));
	vis[src] = 0;
	pair<int, int>v, u;
	while (!pq.empty())
	{
		v = pq.top();
		pq.pop();
		if (v.second + 1 == dist)
			return v.first;
		if (v.first > vis[v.second])
			continue;
		for (int i = 0; i < adj[v.second].size(); i++)
		{
			u = adj[v.second][i];
			if (v.first + u.second < vis[u.first])
			{
				vis[u.first] = v.first + u.second;
				pq.push(MP(vis[u.first], u.first));
			}
		}
	}
	return OO;
}

int main(){

	Qalbaz();

	int t;
	cin >> t;
	int timer, e, u, v, m, n, ans, x;
	while (t--)
	{
		cin >> n >> e >> timer >> m;
		adj.clear();
		adj.resize(n);
		while (m--)
		{
			cin >> u >> v >> x;
			u--, v--;
			adj[u].push_back(MP(v, x));
		}
		ans = 0;
		for (int i = 0; i < n; i++)
		{
			vis.clear();
			vis.resize(n, OO);
			x = solve(i, e);
			if (x <= timer)
				ans++;
		}
		cout << ans << "\n";
		if (t)
			cout << "\n";
	}

	return 0;
}