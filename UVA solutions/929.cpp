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
int arr[1000][1000], dist[1000][1000];
int n, m;
priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>>pq;
bool valid(int r, int c)
{
	return (r >= 0 && r < n && c >= 0 && c < m);
}
int dijkstra(int r, int c)
{
	pq.push(MP(arr[0][0], MP(r, c)));
	for (int i = 0; i < 1000; i++)
		for (int j = 0; j < 1000; j++)
			dist[i][j] = OO;
	dist[r][c] = arr[0][0];
	int d;
	while (pq.empty() == 0)
	{
		d = pq.top().first, r = pq.top().second.first, c = pq.top().second.second;
		pq.pop();
		if (d > dist[r][c])
			continue;
		for (int i = 0; i < 4; i++)
		{
			int a = dx[i] + r;
			int b = dy[i] + c;
			if (valid(a, b) && d + arr[a][b] < dist[a][b])
			{
				dist[a][b] = d + arr[a][b];
				pq.push(MP(dist[a][b], MP(a, b)));
			}
		}
	}
	return dist[n - 1][m - 1];
}
int main(){

	Qalbaz();

	int t;
	cin >> t;
	while (t--)
	{
		cin >> n >> m;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				cin >> arr[i][j];
			}
		}
		int ans = dijkstra(0, 0);
		cout << ans << "\n";
	}

	return 0;
}