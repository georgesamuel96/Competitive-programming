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
map<string, vector<pair<string, int>>>adj;
vs vec;
priority_queue<pair<int, string>>pq;
map<string, int>vis;
int weight(string str, string ss)
{
	int ans = 0;
	int x, y, z1, z2;
	for (int i = 0; i < 4; i++)
	{
		x = str[i] - '0';
		y = ss[i] - '0';
		z1 = z2 = 0;
		while (x != y)
		{
			z1++;
			x++;
			if (x == 10)
				x = 0;
		}
		x = str[i] - '0';
		y = ss[i] - '0';
		while (x != y)
		{
			z2++;
			y++;
			if (y == 10)
				y = 0;
		}
		ans = ans + min(z1, z2);
	}
	return ans;
}
void process(string str)
{
	vis[str] = 1;
	pair<string, int>v;
	for (int i = 0; i < adj[str].size(); i++)
	{
		v = adj[str][i];
		if (vis[v.first] == 0)
		{
			pq.push(MP(-v.second, v.first));
		}
	}
}
int main(){

	Qalbaz();

	int t, n, ans;
	cin >> t;
	pair<int, string>pr;
	while (t--)
	{
		adj.clear();
		vis.clear();
		ans = OO;
		cin >> n;
		vec.resize(n);
		for (int i = 0; i < n; i++)
		{
			cin >> vec[i];
			ans = min(ans, weight("0000", vec[i]));
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = i + 1; j < n; j++)
			{
				adj[vec[i]].push_back(MP(vec[j], weight(vec[i], vec[j])));
				adj[vec[j]].push_back(MP(vec[i], weight(vec[i], vec[j])));
			}
		}
		process(vec[0]);
		while (!pq.empty())
		{
			pr = pq.top();
			pq.pop();
			pr.first *= -1;
			if (vis[pr.second] == 0)
			{
				ans += pr.first, process(pr.second);
			}
		}
		cout << ans << "\n";
	}

	return 0;
}