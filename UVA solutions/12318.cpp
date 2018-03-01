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
	cout << fixed << setprecision(4);
}
 
 
 
int main(){
 
	Qalbaz();
 
	int n, m, k;
	vi vec;
	ll ans, power;
	set<int>st;
	while (cin >> n >> m)
	{
		if (n == 0 && m == 0)
			break;
		st.clear();
		cin >> k;
		vec.resize(k + 1);
		for (int i = 0; i <= k; i++)
			cin >> vec[i];
		n++;
		for (int i = 0; i <= m; i++)
		{
			ans = vec[0];
			power = 1;
			for (int j = 1; j <= k; j++)
			{
				power *= i;
				power = power % n;
				ans = ans + power * vec[j];
				ans = ans % n;
			}
			st.insert(ans);
		}
		cout << (int)st.size() << "\n";
	}
 
	return 0;
}