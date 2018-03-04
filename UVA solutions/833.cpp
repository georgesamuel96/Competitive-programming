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

struct point {
	double x, y;
	point() { x = y = 0.0; }
	point(double _x, double _y) : x(_x), y(_y) {}

	bool between(point p, point q)
	{
		return x <= max(p.x, q.x) && x >= min(p.x, q.x) && y >= min(p.y, q.y) && y <= max(p.y, q.y);
	}

	bool above(point p1, point p2)
	{
		if (p1.x == x && p1.y == y)
			return true;
		if (p2.x == x && p2.y == y)
			return true;
		if (y > p1.y || y > p2.y)
			return true;
		return false;
	}
};
struct vec {
	double x, y; 
	vec(double _x, double _y) : x(_x), y(_y) {}
};
vec toVec(point a, point b) {
	return vec(b.x - a.x, b.y - a.y);
}
double cross(vec a, vec b) { return a.x * b.y - a.y * b.x; }

bool ccw(point p, point q, point r) {
	if (cross(toVec(p, q), toVec(p, r)) > 0)
		return  true;
	if (cross(toVec(q, p), toVec(q, r)) > 0)
		return  true;
	return false;
}

bool above(point p, point a, point b)
{
	if (p.above(a, b) && p.x >= min(a.x, b.x) && p.x <= max(a.x, b.x))
	{
		if (ccw(a, b, p))
			return true;
	}
	return false;
}
point getPoint(point p, point q)
{
	if (p.y < q.y)
		return p;
	return q;
}
int main(){

	Qalbaz();

	int t, n;
	cin >> t;
	double a, b, c, d;
	point p, q;
	vector<pair<point, point>>vec;
	int ind;
	while (t--)
	{
		cin >> n;
		vec.clear();
		for (int i = 0; i < n; i++)
		{
			cin >> a >> b >> c >> d;
			p.x = a, p.y = b;
			q.x = c, q.y = d;
			if (i == 0)
				vec.push_back(MP(p, q));
			else
			{
				ind = n;
				for (int j = 0; j < vec.size(); j++)
				{
					if (p.above(vec[j].first, vec[j].second))
					{
						ind = j;
						break;
					}
				}

				/*
				*	for sort lines
				*/

				vec.push_back(MP(p, q));
				for (int j = vec.size() - 1; j > ind; j--)
				{
					vec[j] = vec[j - 1];
				}
				if (ind != n)
					vec[ind] = MP(p, q);
			}
		}
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			cin >> a >> b;
			p.x = a, p.y = b;
			for (int j = 0; j < vec.size(); j++)
			{
				if (above(p, vec[j].first, vec[j].second))
				{
					p = getPoint(vec[j].first, vec[j].second);
				}
			}
			ind = p.x;
			cout << ind << "\n";
		}
		if (t > 0)
			cout << "\n";
	}

	return 0;
}