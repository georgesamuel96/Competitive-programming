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
		ans++;
		string ss = "";
		while (ss != str)
		{
			ss = st.top();
			st.pop();
			inStack[ss] = 0;
		}
	}
}
int main(){

	Qalbaz();

	string str, str1, str2;
	int n, m;
	while (getline(cin, str) && str[0] != '0')
	{
		dfn.clear(), low.clear(), inStack.clear(), adj.clear();
		stringstream ss;
		ss << str;
		while (ss >> str1 >> str2)
		{
			n = stoi(str1);
			m = stoi(str2);
		}
		for (int i = 0; i < n; i++)
		{
			getline(cin, str);
			adj[str]= vector<string>();
		}
		for (int i = 0; i < m; i++)
		{
			getline(cin, str1);
			getline(cin, str2);
			adj[str1].push_back(str2);
		}
		cnt = ans = 0;
		for (auto it : adj)
		{
			if (dfn[it.first] == 0)
			{
				dfs(it.first);
			}
		}
		cout << ans << "\n";
	}

	return 0;
}