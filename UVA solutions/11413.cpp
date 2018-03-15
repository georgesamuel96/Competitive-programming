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
//#pragma warning (disable : 4996)
void Qalbaz()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(7);
}

vl vec;
bool check(ll mid, int m)
{
	ll ans = 1, ss = 0;
	for (int i = 0; i < vec.size(); i++)
	{
		if (ss + vec[i] <= mid)
			ss = ss + vec[i];
		else if (ans + 1 <= m)
			ss = 0, ans++, i--;
		else
			return false;
	}
	if (ans <= m)
		return true;
	return false;
}
int main(){

	Qalbaz();

	int n, m;
	ll lo, hi, mid, z;
	while (cin >> n >> m)
	{
		vec.resize(n);
		for (int i = 0; i < n; i++)
			cin >> vec[i];
		lo = 1, hi = 1e10;
		while (lo <= hi)
		{
			mid = (lo + hi) / 2;
			if (check(mid, m))
			{
				hi = mid - 1;
				z = mid;
			}
			else
				lo = mid + 1;
		}
		cout << z << "\n";
	}

	return 0;
}