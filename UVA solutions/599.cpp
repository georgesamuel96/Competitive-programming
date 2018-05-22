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
ll fast_power(ll base, ll power){
	if (power == 1)
		return base;
	if (power % 2 == 0)
		return fast_power((base*base), power / 2);
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
	cout << fixed << setprecision(4);
}
map<char, vector<char>>mp;
map<char, int>vis;
int dfs(char node)
{
	vis[node] = 1;
	int cnt = 1;
	for (int i = 0; i < mp[node].size(); i++)
	{
		int v = mp[node][i];
		if (vis[v] == 0)
		{
			cnt = cnt + dfs(v);
		}
	}
	return cnt;
}
int main(){

	Qalbaz();

	string str;
	getline(cin, str);
	int t = stoi(str);
	while (t--)
	{
		while (getline(cin, str) && str[0] != '*')
		{
			mp[str[1]].push_back(str[3]);
			mp[str[3]].push_back(str[1]);
		}
		getline(cin, str);
		for (int i = 0; i < str.size(); i++)
		{
			if (i % 2 == 0)
			{
				if (mp.find(str[i]) == mp.end())
					mp[str[i]] = vector<char>();
			}
		}
		int tree = 0, node = 0, ans;
		for (auto it : mp)
		{
			if (vis[it.first] == 0)
			{
				ans = dfs(it.first);
				if (ans > 1)
					tree++;
				else
					node++;
			}
		}
		cout << "There are " << tree << " tree(s) and " << node << " acorn(s).\n";
		mp.clear(), vis.clear();
	}
	return 0;
}