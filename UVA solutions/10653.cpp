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

int adj[1000][1000], vis[1000][1000];
int srcR, srcC, distR, distC, n, m;
priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>>pq;
bool valid(int r, int c)
{
	return (r >= 0 && r < n && c >= 0 && c < m);
}
void fill_()
{
	for (int i = 0; i < 1000; i++)
		for (int j = 0; j < 1000; j++)
			vis[i][j] = OO;
}
int solve()
{
	while (!pq.empty())
		pq.pop();
	pair<int, pair<int, int>>v;
	fill_();
	vis[srcR][srcC] = 0;
	int u, a, b;
	pq.push(MP(0, MP(srcR, srcC)));
	while (!pq.empty())
	{
		v = pq.top();
		pq.pop();
		if (v.second.first == distR && v.second.second == distC)
			return v.first;
		if (v.first > vis[v.second.first][v.second.second])
			continue;
		for (int i = 0; i < 4; i++)
		{
			a = dx[i] + v.second.first;
			b = dy[i] + v.second.second;
			if (!valid(a, b) || adj[a][b] == 1)
				continue;
			if (v.first + 1 < vis[a][b])
				pq.push(MP(v.first + 1, MP(a, b))), vis[a][b] = v.first + 1;
		}
	}
}

int main(){

	Qalbaz();

	int k, u, v, x;
	while (cin >> n >> m && n)
	{
		cin >> k;
		while (k--)
		{
			cin >> u >> v;
			for (int i = 0; i < v; i++)
			{
				cin >> x;
				adj[u][x] = 1;
			}
		}
		cin >> srcR >> srcC >> distR >> distC;
		int ans = solve();
		cout << ans << "\n";
		memset(adj, 0, sizeof adj);
	}

	return 0;
}