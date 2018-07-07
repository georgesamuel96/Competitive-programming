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

int arr[100][100], vis[100][100], cnt;
bool valid(int r, int c, int n)
{
	return (r >= 0 && r < n && c >= 0 && c < n);
}
void solve(int i, int j, int num, int n)
{
	if (!valid(i, j, n) || vis[i][j] || arr[i][j] != num)
		return;
	cnt++;
	vis[i][j] = 1;
	for (int k = 0; k < 4; k++)
	{
		int a = i + dx[k];
		int b = j + dy[k];
		solve(a, b, num, n);
	}
}
int main(){

	Qalbaz();

	string str, num1, num2;
	int n;
	int x, y, f, t = 0, ans;
	vector<pair<int, int>>vec;
	while (getline(cin, str) && str[0] != '0')
	{
		t++;
		ans = 0;
		n = stoi(str);
		memset(arr, 0, sizeof arr);
		memset(vis, 0, sizeof vis);
		vec.resize(n);
		for (int i = 1; i <= n - 1; i++)
		{
			f = 1;
			getline(cin, str);
			stringstream ss;
			ss << str;
			while (ss >> num1 >> num2)
			{
				x = stoi(num1);
				y = stoi(num2);
				if (f)
					vec[i - 1] = MP(x - 1, y - 1);
				f = 0;
				arr[x - 1][y - 1] = i;
			}
		}
		for (int i = 0; i < n - 1; i++)
		{
			cnt = 0;
			solve(vec[i].first, vec[i].second, i + 1, n);
			if (cnt == n)
				ans++;
		}
		f = 1;
		for (int i = 0; i < n && f; i++)
		{
			for (int j = 0; j < n && f; j++)
			{
				if (arr[i][j] == 0)
				{
					cnt = 0;
					solve(i, j, 0, n);
					if (cnt == n)
						ans++;
					f = 0;
				}
			}
		}
		f = 1;
		for (int i = 0; i < n && f; i++)
		{
			for (int j = 0; j < n && f; j++)
			{
				f = vis[i][j];
			}
		}
		if (f && ans == n)
			cout << "good\n";
		else
			cout << "wrong\n";
	}

	return 0;
}