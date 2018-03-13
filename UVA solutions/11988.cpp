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
//#pragma warning (disable : 4996)
void Qalbaz()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(7);
}


int main(){

	Qalbaz();

	string str, st1 = "",st2 = "";
	int z = 1;
	while (getline(cin, str)){
		for (int i = 0; i < str.size(); i++)
		{
			if (str[i] == '['){
				if (st2.size() > 0)
					st1 = st2 + st1;
				st2.clear();
				z = 0;
				continue;
			}
			else if(str[i] == ']'){
				if (st2.size() > 0)
					st1 = st2 + st1;
				st2.clear();
				z = 1;
				continue;
			}
			if (z == 1){
				if(st2.size() > 0)
					st1 = st2 + st1;
				st1.push_back(str[i]);
				st2 = "";
			}
			else{
				st2.push_back(str[i]);
			}
		}
		if (st2.size() > 0)
			st1 = st2 + st1;
		cout << st1 << "\n";
		st1 = st2 = "";
		z = 1;
	}
	
	return 0;
}