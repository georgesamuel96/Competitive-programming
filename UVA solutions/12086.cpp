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
#include<iterator>

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
const ll OO = (ll)1e18;
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
	cout << fixed << setprecision(0);
}

vl vec, arr;
void build(int s, int e, int pos)
{
	if (s == e)
	{
		arr[pos] = vec[s];
		return;
	}
	int mid = (s + e) / 2;
	build(s, mid, pos * 2);
	build(mid + 1, e, pos * 2 + 1);
	arr[pos] = arr[pos * 2] + arr[pos * 2 + 1];
}
ll getNumber(int l, int r, int s, int e, int pos)
{
	if (s > e || s > r || e < l)
		return 0;
	if (s >= l && e <= r)
		return arr[pos];
	int mid = (s + e) / 2;
	ll x = getNumber(l, r, s, mid, pos * 2);
	ll y = getNumber(l, r, mid + 1, e, pos * 2 + 1);
	return (x + y);
}
void update(int kth, ll val, int s, int e, int pos)
{
	if (s == e)
	{
		arr[pos] = val;
		return;
	}
	int mid = (s + e) / 2;
	if (mid >= kth)
	{
		update(kth, val, s, mid, pos * 2);
	}
	else
	{
		update(kth, val, mid + 1, e, pos * 2 + 1);
	}
	arr[pos] = arr[pos * 2] + arr[pos * 2 + 1];
}
int main(){

	Qalbaz();

	int n, test = 1, x, sz;
	string str, ss1, ss2, ch;
	int y, l, r;
	while (getline(cin, str) && str[0] != '0')
	{
		if (test > 1)
			cout << "\n";
		n = stoi(str);
		vec.resize(n);
		for (int i = 0; i < n; i++)
		{
			getline(cin, str);
			vec[i] = stoi(str);
		}
		x = (int)(ceil(log(n) / log(2)));
		sz = 2 * (int)pow(2, x) - 1;
		arr.clear();
		arr.resize(sz + 1);
		build(0, n - 1, 1);
		cout << "Case " << test++ << ":\n";
		x = 0;
		while (getline(cin, str) && str != "END")
		{
			stringstream ss;
			ss << str;
			ss >> ch;
			ss >> ss1;
			ss >> ss2;
			l = stoi(ss1);
			r = stoi(ss2);
			if (ch == "S")
			{
				update(l - 1, r, 0, n - 1, 1);
			}
			else
			{
				y = getNumber(l - 1, r - 1, 0, n - 1, 1);
				cout << y << "\n";
			}
		}
	}

	return 0;
}
