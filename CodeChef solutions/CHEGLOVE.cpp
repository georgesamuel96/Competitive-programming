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

int main(){

	Qalbaz();

	int t, n;
	cin >> t;
	vl vec, vv, ans;
	while (t--)
	{
		cin >> n;
		vec.clear(), vv.clear();
		vec.resize(n), vv.resize(n);
		for (int i = 0; i < n; i++)
			cin >> vec[i];
		for (int i = 0; i < n; i++)
			cin >> vv[i];
		int x = 0;
		ans.clear();
		ans.resize(3);
		for (int i = 0; i < n; i++)
		{
			if (vec[i] <= vv[i])
				x++;
		}
		if (x == n)
			ans[0] = 1;
		x = 0;
		for (int i = n - 1, j = 0; i >= 0; i--, j++)
		{
			if (vec[i] <= vv[j])
				x++;
		}
		if (x == n)
			ans[1] = 1;
		if (ans[0] == ans[1] && ans[1] == 1)
			cout << "both\n";
		else if (ans[0] == 1)
			cout << "front\n";
		else if (ans[1] == 1)
			cout << "back\n";
		else
			cout << "none\n";
	}

	return 0;
}