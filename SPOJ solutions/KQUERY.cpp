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
	cout << fixed << setprecision(0);
}
vector<pair<int, int>>vec, vec2;
vector<pair<pair<int, int>, pair<int, int>>>vv;
vi arr;
void insert(int x, int s, int e, int pos)
{
	if (s == e)
	{
		arr[pos] = 1;
		return;
	}
	int mid = (s + e) / 2;
	if (mid >= x)
	{
		insert(x, s, mid, pos * 2);
	}
	else
	{
		insert(x, mid + 1, e, pos * 2 + 1);
	}
	arr[pos] = arr[pos * 2] + arr[pos * 2 + 1];
}
int getNumber(int l, int r, int s, int e, int pos)
{
	if (s > e || l > e || r < s)
		return 0;
	if (l <= s && r >= e)
		return arr[pos];
	int mid = (s + e) / 2;
	int x = getNumber(l, r, s, mid, pos * 2);
	int y = getNumber(l, r, mid + 1, e, pos * 2 + 1);
	return (x + y);
}
int main(){

	Qalbaz();

	int n;
	cin >> n;
	vec.resize(n);
	for (int i = 0; i < n; i++)
	{
		cin >> vec[i].first;
		vec[i].second = i;
	}
	sort(rall(vec));
	int m;
	cin >> m;
	vv.resize(m);
	for (int i = 0; i < m; i++)
	{
		cin >> vv[i].second.first >> vv[i].second.second >> vv[i].first.first;
		vv[i].first.second = i;
	}
	sort(rall(vv));
	int x = 0;
	x = (int)(ceil(log(n) / log(2)));
	int sz = 2 * (int)pow(2, x) - 1, y;
	arr.resize(sz + 1);
	x = 0;
	vec2.resize(m);
	for (int i = 0; i < m; i++)
	{
		while (vec[x].first > vv[i].first.first)
		{
			insert(vec[x].second, 0, n - 1, 1);
			x++;
		}
		y = getNumber(vv[i].second.first - 1, vv[i].second.second - 1, 0, n - 1, 1);
		vec2[i].first = vv[i].first.second;
		vec2[i].second = y;
	}
	sort(all(vec2));
	for (int i = 0; i < m; i++)
	{
		cout << vec2[i].second << "\n";
	}

	return 0;
}