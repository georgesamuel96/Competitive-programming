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
vector<vector<pair<int, int>>>adj;
priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>>pq;
int dist[101][101];
int dijkstra(int n, int e, int time)
{
	for (int i = 0; i < 101; i++)
		for (int j = 0; j < 101; j++)
			dist[i][j] = OO;
	for (int i = 1; i <= n; i++)
	{
		pq.push(MP(0, MP(i, i)));
		dist[i][i] = 0;
	}
	int d, u, cell;
	set<int>st;
	pair<int, int>v;
	while (!pq.empty())
	{
		d = pq.top().first;
		u = pq.top().second.first, cell = pq.top().second.second;
		pq.pop();
		if (u == e)
		{
			st.insert(cell);
			continue;
		}
		if (d > dist[u][cell])
			continue;
		for (int i = 0; i < adj[u].size(); i++)
		{
			v = adj[u][i];
			if (d + v.second < dist[v.first][cell] && d + v.second <= time)
			{
				dist[v.first][cell] = d + v.second;
				pq.push(MP(dist[v.first][cell], MP(v.first, cell)));
			}
		}
	}
	return (int)st.size();
}
int main(){

	Qalbaz();

	int t, n, e, time, m, u, v, ff = 0, w;
	cin >> t;
	while (t--)
	{
		if (ff > 0)
			cout << "\n";
		ff = 1;
		cin >> n >> e >> time >> m;
		adj.clear();
		adj.resize(n + 1);
		for (int i = 0; i < m; i++)
		{
			cin >> u >> v >> w;
			adj[u].push_back(MP(v, w));
		}
		int ans = dijkstra(n, e, time);
		cout << ans << "\n";
	}

	return 0;
}