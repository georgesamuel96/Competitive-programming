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

struct str
{
	int x, y, z;
};

int main(){

	Qalbaz();

	int n, m;
	vi b;
	int x, y, z;
	vector<str>vv;
	bool f;
	while (cin >> n >> m && m)
	{
		b.resize(n + 1);
		for (int i = 1; i <= n; i++)
			cin >> b[i];
		for (int i = 0; i < m; i++)
		{
			cin >> x >> y >> z;
			vv.push_back({ x, y, z });
			b[y] += z;
		}
		f = 1;
		for (int i = 0; f && i < m; i++)
		{
			b[vv[i].x] -= vv[i].z;
			if (b[vv[i].x] < 0)
				f = 0;
		}
		if (f)
			cout << "S\n";
		else
			cout << "N\n";
		b.clear(), vv.clear();
	}

	return 0;
}