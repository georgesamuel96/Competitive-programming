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
vi vec;
ll dp[10000][101], k;
ll solve(int i, int rem)
{
	if (i == vec.size())
	{
		if (rem % k == 0)
			return 1;
		return 0;
	}
	ll &ret = dp[i][rem];
	if (ret != -1)
		return ret;
	ret = 0;
	ret = max(ret, solve(i + 1, (rem + vec[i]) % k));
	ret = max(ret, solve(i + 1, (rem - vec[i]) % k));
	return ret;
}
int main(){

	Qalbaz();

	int t, n;
	cin >> t;
	while (t--)
	{
		cin >> n >> k;
		vec.resize(n);
		for (int i = 0; i < n; i++)
		{
			cin >> vec[i];
			if (vec[i] < 0)
			{
				int y = vec[i] / k;
				y = abs(y);
				vec[i] = k * (y + 1) + vec[i];
			}
			vec[i] = vec[i] % k;
		}
		memset(dp, -1, sizeof dp);
		ll ans = solve(1, (vec[0] % k));
		if (ans > 0)
			cout << "Divisible\n";
		else
			cout << "Not divisible\n";
	}

	return 0;
}