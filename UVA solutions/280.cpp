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
#define EPS 1e-9
#define PI 3.14159265359
const ll mod = 1000000007;
const ll OO = (ll)1e18;
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
vector<vi>adj;
vi vis;
int dfs(int node, int f)
{
	int cnt = 0;
	if (f)
		vis[node] = 1, cnt = 1;
	else
		f = 1;
	for (int i = 0; i < adj[node].size(); i++)
	{
		int v = adj[node][i];
		if (vis[v] == 0)
		{
			cnt = cnt + dfs(v, f);
		}
	}
	return cnt;
}
int main(){

	Qalbaz();

	int n, m, x;
	while (cin >> n && n)
	{
		adj.clear();
		adj.resize(n + 1);
		while (cin >> m && m)
		{
			while (cin >> x && x)
			{
				adj[m].push_back(x);
			}
		}
		cin >> x;
		for (int i = 0; i < x; i++)
		{
			cin >> m;
			vis.clear();
			vis.resize(n + 1);
			m = dfs(m, 0);
			cout << n - m;
			for (int i = 0; i < n; i++)
			{
				if (vis[i + 1] == 0)
					cout << " " << i + 1;
			}
			cout << "\n";
		}
	}

	return 0;
}