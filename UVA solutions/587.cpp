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
	cout << fixed << setprecision(3);
}


struct point
{
	double x, y;
	point(){ x = 0.0, y = 0.0; }
};
vector<pair<int, string>>dir;
void cut(string str, double &x, double &y)
{
	double num = 0.0, dig;
	string ss = "";
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] >= '0' && str[i] <= '9')
			num = num * 10 + (str[i] - '0');
		else
			ss += str[i];
	}
	dig = sqrt(num * num / 2);
	if (ss == "N") y += num;
	else if (ss == "NE") y += dig, x += dig;
	else if (ss == "E") x += num;
	else if (ss == "SE") x += dig, y -= dig;
	else if (ss == "S") y -= num;
	else if (ss == "SW") x -= dig, y -= dig;
	else if (ss == "W") x -= num;
	else if (ss == "NW") x -= dig, y += dig;
}
double dist(point p)
{
	return hypot(p.x, p.y);
}
int main(){

	Qalbaz();

	string str;
	vs vec;
	point p;
	int test = 0;
	while (cin >> str && str != "END")
	{
		cout << "Map #" << ++test << "\n";
		vec.clear();
		dir.clear();
		stringstream ss(str);
		while (getline(ss, str, ','))
		{
			if (str[str.size() - 1] == '.')
				str.pop_back(), vec.push_back(str);
			else
				vec.push_back(str);
		}
		for (int i = 0; i < vec.size(); i++)
		{
			cut(vec[i], p.x, p.y);
		}
		cout << "The treasure is located at (" << p.x << "," << p.y << ").\n";
		cout << "The distance to the treasure is " << dist(p) << ".\n\n";
		p.x = p.y = 0.0;
	}

	return 0;
}