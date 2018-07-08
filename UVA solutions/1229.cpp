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
map<string, int>dfn, low, inStack;
map<string, vs>adj;
int cnt, ans;
stack<string>st;
vector<vs>comps;
void dfs(string str)
{
	dfn[str] = low[str] = ++cnt;
	inStack[str] = 1;
	st.push(str);
	for (int i = 0; i < adj[str].size(); i++)
	{
		string v = adj[str][i];
		if (dfn[v] == 0)
		{
			dfs(v);
			low[str] = min(low[v], low[str]);
		}
		else if (inStack[v])
		{
			low[str] = min(low[str], low[v]);
		}
	}
	if (low[str] == dfn[str])
	{
		string ss = "";
		comps.push_back(vector<string>());
		while (ss != str)
		{
			ss = st.top();
			st.pop();
			inStack[ss] = 0;
			comps.back().push_back(ss);
		}
	}
}
map<string, int>vis;
set<string>SET;
void dfs2(string u)
{
	SET.insert(u);
	vis[u] = 1;
	for (int i = 0; i < adj[u].size(); i++)
	{
		string v = adj[u][i];
		if (vis[v] == 0)
			dfs2(v);
	}
}
int main(){

	Qalbaz();

	string str, str1, str2;
	int n, m, ff = 0;

	while (getline(cin, str) && str[0] != '0')
	{
		ff = 1;
		n = stoi(str);
		dfn.clear(), low.clear(), inStack.clear(), adj.clear(), comps.clear();
		for (int i = 0; i < n; i++)
		{
			getline(cin, str);
			stringstream ss;
			ss << str;
			ss >> str1;
			while (ss >> str2)
			{
				adj[str1].push_back(str2);
			}
		}
		cnt = ans = 0;
		for (auto it : adj)
		{
			if (dfn[it.first] == 0)
			{
				dfs(it.first);
			}
		}
		SET.clear();
		vis.clear();
		for (int i = 0; i < comps.size(); i++)
		{
			if (comps[i].size() > 1)
			{
				for (int j = 0; j < comps[i].size(); j++)
					dfs2(comps[i][j]);
			}
		}
		ans = 0;
		cout << (int)SET.size() << "\n";
		for (auto it : SET)
		{
			if (ans > 0)
				cout << " ";
			ans++;
			cout << it;
		}
		cout << "\n";
	}

	return 0;
}