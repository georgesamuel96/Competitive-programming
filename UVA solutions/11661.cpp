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
	cout << fixed << setprecision(2);
}



int main(){

	Qalbaz();

	int t;
	vector<pair<int, char>>vec;
	char c;
	bool f;
	int x, y, mn, prev;
	while (cin >> t)
	{
		if (t == 0)
			break;
		vec.clear();
		f = false;
		for (int i = 0; i < t; i++)
		{
			cin >> c;
			if (c == 'Z')
				f = true;
			else if (c != '.')
				vec.push_back(MP(i, c));
		}
		if (f)
			cout << "0\n";
		else
		{
			mn = 1e7;
			if (vec[0].second == 'R')
				x = vec[0].first, y = -1, prev = 0;
			else
				y = vec[0].first, x = -1, prev = 1;
			for (int i = 1; i < vec.size(); i++)
			{
				if (vec[i].second == 'R')
				{
					if (prev == 1)
						mn = min(mn, vec[i].first - y), prev = 0;
					x = vec[i].first;
				}
				else
				{
					if (prev == 0)
						mn = min(mn, vec[i].first - x), prev = 1;
					y = vec[i].first;
				}
			}
			cout << mn << "\n";
		}
	}

	return 0;
}