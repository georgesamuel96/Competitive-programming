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
const ll OO = (ll)1e18;
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
ll dist[20000];
vector<vector<pair<int, ll>>>adj;
int n, m, src, dis;
priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>>pq;
ll dijkstra()
{
	for (int i = 0; i < 20000; i++)
		dist[i] = OO;
	dist[src] = 0;
	pq.push(MP(0, src));
	int d, u;
	pair<ll, int>v;
	while (!pq.empty())
	{
		d = pq.top().first;
		u = pq.top().second;
		pq.pop();
		if (d > dist[u])
			continue;
		for (int i = 0; i < adj[u].size(); i++)
		{
			v = adj[u][i];
			if (d + v.second < dist[v.first])
			{
				dist[v.first] = d + v.second;
				pq.push(MP(dist[v.first], v.first));
			}
		}
	}
	return dist[dis] != OO? dist[dis] : -1;
}
int main(){

	Qalbaz();

	int t, u, v, test = 1;
	ll w;
	cin >> t;
	while (t--)
	{
		cin >> n >> m >> src >> dis;
		adj.clear();
		adj.resize(n);
		for (int i = 0; i < m; i++)
		{
			cin >> u >> v >> w;
			adj[u].push_back(MP(v, w));
			adj[v].push_back(MP(u, w));
		}
		int ans = dijkstra();
		if (ans != -1)
		cout << "Case #" << test++ << ": " << ans << "\n";
		else
			cout << "Case #" << test++ << ": " << "unreachable" << "\n";
	}

	return 0;
}