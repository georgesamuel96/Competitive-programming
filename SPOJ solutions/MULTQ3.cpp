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
struct node
{
	int x, y, z;
};
vector<node> tree;
vi lazy;
void build(int s, int e, int pos)
{
	if (s == e)
	{
		tree[pos].x = 1, tree[pos].y = 0, tree[pos].z = 0;
		return;
	}
	int mid = (s + e) / 2;
	build(s, mid, pos * 2);
	build(mid + 1, e, pos * 2 + 1);
	tree[pos].x = tree[pos * 2].x + tree[pos * 2 + 1].x;
	tree[pos].y = tree[pos * 2].y + tree[pos * 2 + 1].y;
	tree[pos].z = tree[pos * 2].z + tree[pos * 2 + 1].z;
}
void process(int s, int e, int pos)
{
	if (lazy[pos] != 0)
	{
		lazy[pos] %= 3;
		int x, y, z;
		x = tree[pos].x, y = tree[pos].y, z = tree[pos].z;
		if (lazy[pos] == 1)
		{
			tree[pos].x = y, tree[pos].y = z, tree[pos].z = x;
		}
		else if (lazy[pos] == 2)
		{
			tree[pos].x = z, tree[pos].y = x, tree[pos].z = y;
		}
		if (s != e)
		{
			lazy[pos * 2] += lazy[pos];
			lazy[pos * 2 + 1] += lazy[pos];
		}
		lazy[pos] = 0;
	}
}
void update(int l, int r, int s, int e, int pos)
{
	process(s, e, pos);
	if (s > r || e < l)
		return;
	if (s >= l && e <= r)
	{
		int x, y, z;
		x = tree[pos].x, y = tree[pos].y, z = tree[pos].z;
		tree[pos].x = y, tree[pos].y = z, tree[pos].z = x;
		if (s != e)
		{
			lazy[pos * 2]++, lazy[pos * 2 + 1]++;
		}
		return;
	}
	int mid = (s + e) / 2;
	update(l, r, s, mid, pos * 2);
	update(l, r, mid + 1, e, pos * 2 + 1);
	tree[pos].x = tree[pos * 2].x + tree[pos * 2 + 1].x;
	tree[pos].y = tree[pos * 2].y + tree[pos * 2 + 1].y;
	tree[pos].z = tree[pos * 2].z + tree[pos * 2 + 1].z;
}
int getQ(int l, int r, int s, int e, int pos)
{
	process(s, e, pos);
	if (s > r || e < l)
		return 0;
	if (s >= l && e <= r)
		return tree[pos].x;
	int mid = (s + e) / 2;
	int x = getQ(l, r, s, mid, pos * 2);
	int y = getQ(l, r, mid + 1, e, pos * 2 + 1);
	return (x + y);
}
int main(){

	fast();

	int n, m;
	scanf("%d%d", &n, &m);
	int MAX = (int)(ceil(log(1e5) / log(2)));
	MAX = 2 * (int)(pow(2, MAX));
	tree.resize(MAX);
	lazy.resize(MAX);
	int type, l, r;
	build(0, n - 1, 1);
	while (m--)
	{
		scanf("%d%d%d", &type, &l, &r);
		if (type)
		{
			int x = getQ(l, r, 0, n - 1, 1);
			printf("%d\n", x);
		}
		else
		{
			update(l, r, 0, n - 1, 1);
		}
	}

	return 0;
}