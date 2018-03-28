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
	cout << fixed << setprecision(2);
}

int arr[100][100], row[100], col[100];
bool check(int n)
{
	for (int i = 0; i < n; i++)
	{
		if (row[i] & 1 || col[i] & 1)
			return false;
	}
	return true;
}

int main(){

	Qalbaz();

	int n;
	while (cin >> n && n)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cin >> arr[i][j];
				row[i] += (arr[i][j] == 1);
				col[j] += (arr[i][j] == 1);
			}
		}
		int r = 0, c = 0, f = check(n), z = 0;
		for (int i = 0; i < n&&!f; i++)
		{
			for (int j = 0; j < n&&!f; j++)
			{
				z = 1;
				if (arr[i][j])
				{
					row[i]--, col[j]--;
					f = check(n);
					r = i, c = j;
					row[i]--, col[j]++;
				}
				else
				{
					row[i]++, col[j]++;
					f = check(n);
					r = i, c = j;
					row[i]--, col[j]--;
				}
			}
		}

		if (f && z == 0)
			cout << "OK\n";
		else if (f)
			cout << "Change bit (" << r + 1 << "," << c + 1 << ")\n";
		else
			cout << "Corrupt\n";
		memset(row, 0, sizeof row);
		memset(col, 0, sizeof col);
	}

	return 0;
}