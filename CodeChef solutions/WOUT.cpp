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

ll n, k;
vl vec;

int main(){

	Qalbaz();

	int t, l, r;
	cin >> t;
	ll ans, sum;
	while (t--)
	{
		vec.clear();
		cin >> n >> k;
		vec.resize(n + 1);
		for (int i = 0; i < n; i++)
		{
			cin >> l >> r;
			vec[l]++, vec[r + 1]--;
		}
		for (int i = 1; i < n; i++)
		{
			vec[i] = vec[i - 1] + vec[i];
		}
		ans = 0;
		for (int i = 0; i < k; i++)
		{
			ans = ans + vec[i];
		}
		sum = ans;
		l = 0;
		for (int i = k; i < n; i++)
		{
			sum -= vec[l];
			sum += vec[i];
			ans = max(ans, sum);
			l++;
		}
		ans = n * k - ans;
		cout << ans << "\n";
	}

	return 0;
}