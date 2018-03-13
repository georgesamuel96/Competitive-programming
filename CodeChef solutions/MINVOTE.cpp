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

vl vec, front, back;

int main(){

	Qalbaz();

	int n, t;
	int lo, hi, mid, z;
	cin >> t;
	while (t--)
	{
		cin >> n;
		vec.resize(n + 2);
		front.resize(n + 2), back.resize(n + 2);
		for (int i = 1; i <= n; i++)
		{
			cin >> vec[i];
			vec[i] = vec[i] + vec[i - 1];
		}
		
		for (int i = 1; i <= n; i++)
		{
			lo = i, hi = n, z = -1;
			while (lo <= hi)
			{
				mid = (lo + hi) / 2;
				if (vec[mid] - vec[i] <= (vec[i] - vec[i - 1]))
					lo = mid + 1, z = mid;
				else
					hi = mid - 1;
			}
			if (z != -1)
			{
				front[i + 1] += 1;
				front[min(z + 2, n + 1)] -= 1;
			}
			lo = 1, hi = i - 1, z = -1;
			while (lo <= hi)
			{
				mid = (lo + hi) / 2;
				if (vec[i - 1] - vec[mid] <= (vec[i] - vec[i - 1]))
					hi = mid - 1, z = mid;
				else
					lo = mid + 1;
			}
			if (z != -1)
			{
				back[i - 1] += 1;
				back[max(z - 1, 0)] -= 1;
			}
		}
		for (int i = 1, j = n; i <= n; i++, j--)
		{
			front[i] = front[i] + front[i - 1];
			back[j] = back[j] + back[j + 1];
		}
		for (int i = 1; i <= n; i++)
		{
			cout << back[i] + front[i] << " ";
		}
		cout << "\n";
		back.clear(), front.clear(), vec.clear();
	}
	
	return 0;
}