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
	//cout << fixed << setprecision(2);
}

/*
	points:

	left top      --> 0
	right top     --> 1
	left bottom   --> 2
	right bottom  --> 3

*/

double points[4][2], arr[4][2];

bool intersect()
{
	double a, b, c, d;
	a = max(points[2][0], arr[2][0]);
	b = max(points[2][1], arr[2][1]);
	c = min(points[1][0], arr[1][0]);
	d = min(points[1][1], arr[1][1]);
	if (a >= c || b >= d)
		return false;
	points[2][0] = a, points[2][1] = b;
	points[1][0] = c, points[1][1] = d;
	return true;
}


int main(){

	Qalbaz();

	int n;
	int t;
	cin >> t;
	while (t--)
	{
		cin >> points[2][0] >> points[2][1] >> points[1][0] >> points[1][1];
	
		cin >> arr[2][0] >> arr[2][1] >> arr[1][0] >> arr[1][1];
			
			if (!intersect())
			{
				cout << "No Overlap\n";
			}
			else
			{
				cout << points[2][0] << " " << points[2][1] << " " << points[1][0] << " " << points[1][1] << "\n";
			}
			if (t > 0)
				cout << "\n";
	}

	return 0;
}