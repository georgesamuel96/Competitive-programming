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

int n, m;
bool valid(int r, int c)
{
	return (r >= 0 && r < n && c >= 0 && c < m);
}
int arr[1000][1000], vis[1000][1000];
priority_queue < pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>>pq;
void fill_()
{
	for (int i = 0; i < 1000; i++)
		for (int j = 0; j < 1000; j++)
			vis[i][j] = OO;
}
int solve(int i, int j)
{
	while (!pq.empty())
		pq.pop();
	pq.push(MP(arr[0][0], MP(0, 0)));
	fill_();
	vis[0][0] = arr[0][0];
	
	int a, b;
	pair<int, pair<int, int>> v;
	while (!pq.empty())
	{
		v = pq.top();
		pq.pop();
		if (v.second.first == n - 1 && v.second.second == m - 1)
			return v.first;
		if (v.first > vis[v.second.first][v.second.second])
			continue;
		for (int i = 0; i < 4; i++)
		{
			a = dx[i] + v.second.first;
			b = dy[i] + v.second.second;
			if (!valid(a, b))
				continue;
			if (v.first + arr[a][b] < vis[a][b])
			{
				pq.push(MP(v.first + arr[a][b], MP(a, b)));
				vis[a][b] = v.first + arr[a][b];
			}
		}
	}
}

int main(){

	Qalbaz();

	int t;
	cin >> t;
	while (t--)
	{
		cin >> n >> m;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				cin >> arr[i][j];
		int ans = solve(0, 0);
		cout << ans << "\n";
	}

	return 0;
}