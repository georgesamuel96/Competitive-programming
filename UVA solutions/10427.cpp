#define _CRT_SECURE_NO_WARNINGS
#includeiostream
#includesstream
#includevector
#includealgorithm
#includestring.h
#includeset
#includefstream
#includemap
#includestring
#include stdio.h
#includebitset
#includequeue
#includeiomanip
#includecmath
#includestack
#includeclimits
 
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vectorllvl;
typedef vectorintvi;
typedef vectorboolvb;
typedef vectordoublevd;
typedef vectorcharvc;
typedef vectorstringvs;
#define MP make_pair
#define all(v) v.begin(),v.end()
const ll mod = 1000000007;
const ll OO = (ll)1e18;
const int dx[] = { 0, 1, -1, 0, 1, -1, 1, -1 };
const int dy[] = { 1, 0, 0, -1, 1, -1, -1, 1 };
ll gcd(ll a, ll b){ if (b == 0){ return a; }return gcd(b, a % b); }
ll fast_power(double base, ll power){
	if (power == 1) return base;
	if (power % 2 == 0) return fast_power((basebase), power  2);
	else return(basefast_power((basebase), power  2));
}
#pragma warning (disable  4996)
void Qalbaz()
{
#ifndef ONLINE_JUDGE
	freopen(input.txt, r, stdin);
	freopen(output.txt, w, stdout);
#endif
	ios_basesync_with_stdio(0); cin.tie(0); cout.tie(0);
	cout  fixed  setprecision(4);
}
 
int arr[100000000 + 1], numbers[9];
 
int main(){
 
	Qalbaz();
 
	int z = 1, num, ind = 1, j;
	while (true)
	{
		num = z;
		j = 0;
		while (num)
		{
			numbers[j++] = num % 10;
			num = num  10;
		}
		j--;
		while (j  -1 && ind  100000000 + 1)
			arr[ind] = numbers[j--], ind++;
		if (ind = 100000000)
			break;
		z++;
	}
	int n;
	while (cin  n)
	{
		cout  arr[n]  n;
	}
 
	return 0;
}