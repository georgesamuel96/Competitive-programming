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

int n, m;
char arr[8][8];
vs vec;
int vis[8][8], ar[26];
bool valid(int r, int c)
{
	return (r >= 0 && r < n && c >= 0 && c < m);
}
bool f;
string str = "IEHOVA#";
void solve(int r, int c)
{
	if (f)
	{
		for (int i = 0; i < vec.size() - 1; i++)
			cout << vec[i] << " ";
		cout << vec[vec.size() - 1] << "\n";
		return;
	}
	vis[r][c] = 1;
	for (int i = 0; i < str.size() - 1; i++)
	{
		if (valid(r - 1, c) && arr[r - 1][c] == str[i] && vis[r - 1][c] == 0)
		{
			vec.push_back("forth");
			solve(r - 1, c);
			vec.pop_back();
		}
		if (valid(r, c + 1) && arr[r][c + 1] == str[i] && vis[r][c + 1] == 0)
		{
			vec.push_back("right");
			solve(r, c + 1);
			vec.pop_back();
		}
		if (valid(r, c - 1) && arr[r][c - 1] == str[i] && vis[r][c - 1] == 0)
		{
			vec.push_back("left");
			solve(r, c - 1);
			vec.pop_back();
		}
	}
	if (valid(r - 1, c) && arr[r - 1][c] == str[str.size() - 1] && vis[r - 1][c] == 0)
	{
		f = true;
		vec.push_back("forth");
		solve(r - 1, c);
		vec.pop_back();
	}
	if (valid(r, c + 1) && arr[r][c + 1] == str[str.size() - 1] && vis[r][c + 1] == 0)
	{
		f = true;
		vec.push_back("right");
		solve(r, c + 1);
		vec.pop_back();
	}
	if (valid(r, c - 1) && arr[r][c - 1] == str[str.size() - 1] && vis[r][c - 1] == 0)
	{
		f = true;
		vec.push_back("left");
		solve(r, c - 1);
		vec.pop_back();
	}
}

int main(){

	Qalbaz();

	int t;
	int r, c;
	cin >> t;
	
	
	while (t--)
	{
		cin >> n >> m;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				cin >> arr[i][j];
				if (arr[i][j] == '@')
					r = i, c = j;
			}
		}
		memset(vis, 0, sizeof vis);
		f = false;
		solve(r, c);

	}
	return 0;
}