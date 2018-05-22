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

int main(){

	Qalbaz();

	int t;
	cin >> t;
	int n, m, arr[10][30], arr2[10][10], z;
	map<int, int>mp;
	while (t--)
	{
		mp.clear();
		cin >> n >> m;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				cin >> arr[i][j];
				if (arr[i][j])
					mp[j + 1]++;
			}
		}
		z = 1;
		for (int i = 0; i < m; i++)
		{
			if (mp[i + 1] != 2)
			{
				z = 0;
				break;
			}
		}
		if (z)
		{
			memset(arr2, 0, sizeof arr2);
			int u = -1, v = -1;
			for (int j = 0; j < m; j++)
			{
				u = -1, v = -1;
				for (int i = 0; i < n; i++)
				{
					if (arr[i][j])
					{
						if (u == -1)
							u = i;
						else
							v = i;
					}
				}
				if (arr2[u][v])
				{
					z = 0;
					break;
				}
				else
					arr2[u][v] = arr2[v][u] = 1;
			}
			if (z)
				cout << "Yes\n";
			else
				cout << "No\n";
		}
		else
			cout << "No\n";
	}
	
	return 0;
}