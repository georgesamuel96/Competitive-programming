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
#include<iterator>
#include<cctype>

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

//#pragma warning (disable : 4996)
void fast()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	//ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(8);
}
bool cmp(const pair<int, int>& L, const pair<int, int>& R){
	if (L.first == R.first){
		return L.second > R.second;
	}
	else {
		return L.first < R.first;
	}
}
int main(){

	fast();

	int t, n, l, r, ans, lo, hi, mid, z;
	scanf("%d", &t);
	vector<pair<int, int>> vec;
	while (t--)
	{
		ans = 0;
		scanf("%d", &n);
		vec.resize(n);
		for (int i = 0; i < n; i++)
		{
			scanf("%d%d", &l, &r);
			vec[i].first = l, vec[i].second = r;
		}
		sort(all(vec), cmp);
		while (vec.size())
		{
			l = vec.back().first;
			r = vec.back().second;
			vec.pop_back();
			ans++;
			while (true)
			{
				lo = 0, hi = vec.size() - 1, z = -1;
				while (lo <= hi)
				{
					mid = (lo + hi) / 2;
					if (vec[mid].first < l && vec[mid].second < r)
						lo = mid + 1, z = mid;
					else
						hi = mid - 1;
				}
				if (z == -1)
					break;
				l = vec[z].first, r = vec[z].second;
				vec.erase(vec.begin() + z);
			}
		}
		printf("%d\n", ans);


	}

	return 0;
}