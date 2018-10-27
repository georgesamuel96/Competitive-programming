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
vector<pair<int, int>> tree;
int arr[4];
void build(int s, int e, int pos)
{
	if (s == e)
	{
		tree[pos].first = vec[s], tree[pos].second = 0;
		return;
	}
	int mid = (s + e) / 2;
	build(s, mid, pos * 2);
	build(mid + 1, e, pos * 2 + 1);
	arr[0] = tree[pos * 2].first, arr[1] = tree[pos * 2].second,
		arr[2] = tree[pos * 2 + 1].first, arr[3] = tree[pos * 2 + 1].second;
	sort(arr, arr + 4);
	tree[pos].first = arr[3], tree[pos].second = arr[2];
}
void update(int ind, int k, int s, int e, int pos)
{
	if (s == e)
	{
		tree[pos].first = k;
		return;
	}
	int mid = (s + e) / 2;
	if (mid >= ind)
	{
		update(ind, k, s, mid, pos * 2);
	}
	else
	{
		update(ind, k, mid + 1, e, pos * 2 + 1);
	}
	arr[0] = tree[pos * 2].first, arr[1] = tree[pos * 2].second,
		arr[2] = tree[pos * 2 + 1].first, arr[3] = tree[pos * 2 + 1].second;
	sort(arr, arr + 4);
	tree[pos].first = arr[3], tree[pos].second = arr[2];
}
pair<int, int> getQ(int l, int r, int s, int e, int pos)
{
	if (s > r || e < l)
		return MP(0, 0);
	if (s >= l && e <= r)
	{
		return tree[pos];
	}
	int mid = (s + e) / 2;
	pair<int, int> x = getQ(l, r, s, mid, pos * 2);
	pair<int, int> y = getQ(l, r, mid + 1, e, pos * 2 + 1);
	arr[0] = x.first, arr[1] = x.second, arr[2] = y.first, arr[3] = y.second;
	sort(arr, arr + 4);
	return MP(arr[3], arr[2]);
}
int main(){

	fast();

	int n;
	scanf("%d", &n);
	vec.resize(n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &vec[i]);
	}
	int sz = (int)(ceil(log(n) / log(2)));
	sz = 2 * (int)(pow(2, sz));
	tree.resize(sz);
	int m, l, r;
	char t;
	scanf("%d", &m);
	build(0, n - 1, 1);
	while (m--)
	{
		scanf(" %c%d%d", &t, &l, &r);
		if (t == 'U')
		{
			update(l - 1, r, 0, n - 1, 1);
		}
		else
		{
			pair<int, int> ans = getQ(l - 1, r - 1, 0, n - 1, 1);
			printf("%d\n", ans.first + ans.second);
		}
	}

	return 0;
}