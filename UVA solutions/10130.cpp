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
	cout << fixed << setprecision(3);
}
vector<pair<int, int>>vec;
int dp[1000][31];
int solve(int i, int m)
{
	if (i == vec.size())
		return 0;
	int &ret = dp[i][m];
	if (ret != -1)
		return ret;
	ret = 0;
	if (m - vec[i].second >= 0)
		ret = max(ret, solve(i + 1, m - vec[i].second) + vec[i].first);
	ret = max(ret, solve(i + 1, m));
	return ret;
}
int main(){

	Qalbaz();

	int t, n, m, ans;
	cin >> t;
	while (t--)
	{
		cin >> n;
		ans = 0;
		vec.resize(n);
		for (int i = 0; i < n; i++)
			cin >> vec[i].first >> vec[i].second;
		cin >> m;
		while (m--)
		{
			cin >> n;
			memset(dp, -1, sizeof dp);
			ans = ans + solve(0, n);
		}
		cout << ans << "\n";
	}

	return 0;
}