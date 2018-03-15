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
#define EPS 1e-9
const ll mod = 1000000007;
const ll OO = (ll)1e18;
const int dx[] = { 0, 1, -1, 0, 1, -1, 1, -1 };
const int dy[] = { 1, 0, 0, -1, 1, -1, -1, 1 };
ll gcd(ll a, ll b){ if (b == 0){ return a; }return gcd(b, a % b); }
//#pragma warning (disable : 4996)
void Qalbaz()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(7);
}

int main(){

	Qalbaz();

	int arr[505][505];
	int w, h, n, x1, x2, y1, y2, xMIN, yMIN, xMAX, yMAX, ans;
	while (cin >> w >> h >> n && (n || w || h))
	{
		memset(arr, 0, sizeof arr);
		while (n--)
		{
			cin >> x1 >> y1 >> x2 >> y2;
			xMIN = min(x1, x2);
			xMAX = max(x1, x2);
			yMIN = min(y1, y2);
			yMAX = max(y1, y2);
			arr[xMIN][yMIN] += 1;
			arr[xMIN][yMAX + 1] -= 1;
			arr[xMAX + 1][yMIN] -= 1;
			arr[xMAX + 1][yMAX + 1] += 1;
		}
		for (int i = 1; i <= w; i++)
		{
			for (int j = 1; j <= h; j++)
			{
				arr[i][j] = arr[i][j - 1] + arr[i][j];
			}
		}
		for (int i = 1; i <= h; i++)
		{
			for (int j = 1; j <= w; j++)
			{
				arr[j][i] = arr[j - 1][i] + arr[j][i];
			}
		}
		ans = 0;
		for (int i = 1; i <= w; i++)
		{
			for (int j = 1; j <= h; j++)
			{
				if (arr[i][j] == 0)
					ans++;
			}
		}
		if (ans == 0)
			cout << "There is no empty spots.\n";
		else if (ans == 1)
			cout << "There is one empty spot.\n";
		else
			cout << "There are " << ans << " empty spots.\n";
	}


	return 0;
}