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

int main(){

	Qalbaz();

	vi vec;
	int x = 1, y = 4, z = 0;
	while (x <= 1e7)
	{
		vec.push_back(x);
		if (z == 0)
			x++;
		else
			x += y, y += 4;
		z = 1 - z;
	}
	int n, lo, hi, mid, row, col, ans;
	while (cin >> n)
	{
		lo = 0, hi = vec.size() - 1, z = -1;
		while (lo <= hi)
		{
			mid = (lo + hi) / 2;
			if (mid % 2 == 0)
			{
				row = vec[mid] - mid;
				col = vec[mid];
			}
			else
			{
				row = vec[mid];
				col = vec[mid] + mid;
			}
			if (n <= col && n >= row)
			{
				z = mid;
				break;
			}
			if (vec[mid] < n)
				lo = mid + 1;
			else
				hi = mid - 1;
		}
		if (z % 2 == 0)
		{
			row = vec[z] - n + 1;
			col = z - (vec[z] - n) + 1;
		}
		else
		{
			row = n - vec[z] + 1;
			col = z - (n - vec[z]) + 1;
		}
		
		cout << "TERM " << n << " IS " << row << "/" << col << "\n";
	}

	return 0;
}