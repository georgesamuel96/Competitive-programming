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
vi tree, lazy, vec, prime;
void build(int s, int e, int pos)
{
	if (s == e)
	{
		tree[pos] = prime[vec[s]];
		return;
	}
	int mid = (s + e) / 2;
	build(s, mid, pos * 2);
	build(mid + 1, e, pos * 2 + 1);
	tree[pos] = tree[pos * 2] + tree[pos * 2 + 1];
}
void process(int s, int e, int pos)
{
	if (lazy[pos] != -1)
	{
		tree[pos] = (e - s + 1) * lazy[pos];
		if (s != e)
		{
			int mid = (s + e) / 2;
			lazy[pos * 2] = lazy[pos];
			lazy[pos * 2 + 1] = lazy[pos];
		}
		lazy[pos] = -1;
	}
}
void update(int l, int r, int s, int e, int pos, int val)
{
	process(s, e, pos);
	if (s >= l && e <= r)
	{
		tree[pos] = (e - s + 1) * val;
		if (s != e)
		{
			int mid = (s + e) / 2;
			lazy[pos * 2] = val;
			lazy[pos * 2 + 1] = val;
		}
		return;
	}
	if (s > r || e < l)
		return;
	int mid = (s + e) / 2;
	update(l, r, s, mid, pos * 2, val);
	update(l, r, mid + 1, e, pos * 2 + 1, val);
	tree[pos] = tree[pos * 2] + tree[pos * 2 + 1];
}
int getQ(int l, int r, int s, int e, int pos)
{
	process(s, e, pos);
	if (s >= l && e <= r)
	{
		return tree[pos];
	}
	if (s > r || e < l)
		return 0;
	int mid = (s + e) / 2;
	int x = getQ(l, r, s, mid, pos * 2);
	int y = getQ(l, r, mid + 1, e, pos * 2 + 1);
	return (x + y);
}
int main(){

	fast();

	prime.resize(1e6 + 1, 1);
	prime[0] = prime[1] = 0;
	for (int i = 2; i*i <= 1e6; i++)
	{
		if (prime[i])
		{
			for (int j = i * 2; j <= 1e6; j += i)
			{
				prime[j] = 0;
			}
		}
	}
	int MAX = (int)(ceil(log(1e6) / log(2)));
	MAX = 2 * (int)(pow(2, MAX));
	int t, n, m, type, l, r, val;
	scanf("%d", &t);
	int test = 1;
	while (t--)
	{
		printf("Case %d:\n", test++);
		scanf("%d%d", &n, &m);
		vec.resize(n);
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &vec[i]);
		}
		tree.clear(), lazy.clear();
		tree.resize(MAX);
		lazy.resize(MAX, -1);
		build(0, n - 1, 1);
		while (m--)
		{
			scanf("%d%d%d", &type, &l, &r);
			if (type == 1)
			{
				int x = getQ(l - 1, r - 1, 0, n - 1, 1);
				printf("%d\n", x);
			}
			else
			{
				scanf("%d", &val);
				if (prime[val])
					update(l - 1, r - 1, 0, n - 1, 1, 1);
				else
					update(l - 1, r - 1, 0, n - 1, 1, 0);
			}
		}
	}

	return 0;
}