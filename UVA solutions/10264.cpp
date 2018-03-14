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

int power(int base, int P)
{
	if (P == 0)
		return 1;
	if (P == 1)
		return base;
	if (P % 2)
		return base * power(base, P - 1);
	int c1 = power(base, P / 2);
	return c1 * c1;
}

int main(){

	Qalbaz();

	int n, edges;
	vi vec, vv;
	int sum, ans;
	while (cin >> n)
	{
		ans = 0;
		edges = power(2, n);
		vec.resize(edges), vv.resize(edges);
		for (int i = 0; i < edges; i++)
		{
			cin >> vec[i];
		}
		for (int i = 0; i < edges; i++)
		{
			sum = 0;
			for (int j = 0; j < n; j++)
			{
				int b = i ^ (1 << j);
				sum += vec[b];
			}
			vv[i] = sum;
		}
		for (int i = 0; i < edges; i++)
		{
			sum = vv[i];
			for (int j = 0; j < n; j++)
			{
				int b = i ^ (1 << j);
				sum += vv[b];
				ans = max(ans, sum);
				sum -= vv[b];
			}
		}
		cout << ans << "\n";
		vv.clear();
		vec.clear();
	}

	return 0;
}