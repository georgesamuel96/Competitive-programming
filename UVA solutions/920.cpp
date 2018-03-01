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
	cout << fixed << setprecision(2);
}

struct point
{
	double x, y;
	point(){ x = 0.0, y = 0.0; }
	point(double _x, double _y) :x(_x), y(_y) {}
	bool operator < (point other) const 
	{
		if (fabs(x - other.x) > EPS)
			return x > other.x;
	}
};
vector<point>points;

double dist(point a, point b)
{
	return hypot(a.x - b.x, a.y - b.y);
}


int main(){

	Qalbaz();

	int t, n;
	cin >> t;
	double x, y, sum, maxY;
	while (t--)
	{
		cin >> n;
		points.clear();
		for (int i = 0; i < n;i++)
		{
			cin >> x >> y;
			points.push_back(point(x, y));
		}
		sort(all(points));

		/*


		points[i].y
		\*
		\* ---  maxY
		\
		\
		points[i - 1].y
		The line segment marked by * can be computed by
		distance(points[i], points[i - 1]) *
		(points[i].y - currentMaxY) / (points[i].y - points[i - 1].y)
		

		*/


		sum = 0.0;
		maxY = 0.0;
		for (int i = 1; i < n; i++)
		{
			if (points[i].y > maxY)
			{
				sum += dist(points[i], points[i - 1]) * (points[i].y - maxY) / (points[i].y - points[i - 1].y);
				maxY = points[i].y;
			}
		}
		cout << sum << "\n";
	}

	return 0;
}