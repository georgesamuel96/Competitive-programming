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
#define EPS 1e-9
#define PI 3.14159265359
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

	vl powers, sum;
	ll p = 2;
	sum.push_back(0);
	powers.push_back(0);
	while (sum[sum.size() - 1] <= 1e15)
	{
		powers.push_back(p);
		p = p * 2LL;
		sum.push_back(powers[powers.size() - 1] + sum[sum.size() - 1]);
	}
	int t, test = 1;
	cin >> t;
	ll k;
	while (t--)
	{
		cin >> k;

		ll index = 0;
		while (sum[index] < k)
			index++;
		ll from = sum[index - 1] + 1, to = sum[index], mid, ans;
		while (from <= to)
		{
			mid = (from + to) / 2;
			if (mid < k)
				from = mid + 1;
			else if (mid > k)
				to = mid - 1;
			else
			{
				ans = mid;
				break;
			}
		}
		string str;
		ans -= sum[index - 1] + 1;

		while (ans)
		{
			if (ans % 2 == 0)
				str.push_back('5');
			else
				str.push_back('6');
			ans /= 2;
		}
		int numberOfDigits = 0;
		index = powers[index] - 1;
		while (index)
			numberOfDigits++, index /= 2;
		while (str.size() < numberOfDigits)
			str.push_back('5');
		for (int i = str.size() - 1; i >= 0; i--)
			cout << str[i];

		cout << "\n";
	}

	return 0;
}