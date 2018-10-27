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
vi vec;
char str[30];
int tree[4 * 100001];
void build(int s, int e, int pos)
{
	if (s == e)
	{
		tree[pos] = vec[s];
		return;
	}
	int mid = (s + e) / 2;
	build(s, mid, pos * 2);
	build(mid + 1, e, pos * 2 + 1);
	tree[pos] = min(tree[pos * 2], tree[pos * 2 + 1]);
}
int getQ(int l, int r, int s, int e, int pos)
{
	if (s >= l && e <= r)
		return tree[pos];
	if (s > r || e < l)
		return OO;
	int mid = (s + e) / 2;
	int x = getQ(l, r, s, mid, pos * 2);
	int y = getQ(l, r, mid + 1, e, pos * 2 + 1);
	return min(x, y);
}
void update(int ind, int s, int e, int pos)
{
	if (s == e)
	{
		tree[pos] = vec[s];
		return;
	}
	int mid = (s + e) / 2;
	if (mid >= ind)
	{
		update(ind, s, mid, pos * 2);
	}
	else
	{
		update(ind, mid + 1, e, pos * 2 + 1);
	}
	tree[pos] = min(tree[pos * 2], tree[pos * 2 + 1]);
}
vi vv;
int main(){

	fast();

	int n, m, x, y, k, z;
	scanf("%d%d", &n, &m);
	vec.resize(n);
	for (int i = 0; i < n; i++)
		scanf("%d", &vec[i]);
	build(0, n - 1, 1);
	while (m--)
	{
		scanf("%s", str);
		if (str[0] == 'q')
		{
			k = 6;
			x = 0;
			while (str[k] != ',')
				x = x * 10 + (str[k] - '0'), k++;
			k++;
			y = 0;
			while (str[k] != ')')
				y = y * 10 + (str[k] - '0'), k++;
			x = getQ(x - 1, y - 1, 0, n - 1, 1);
			printf("%d\n", x);
		}
		else
		{
			vv.clear();
			k = 6;
			int x = 0;
			while (str[k] != ')')
			{
				if (str[k] != ',')
					x = x * 10 + (str[k] - '0');
				else
				{
					vv.push_back(x - 1);
					x = 0;
				}
				k++;
			}
			vv.push_back(x - 1);
			for (int i = 0; i < vv.size() - 1; i++)
			{
				swap(vec[vv[i]], vec[vv[i + 1]]);
			}
			for (int i = 0; i < vv.size(); i++)
			{
				update(vv[i], 0, n - 1, 1);
			}
		}

	}

	return 0;
}