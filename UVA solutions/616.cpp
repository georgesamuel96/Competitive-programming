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
	cout << fixed << setprecision(3);
}

bool solve(int n, int x)
{
	int y = 0;
	while (n && y < x)
	{
		if ((n - 1) % x == 0)
		{
			n -= 1;
			n = n - (n / x);
			y++;
		}
		else
			return false;
	}
	if (n % x == 0)
		return true;
	return false;
}
int main(){

	Qalbaz();

	int n;
	vi vec;
	while (cin >> n && n >= 0)
	{
		int i;
		vec.clear();
		n--;
		for (i = 1; i * i < n; i++)
		{
			if (n % i == 0)
				vec.push_back(n / i), vec.push_back(i);
		}
		if (i * i == n)
			vec.push_back(i);
		sort(all(vec));
		for (i = vec.size() - 1; i > 0; i--)
		{
			if (solve(n + 1, vec[i]))
			{
				cout << n + 1 << " coconuts, " << vec[i] << " people and 1 monkey\n";
				break;
			}
		}
		if (i <= 0)
			cout << n + 1 << " coconuts, no solution\n";
	}

	return 0;
}