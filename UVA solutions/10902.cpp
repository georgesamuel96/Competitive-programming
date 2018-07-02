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
struct point
{
	double x, y;
	point()
	{

	}
	point(double _x, double _y)
	{
		x = _x, y = _y;
	}
};
bool IN(double a, double b, double c)
{
	if (a <= c && c <= b)
		return true;
	return false;
}
bool onLine(point A, point B, point C)
{
	double minX = min(A.x, B.x);
	double maxX = max(A.x, B.x);
	double minY = min(A.y, B.y);
	double maxY = max(A.y, B.y);
	if (IN(minX, maxX, C.x) && IN(minY, maxY, C.y))
	{
		if ((A.x - B.x) * (C.y - A.y) == (A.y - B.y) * (C.x - A.x))
			return true;
	}
	return false;
}
long double cross(point A, point B, point C)
{
	return ((B.x - A.x) * (C.y - A.y) - (B.y - A.y) * (C.x - A.x));
}
bool INTERSECT(point A, point B, point C, point D)
{
	if (onLine(A, B, C) || onLine(A, B, D) || onLine(C, D, A) || onLine(C, D, B))
		return true;
	if (cross(A, B, C) * cross(A, B, D) < 0 && cross(B, A, C) * cross(B, A, D) &&
		cross(C, D, A) * cross(C, D, B) < 0 && cross(D, C, A) * cross(D, C, B) < 0)
		return true;
	return false;
}

int main(){

	Qalbaz();

	vector<pair<point, point>>vec;
	pair<double, double> newPoint;
	vi vv, ans;
	int n;
	while (cin >> n && n)
	{
		vec.resize(n);
		vv.clear();
		vv.resize(n);
		bool f;
		int sz = 0, cnt, _ans;
		for (int i = 0; i < n; i++)
		{
			cnt = 0;
			cin >> vec[i].first.x >> vec[i].first.y >> vec[i].second.x >> vec[i].second.y;
			f = true;
			for (int j = 0; j < sz; j++)
			{
				if (INTERSECT(vec[vv[j]].first, vec[vv[j]].second, vec[i].first, vec[i].second))
					continue;
				vv[cnt] = vv[j];
				cnt++;
			}
			vv[cnt] = i;
			sz = cnt + 1;
		}
		
		cout << "Top sticks:";
		f = false;
		for (int i = 0; i < sz; i++)
		{
			if (f)
				cout << ",";
			f = true;
			cout << " " << vv[i] + 1;
		}
		cout << ".\n";
	}

	return 0;
}