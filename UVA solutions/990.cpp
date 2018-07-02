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
vector<pair<int, int>>vec, vec2;
int dp[31][1001], taken[31][1001];
int solve(int i, int t)
{
	if (i == vec.size())
		return 0;
	int &ret = dp[i][t];
	if (ret != -1)
		return ret;
	ret = 0;
	
	int a = 0, b;
	if (t - vec[i].first >= 0)
	{
		a = solve(i + 1, t - vec[i].first) + vec[i].second;
	}
	b = solve(i + 1, t);
	if (a > b)
		taken[i][t] = 1;
	ret = max(a, b);
	return ret;
}
vi vv;
void build(int i, int t)
{
	for (int i = 0; i < vec.size(); i++)
	{
		if (taken[i][t] == 1)
		{
			vv.push_back(i);
			t -= vec[i].first;
		}
	}
}
int main(){

	Qalbaz();

	int t, w, n, d, v, f = 0;
	while (cin >> t >> w)
	{
		if (f)
			cout << "\n";
		f = 1;
		cin >> n;
		vec.resize(n);
		vec2 = vec;
		for (int i = 0; i < n; i++)
		{
			cin >> d >> v;
			vec2[i].first = d, vec2[i].second = v;
			d = (d * w) + (2 * w * d);
			vec[i].first = d, vec[i].second = v;
		}
		memset(dp, -1, sizeof dp);
		int ans = solve(0, t);
		cout << ans << "\n";
		build(0, t);
		cout << (int)vv.size() << "\n";
		for (int i = 0; i < vv.size(); i++)
		{
			cout << vec2[vv[i]].first << " " << vec2[vv[i]].second << "\n";
		}
		vv.clear();
	}

	return 0;
}