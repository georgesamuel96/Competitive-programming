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
ll fast_power(ll base, ll power){
	if (power == 0)
		return 1;
	if (power == 1)
		return (base % mod);
	if (power % 2 == 0)
		return (fast_power(((base*base) % mod), power / 2LL) % mod);
	else return ((base*fast_power(((base*base) % mod) % mod, power / 2LL)) % mod);
}
//#pragma warning (disable : 4996)
void Qalbaz()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(0);
}

vi vec;
struct node
{
	ll sum, pref, suff, MAX;
};
vector<node> arr;
void build(int s, int e, int pos)
{
	if (s == e)
	{
		arr[pos].sum = vec[s];
		arr[pos].pref = vec[s];
		arr[pos].suff = vec[s];
		arr[pos].MAX = vec[s];
		return;
	}
	int mid = (s + e) / 2;
	build(s, mid, pos * 2);
	build(mid + 1, e, pos * 2 + 1);
	arr[pos].sum = arr[pos * 2].sum + arr[pos * 2 + 1].sum;
	arr[pos].pref = max(arr[pos * 2].pref, arr[pos * 2].sum + arr[pos * 2 + 1].pref);
	arr[pos].suff = max(arr[pos * 2 + 1].suff, arr[pos * 2 + 1].sum + arr[pos * 2].suff);
	arr[pos].MAX = max(arr[pos].pref, max(arr[pos].suff, max(arr[pos * 2].MAX,
		max(arr[pos * 2 + 1].MAX, arr[pos * 2].suff + arr[pos * 2 + 1].pref))));
}
node getNumber(int l, int r, int s, int e, int pos)
{
	node ans;
	ans.suff = ans.pref = ans.MAX = ans.sum = -OO;
	if (s > e || s > r || e < l)
		return ans;
	if (s >= l && e <= r)
		return arr[pos];
	int mid = (s + e) / 2;
	node x = getNumber(l, r, s, mid, pos * 2);
	node y = getNumber(l, r, mid + 1, e, pos * 2 + 1);
	ans.sum = x.sum + y.sum;
	ans.pref = max(x.pref, x.sum + y.pref);
	ans.suff = max(y.suff, y.sum + x.suff);
	ans.MAX = max(ans.pref, max(ans.suff, max(x.MAX, max(y.MAX,
		x.suff + y.pref))));
	return ans;
}
int main(){

	Qalbaz();

	int n;
	cin >> n;
	vec.resize(n);
	for (int i = 0; i < n; i++)
	{
		cin >> vec[i];
	}
	int x = (int)(ceil(log(n) / log(2)));
	int sz = 2 * (int)pow(2, x) - 1;
	arr.resize(sz + 1);
	build(0, n - 1, 1);
	int m, l, r;
	cin >> m;
	while (m--)
	{
		cin >> l >> r;
		node y = getNumber(l - 1, r - 1, 0, n - 1, 1);
		cout << y.MAX << "\n";
	}

	return 0;
}
