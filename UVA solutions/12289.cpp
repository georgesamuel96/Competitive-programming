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

int main(){

	Qalbaz();

	int t;
	cin >> t;
	string str, st;
	int x, y;
	while (t--)
	{
		cin >> str;
		if (str.size() > 3)
			cout << "3\n";
		else
		{
			x = 0;
			st = "one";
			for (int i = 0; i < 3; i++)
			{
				if (str[i] == st[i])
					x++;
			}
			st = "two";
			y = 0;
			for (int i = 0; i < 3; i++)
			{
				if (str[i] == st[i])
					y++;
			}
			if (x == 3)
				cout << "1\n";
			else if (y == 3)
				cout << "2\n";
			else if (x == 2)
				cout << "1\n";
			else
				cout << "2\n";
		}
	}

	return 0;
}