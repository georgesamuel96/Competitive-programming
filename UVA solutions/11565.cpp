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
#define PI 3.14159265359
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
	cout << fixed << setprecision(9);
}
int a, b, c;
bool valid(int x, int y, int z)
{
	if (!(x * x + y * y + z * z == c))
		return false;
	if (!(x * y * z == b))
		return false;
	if (x == y || x == z || y == z)
		return false;
	return true;
}
int main(){

	Qalbaz();

	int n;
	cin >> n;
	int x, y, z;
	bool f;
	while (n--)
	{
		cin >> a >> b >> c;
		f = false;
		for (int i = -100; i <= 100 && !f; i++)
		{
			x = i;
			for (int j = -100; j <= 100; j++)
			{
				y = j;
				z = a - (x + y);
				if (x == 1 && y == 2)
					int zz = 0;
				if (valid(x, y, z))
				{
					f = true;
					break;
				}
			}
		}
		if (f)
			cout << x << " " << y << " " << z << "\n";
		else
			cout << "No solution.\n";
	}

	return 0;
}