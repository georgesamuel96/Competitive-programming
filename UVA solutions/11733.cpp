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

vector<vector<pair<int, ll>>>adj;
vector<pair<ll, pair<int, int>>>edge;

struct  dsu
{
	vi parent, rank;
	int forest;

	dsu(int n)
	{
		parent.resize(n), rank.resize(n);
		for (int i = 0; i < n; i++)
			parent[i] = i, rank[i] = 1;
	}

	int findSet(int x)
	{
		if (parent[x] == x)
			return x;
		return parent[x] = findSet(parent[x]);
	}

	void link(int x, int y)
	{
		if (rank[x] > rank[y])
			swap(x, y);
		parent[x] = y;
		if (rank[x] == rank[y])
			rank[y]++;
	}

};

int main(){

	Qalbaz();

	int t, n, m, u, v, ind, nodes, y;
	ll airport, w, ans, cnt;
	cin >> t;
	int test = 0;
	pair<ll, int>nd;
	while (t--)
	{
		cin >> n >> m >> airport;
		adj.clear(), edge.clear();
		adj.resize(n);
		cout << "Case #" << ++test << ": ";
		for (int i = 0; i < m; i++)
		{
			cin >> u >> v >> w;
			u--, v--;
			adj[u].push_back(MP(v, w));
			adj[v].push_back(MP(u, w));
			edge.push_back(MP(w, MP(u, v)));
		}
		dsu DSU(n);
		ans = 0, cnt = 0;
		sort(all(edge));
		for (int i = 0; i < m; i++)
		{
			if (edge[i].first >= airport)
				break;
			u = DSU.findSet(edge[i].second.first);
			v = DSU.findSet(edge[i].second.second);
			if (u != v)
			{
				DSU.link(u, v);
				cnt++;
				ans += edge[i].first;
			}
			if (cnt == n - 1)
				break;
		}
		cout << ans + (n - cnt) * airport << " " << n - cnt << "\n";
	}

	return 0;
}