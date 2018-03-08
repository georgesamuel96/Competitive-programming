/*#define _CRT_SECURE_NO_WARNINGS
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
ll fast_power(double base, ll power){
	if (power == 1) return base;
	if (power % 2 == 0) return fast_power((base*base), power / 2);
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
	cout << fixed << setprecision(2);
}


int main(){

	Qalbaz();

	map<int, int>mp;
	int n, m;
	cin >> n >> m;
	vl vec(n, 1e10), rem;
	int x;
	for (int i = 1; i <= m; i++)
		mp[i] = 0;
	int y = n / m;
	cout << y << " ";
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		if (x <= m && mp[x] < y)
			mp[x]++, vec[i] = x;
		else
			rem.push_back(i);
	}
	int j = 0, ss = 0;
	
	for (int i = 1; i <= m; i++)
	{
		if (mp[i] < y)
		{
			ss++;
			vec[rem[rem.size() - 1]] = i;
			rem.pop_back();
			mp[i]++;
			i--;
		}
	}
	j = 1;
	for (int i = 0; i < rem.size(); i++)
		vec[rem[i]] = j, j++, ss++;
	cout << ss << "\n";
	for (int i = 0; i < n; i++)
		cout << vec[i] << " ";

	return 0;
}*/

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
ll fast_power(double base, ll power){
	if (power == 1) return base;
	if (power % 2 == 0) return fast_power((base*base), power / 2);
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
	cout << fixed << setprecision(2);
}

int dp[105][105], arr[105][105], n, m;
bool valid(int r, int c)
{
	if (r < 0 || r >= n || c < 0 || c >= m)
		return false;
	return true;
}
int solve(int r, int c)
{
	if (!valid(r, c))
		return 0;
	if (r == n - 1)
		return arr[r][c];
	int &ret = dp[r][c];
	if (ret != -1)
		return ret;
	ret = 0;
	ret = max(ret, solve(r + 1, c + 1) + arr[r][c]);
	ret = max(ret, solve(r + 1, c - 1) + arr[r][c]);
	ret = max(ret, solve(r + 1, c) + arr[r][c]);
	return ret;
}
int main(){

	Qalbaz();

	int t, ans;
	cin >> t;
	while (t--)
	{
		ans = 0;
		cin >> n >> m;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				cin >> arr[i][j];
		for (int i = 0; i < m; i++)
		{
			memset(dp, -1, sizeof dp);
			ans = max(ans, solve(0, i));
		}
		cout << ans << "\n";
	}

	return 0;
}