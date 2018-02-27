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
const ll mod = 1000000007;
const ll OO = (ll)1e18;
const int dx[] = { 0, 1, -1, 0, 1, -1, 1, -1 };
const int dy[] = { 1, 0, 0, -1, 1, -1, -1, 1 };
ll gcd(ll a, ll b){ if (b == 0){ return a; }return gcd(b, a % b); }
ll fast_power(double base, ll power){
	if (power == 1) return base;
	if (power % 2 == 0) return fast_power((base*base), power / 2);
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
	cout << fixed << setprecision(2);
}
 
vector<vector<pair<int, int>>>adj;
vector<pair<int, pair<int, int>>>edges;
vi taken;
map<pair<int, pair<int, int>>, bool>path;
priority_queue<pair<int, pair<int, int>>>pq;
void process(int node)
{
	taken[node] = 1;
	for (int i = 0; i < adj[node].size(); i++)
	{
		if (taken[adj[node][i].first] == 0)
		{
			pq.push(MP(adj[node][i].second, MP(node, adj[node][i].first)));
		}
	}
}
 
queue<pair<int, int>>q;
vi vis;
int bfs(int src, int dist)
{
	q.push(MP(src, 1e8));
	int v, w, mn = 1e8;
	vis[src] = 1;
	while (!q.empty())
	{
		v = q.front().first, w = q.front().second, q.pop();
		if (v == dist)
		{
			mn = min(mn, w);
			continue;
		}
		for (int i = 0; i < adj[v].size(); i++)
		{
			if (vis[adj[v][i].first] == 0 && path[MP(adj[v][i].second, MP(v, adj[v][i].first))] == true)
				vis[adj[v][i].first] = 1, q.push(MP(adj[v][i].first, min(w, adj[v][i].second)));
		}
	}
	return mn;
}
 
int main(){
 
	Qalbaz();
 
	int n, m, u, v, w, src, dist, tst, test = 0;
	int from, to;
	while (cin >> n >> m)
	{
		if (n == 0)
			break;
		adj.clear();
		adj.resize(n);
		taken.clear();
		taken.resize(n);
		edges.clear();
		vis.clear(), vis.resize(n);
		path.clear();
		for (int i = 0; i < m; i++)
		{
			cin >> u >> v >> w;
			u--, v--;
			adj[u].push_back(MP(v, w));
			adj[v].push_back(MP(u, w));
			edges.push_back(MP(w, MP(u, v)));
		}
		cin >> src >> dist >> tst;
		sort(all(edges));
		process(edges[m - 1].second.first);
		while (!pq.empty())
		{
			w = pq.top().first, from = pq.top().second.first, to = pq.top().second.second, pq.pop();
			if (taken[to] == 0)
			{
				path[MP(w, MP(from, to))] = true;
				path[MP(w, MP(to, from))] = true;
				process(to);
			}
		}
		src--, dist--;
		int ans = bfs(src, dist);
		cout << "Scenario #" << ++test << "\nMinimum Number of Trips = ";
		ans--;
		if (tst % ans == 0)
			ans = tst / ans;
		else
			ans = tst / ans + 1;
		cout << ans << "\n\n";
 
	}
 
	return 0;
}