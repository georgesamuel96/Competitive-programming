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
	cout << fixed << setprecision(9);
}
bool vis[20], vis2[20];
int arr[20];
int m, n, ans;
void solve(int i, int sum)
{
	if (i == m)
		return;
	if (sum + arr[i] <= n)
	{
		vis[i] = true;
		if (sum + arr[i] > ans)
		{
			for (int j = 0; j < 20; j++)
				vis2[j] = vis[j];
			ans = sum + arr[i];
		}
		solve(i + 1, sum + arr[i]);
		vis[i] = false;
	}
	solve(i + 1, sum);
}

int main(){

	Qalbaz();

	while (cin >> n >> m)
	{
		for (int i = 0; i < m; i++)
			cin >> arr[i];
		memset(vis, false, sizeof vis);
		ans = 0;
		solve(0, 0);
		for (int i = 0; i < 20; i++)
			if (vis2[i])
				cout << arr[i] << " ";
		cout << "sum:" << ans << "\n";
		memset(arr, 0, sizeof arr);
	}

	return 0;
}