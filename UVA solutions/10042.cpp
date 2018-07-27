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
int n;
map<int, int>mp;
int sum(int num)
{
	int c = 0;
	while (num)
	{
		c = c + num % 10;
		num = num / 10;
	}
	return c;
}
bool solve()
{
	mp.clear();
	ll x = n;
	for (int i = 2; i*i <= x; i++)
	{
		while (x % i == 0)
			mp[i]++, x /= i;
	}
	if (x > 1)
		mp[x]++;
	int y = sum(n);
	x = 0;
	for (auto it : mp)
	{
		x = x + sum(it.first) * it.second;
	}
	if (y == x)
		return true;
	return false;
}
bool isPrime()
{
	if (n == 2)
		return true;
	if (n % 2 == 0)
		return false;
	for (int i = 3; i*i <= n; i += 2)
		if (n % i == 0)
			return false;
	return true;
}
int main(){

	Qalbaz();

	int t;
	cin >> t;
	while (t--)
	{
		cin >> n;
		n++;
		while (isPrime() || !solve())
			n++;
		cout << n << "\n";

	}
	
	return 0;
}