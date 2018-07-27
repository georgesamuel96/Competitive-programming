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
int arr[10000000 + 1];
vl vec, vv;
bool isPrime(ll num)
{
	for (ll i = 0; i < vec.size() && vec[i] * vec[i] <= num; i++)
	{
		if (num % vec[i] == 0)
			return false;
	}
	return true;
}
int solve1(ll num)
{
	int lo = 0, hi = vv.size() - 1, z = -1, mid;
	while (lo <= hi)
	{
		mid = (lo + hi) / 2;
		if (vv[mid] >= num)
			hi = mid - 1, z = mid;
		else
			lo = mid + 1;
	}
	return z;
}
int solve2(ll num)
{
	int lo = 0, hi = vv.size() - 1, z = -1, mid;
	while (lo <= hi)
	{
		mid = (lo + hi) / 2;
		if (vv[mid] <= num)
			lo = mid + 1, z = mid;
		else
			hi = mid - 1;
	}
	return z;
}
int main(){

	Qalbaz();

	ll n, m;	
	ll x, y, a, b, mn, mx;
	arr[0] = arr[1] = 1;
	for (ll i = 2; i * i <= 1e7; i++)
	{	
		for (ll j = i * i; j <= 1e7; j+=i)
		{
			arr[j] = 1;
		}
	}
	for (int i = 2; i < 1e7 + 1; i++)
		if (arr[i] == 0)
			vec.push_back(i);
	int c;
	while (cin >> n >> m)
	{
		vv.clear();
		c = 0;
		if (n <= 1e7 && m <= 1e7)
		{
			for (int i = n; i <= m; i++)
				if (arr[i] == 0)
					vv.push_back(i);
		}
		else
		{
			for (ll i = n; i <= m; i++)
			{
				if ((i <= 1e7 && arr[i] == 0) || isPrime(i))
					vv.push_back(i);
			}
		}
		int ind1 = solve1(n), ind2 = solve2(m);
		if (vv[ind1] > m || ind2 - ind1 < 1 || vv[ind2] < n)
		{
			cout << "There are no adjacent primes.\n";
			continue;
		}
		mn = 1e18, mx = -1;
		x = y = 0;
		for (int i = ind1; i < ind2; i++)
		{
			if (vv[i + 1] - vv[i] < mn)
				mn = vv[i + 1] - vv[i], a = vv[i], b = vv[i + 1];
			if (vv[i + 1] - vv[i] > mx)
				mx = vv[i + 1] - vv[i], x = vv[i], y = vv[i + 1];
		}
		cout << a << "," << b << " are closest, " << x << "," << y << " are most distant.\n";
	}

	return 0;
}