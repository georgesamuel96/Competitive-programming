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

string convert_(int n)
{
	string str = "";
	int re;
	char c;
	while (n)
	{
		re = n % 2;
		n /= 2;
		c = re + '0';
		str = str + c;
	}
	reverse(all(str));
	return str;
}

void solve(int n, int &a, int &b)
{
	string str = convert_(n), s_a, s_b;
	s_a.resize(str.size(), '0');
	s_b = s_a;
	int z = 0;
	for (int i = str.size() - 1; i >=  0; i--)
	{
		if(str[i] == '1')
		{
			if (z == 0)
				s_a[i] = '1';
			else
				s_b[i] = '1';
			z = 1 - z;
		}
	}
	for (int i = 0; i < str.size(); i++)
	{
		a = a * 2 + (s_a[i] - '0');
		b = b * 2 + (s_b[i] - '0');
	}
}

int main(){

	Qalbaz();

	int n;
	int a, b;
	while (cin >> n)
	{
		if (n == 0)
			break;
		a = b = 0;
		solve(n, a, b);
		cout << a << " " << b << "\n";
	}

	return 0;
}