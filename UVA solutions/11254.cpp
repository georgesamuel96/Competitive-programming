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
vi vec;
bool check(int x, int y, int n)
{
	if ((x * (x + 1)) % 2 == 0 && (y * (y - 1)) % 2 == 0)
	{
		x = (x * (x + 1)) / 2;
		y = (y * (y - 1)) / 2;
		int ans = x - y;
		if (x >= y && ans == n)
			return true;
		return false;
	}
	return false;
}
int main(){

	Qalbaz();

	int n, x, y, a, b, ansX, ansY;
	while (cin >> n && n > -1)
	{
		n = n * 2;
		ansX = n / 2, ansY = n / 2;
		for (int i = 1; i * i <= n; i++)
		{
			if (n % i == 0)
			{
				a = n / i, b = i;
				if ((a - b + 1) % 2 != 0 || (a + b - 1) % 2 != 0)
					continue;
				x = a - b + 1;
				y = a + b - 1;
				x /= 2;
				y /= 2;
				if (y - x + 1 > ansY - ansX + 1)
					ansY = y, ansX = x;
			}
			
		}
		cout << n / 2 << " = " << ansX << " + ... + " << ansY << "\n";
	}

	return 0;
}