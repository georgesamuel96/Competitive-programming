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
#include<iterator>
#include<cctype>

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

//#pragma warning (disable : 4996)
void fast()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	//ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(8);
}
vector<vector<pair<int, int>>> adj;
vi vec;
int dist[1001][101];
int solve(int c, int src, int dis)
{
	priority_queue<pair<int, pair<int, int>>> pq;
	pq.push({ 0, { 0, -src } });
	for (int i = 0; i < 1001; i++)
		for (int j = 0; j < 101; j++)
			dist[i][j] = 1e9;
	dist[src][0] = 0;
	int w, gas, node, newGas;
	pair<int, int> v;
	while (!pq.empty())
	{
		w = -pq.top().first;
		gas = -pq.top().second.first;
		node = -pq.top().second.second;
		pq.pop();
		if (node == dis)
			return w;
		if (w > dist[node][gas])
			continue;
		if (gas + 1 <= c && dist[node][gas + 1] > w + vec[node])
		{
			dist[node][gas + 1] = w + vec[node];
			pq.push({ -dist[node][gas + 1], { -(gas + 1), -node } });
		}
		for (int i = 0; i < adj[node].size(); i++)
		{
			v = adj[node][i];
			if (gas >= v.second)
			{
				newGas = gas - v.second;
				if (dist[v.first][newGas] > w)
				{
					dist[v.first][newGas] = w;
					pq.push({ -dist[v.first][newGas], { -newGas, -v.first } });
				}
			}
		}
	}
	return dist[dis][0];
}
int main(){

	fast();

	int n, m, u, v, w, q, c;
	scanf("%d%d", &n, &m);
	adj.resize(n);
	vec.resize(n);
	for (int i = 0; i < n; i++)
		scanf("%d", &vec[i]);
	for (int i = 0; i < m; i++)
	{
		scanf("%d%d%d", &u, &v, &w);
		adj[u].push_back({ v, w });
		adj[v].push_back({ u, w });
	}
	scanf("%d", &q);
	while (q--)
	{
		scanf("%d%d%d", &c, &u, &v);
		w = solve(c, u, v);
		if (w == 1e9)
			printf("impossible\n");
		else
			printf("%d\n", w);
	}

	return 0;
}