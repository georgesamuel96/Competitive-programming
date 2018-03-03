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

struct point
{
	double x, y;
	bool between(point p, point q)
	{
		return x <= max(p.x, q.x) && x >= min(p.x, q.x) && y >= min(p.y, q.y) && y <= max(p.y, q.y);
	}
};
struct line
{
	double a, b, c;
};
void getLine(point p1, point p2, line &l)
{
	if (abs(p1.x - p2.x) < EPS)
	{
		l.a = 1.0; l.b = 0.0; l.c = -p1.x;
	}
	else
	{
		l.a = (p1.y - p2.y) / (p2.x - p1.x);
		l.b = 1.0;
		l.c = -p1.x * l.a - p1.y;
	}
}
bool parallel(line l1, line l2)
{
	return abs(l1.a - l2.a) < EPS && abs(l1.b - l2.b) < EPS;

}
bool same(line l1, line l2) {
	return parallel(l1, l2) && (fabs(l1.c - l2.c) < EPS);
}
point intersect(line l1, line l2)
{
	double det = l1.a * l2.b - l2.a * l1.b;
	point p;
	p.x = 0, p.y = 0;
	if (parallel(l1, l2))
		return p;
	else
	{
		p.x = (l1.b * l2.c - l2.b * l1.c) / det;
		if (abs(l1.b) > EPS)
			p.y = -l1.a * p.x - l1.c;
		else				  
			p.y = -l2.a * p.x - l2.c;
		return p;
	}
}
int main(){

	Qalbaz();

	double a, b, c, d;
	int n;
	point p1, p2;
	vector<pair<pair<point, point>, int>>vec;
	int test = 1;
	line l1, l2;
	while (cin >> n)
	{
		if (n == 0)
			break;
		
		vec.clear();
		for (int k = 0; k < n; k++)
		{
			cin >> a >> b >> c >> d;
			p1.x = a, p1.y = b;
			p2.x = c, p2.y = d;
			vec.push_back(MP(MP(p1, p2), k + 1));
			if (k == 0)
				continue;
			int i = vec.size() - 1;
			for (int j = 0; j < vec.size() - 1; j++)
			{
				getLine(vec[i].first.first, vec[i].first.second, l1);
				getLine(vec[j].first.first, vec[j].first.second, l2);
				if (parallel(l1, l2))
				{
					if (same(l1, l2))
					{
						if (vec[j].first.first.between(vec[i].first.first, vec[i].first.second) || vec[j].first.second.between(vec[i].first.first, vec[i].first.second) || vec[i].first.first.between(vec[j].first.first, vec[j].first.second) || vec[i].first.second.between(vec[j].first.first, vec[j].first.second))
							vec.erase(vec.begin() + (j)), j--, i--;
					}
				}
				else
				{
					p1 = intersect(l1, l2);
					if (p1.between(vec[j].first.first, vec[j].first.second) && p1.between(vec[i].first.first, vec[i].first.second))
						vec.erase(vec.begin() + (j)), j--, i--;
				}
			}
		}
		cout << "Top sticks: ";
		for (int i = 0; i < vec.size(); i++)
		{
			if (i + 1 != vec.size())
				cout << vec[i].second << ", ";
			else
				cout << vec[i].second << ".\n";
		}
	}

	return 0;
}