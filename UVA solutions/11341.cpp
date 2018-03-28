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
	cout << fixed << setprecision(2);
}

int arr[10][100], dp[10][100];
int n, m;
int solve(int i, int s)
{
	if (i == n)
		return 0;
	if (s <= 0)
		return -1e9;
	int &ret = dp[i][s];
	if (ret != -1)
		return ret;
	ret = -1e9;
	for (int j = 0; j < m && j + 1 <= s; j++)
	{
		if (arr[i][j] >= 5)
			ret = max(ret, solve(i + 1, s - (j + 1)) + arr[i][j]);
	}
	return ret;
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
		memset(dp, -1, sizeof dp);
		double ans = solve(0, m) / n;
		if (ans >= 5.0)
			cout << "Maximal possible average mark - " << ans << ".\n";
		else
			cout << "Peter, you shouldn't have played billiard that much.\n";
	}

	return 0;
}