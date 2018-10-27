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
vi tree, lazy;
string str;
char ss[55];
void build(int s, int e, int pos)
{
	if (s == e)
	{
		tree[pos] = str[s] - '0';
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
			lazy[pos * 2] = lazy[pos];
			lazy[pos * 2 + 1] = lazy[pos];
		}
		lazy[pos] = -1;
	}
}
void update(int l, int r, int val, int s, int e, int pos)
{
	process(s, e, pos);
	if (s > r || e < l)
		return;
	if (s >= l && e <= r)
	{
		if (val == -1)
			tree[pos] = ((e - s + 1)) * (tree[pos] == 0);
		else
			tree[pos] = (e - s + 1) * val;
		if (s != e)
		{
			lazy[pos * 2] = (tree[pos] != 0);
			lazy[pos * 2 + 1] = (tree[pos] != 0);
		}
		return;
	}
	int mid = (s + e) / 2;
	update(l, r, val, s, mid, pos * 2);
	update(l, r, val, mid + 1, e, pos * 2 + 1);
	tree[pos] = tree[pos * 2] + tree[pos * 2 + 1];
}
int getQ(int l, int r, int s, int e, int pos)
{
	process(s, e, pos);
	if (s > r || e < l)
		return 0;
	if (s >= l && e <= r)
	{
		return tree[pos];
	}
	int mid = (s + e) / 2;
	int x = getQ(l, r, s, mid, pos * 2);
	int y = getQ(l, r, mid + 1, e, pos * 2 + 1);
	return (x + y);
}
int main(){

	fast();

	int t, m, q, T, MAX, sz, l, r, test = 1, test2;
	char c;
	scanf("%d", &t);
	while (t--)
	{
		test2 = 1;
		printf("Case %d:\n", test++);
		str.clear();
		scanf("%d", &m);
		while (m--)
		{
			scanf("%d", &T);
			scanf("%s", ss);
			while (T--)
			{
				for (int i = 0; ss[i] != '\0'; i++)
					str.push_back(ss[i]);
			}
		}
		sz = str.size();
		MAX = (int)(ceil(log(sz) / log(2)));
		MAX = 2 * (int)(pow(2, MAX));
		tree.resize(MAX);
		lazy.resize(MAX, -1);
		build(0, sz - 1, 1);
		scanf("%d", &m);
		while (m--)
		{
			scanf(" %c%d%d", &c, &l, &r);
			if (c == 'F')
			{
				update(l, r, 1, 0, sz - 1, 1);
			}
			else if (c == 'E')
			{
				update(l, r, 0, 0, sz - 1, 1);
			}
			else if (c == 'I')
			{
				update(l, r, -1, 0, sz - 1, 1);
			}
			else
			{
				int ans = getQ(l, r, 0, sz - 1, 1);
				printf("Q%d: %d\n", test2++, ans);
			}
		}
		tree.clear();
		lazy.clear();
	}

	return 0;
}