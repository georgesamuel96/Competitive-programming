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
 
vs vec;
map<string, vector<pair<string, int>>>adj;
map<string, bool>taken;
priority_queue<pair<int, string>>pq;
void process(string node)
{
	taken[node] = true;
	pair<string, int> v;
	for (int i = 0; i < adj[node].size(); i++)
	{
		v = adj[node][i];
		if (taken[v.first] == false)
			pq.push(MP(-(v.second), v.first));
	}
}
 
int main(){
 
	Qalbaz();
 
	pair<int, string>tt;
	int t, n, x, y, w, mst, mn;
	cin >> t;
	string str;
	while (t--)
	{
		vec.clear();
		adj.clear();
		taken.clear();
		cin >> n;
		mst = mn = 1e7;
		vec.resize(n);
		str = "0000";
		for (int i = 0; i < n; i++)
		{
			cin >> vec[i];
			w = 0;
			for (int k = 0; k < 4; k++)
			{
				x = (vec[i][k] - '0') - 0;
				if (x < 0)
					x += 10;
				y = 0 - (vec[i][k] - '0');
				if (y < 0)
					y += 10;
				w += min(x, y);
			}
			if (mst > w)
				mst = w, str = vec[i];
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = i + 1; j < n; j++)
			{
				w = 0;
				for (int k = 0; k < 4; k++)
				{
					x = (vec[i][k] - '0') - (vec[j][k] - '0');
					if (x < 0)
						x += 10;
					y = (vec[j][k] - '0') - (vec[i][k] - '0');
					if (y < 0)
						y += 10;
					w += min(x, y);
				}
				adj[vec[i]].push_back(MP(vec[j], w));
				adj[vec[j]].push_back(MP(vec[i], w));
			}
		}
		y = 0;
		process(str);
		while (!pq.empty())
		{
			tt = pq.top(), pq.pop();
			x = tt.first;
			x = -x;
			str = tt.second;
			if (taken[str] == false)
				mst += x, process(str);
		}
		cout << mst << "\n";
	}
 
	return 0;
}