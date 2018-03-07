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

void clear_string(string &str)
{
	string st = "";
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			st += str[i];
		else if (str[i] >= 'A' && str[i] <= 'Z')
			st += tolower(str[i]);
	}
	str = st;
}

int main(){

	Qalbaz();

	int t;
	cin >> t;
	string str;
	int mn;
	map<char, int>mp;
	int test = 0;
	while (t--)
	{
		cin >> str;
		mp.clear();
		mn = 1e8;
		for (int i = 0; i < str.size(); i++)
		{
			mp[str[i]]++;
		}
		mp['A'] = mp['A'] / 3;
		mp['R'] = mp['R'] / 2;
		mn = min(mn, mp['M']);
		mn = min(mn, mp['A']);
		mn = min(mn, mp['R']);
		mn = min(mn, mp['G']);
		mn = min(mn, mp['I']);
		mn = min(mn, mp['T']);
		cout << mn << "\n";
	}

	return 0;
}