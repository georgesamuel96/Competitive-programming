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
struct point {
	double x, y;
	point(double _x, double _y)
	{
		x = _x, y = _y;
	}
};
struct vec
{
	double x, y;
	vec()
	{
		x = 0.0, y = 0.0;
	}
	vec(double a, double b)
	{
		x = a, y = b;
	}
};
vec scale(vec v, double s)
{
	return vec(v.x * s, v.y * s);
}
point translate(point p, vec v)
{
	return point(p.x + v.x, p.y + v.y);
}
double dist(point p, point q)
{
	return (sqrt((p.x - q.x) * (p.x - q.x) + (p.y - q.y) * (p.y - q.y)));
}
int main(){

	Qalbaz();

	string str, str_num, dir;
	double num, sqrt2 = sqrt(2.0);
	map<string, vec>mp;
	int test = 1;
	point p = point(0.0, 0.0);
	mp["N"] = vec(0, 1);
	mp["S"] = vec(0, -1);
	mp["E"] = vec(1, 0);
	mp["W"] = vec(-1, 0);
	mp["NE"] = vec(1 / sqrt2, 1 / sqrt2);
	mp["NW"] = vec(-1 / sqrt2, 1 / sqrt2);
	mp["SE"] = vec(1 / sqrt2, -1 / sqrt2);
	mp["SW"] = vec(-1 / sqrt2, -1 / sqrt2);
	while (getline(cin, str))
	{
		if (str == "END")
			break;
		dir.clear();
		str_num.clear();
		p = point(0.0, 0.0);
		for (int i = 0; i < str.size() - 1; i++)
		{
			if (str[i] >= '0' && str[i] <= '9')
				str_num.push_back(str[i]);
			else if (str[i] != ',')
				dir.push_back(str[i]);
			else
			{
				num = stod(str_num);
				vec v = mp[dir];
				v = scale(v, num);
				p = translate(p, v);
				dir.clear();
				str_num.clear();
			}
		}
		num = stod(str_num);
		vec v = mp[dir];
		v = scale(v, num);
		p = translate(p, v);
		cout << "Map #" << test++ << "\nThe treasure is located at (" << p.x << "," << p.y << ").\n";
		cout << "The distance to the treasure is " << dist(point(0.0, 0.0), p) << ".\n\n";
	}

	return 0;
}