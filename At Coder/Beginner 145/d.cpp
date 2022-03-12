//#pragma GCC optimize("-O3")
/*
				C++
				encoding: UTF-8
				Last Modified: 16/Nov/19 07:09:00 PM
*/

#include <bits/stdc++.h>
#ifdef H4wk3ye
#	include <prettypr.hpp>
#endif

using namespace std;

// clang-format off

#define		int                    long long
#define		ve                     vector
#define		pb                     push_back
#define		endl                   "\n"
#define		ff                     first
#define		ss                     second
#define		pii                    pair<int, int>
#define		len(v)                 (int)v.size()
#define		all(v)                 v.begin(), v.end()
#define		reset(a, b)            memset(a, b, sizeof(a));
#define		fr(i, s, n)            for (int i = s ; i < n ; ++i)
#define		dfr(i, s, n)           for (int i = s ; i > n ; --i)

template < typename T > void pr (const T& t) {
    cout << t << "\n";
}

template < typename T, typename U, typename... ARGS >
void pr (const T& t, const U& u, const ARGS&... args) {
    cout << t << " ";
    pr (u, args...);
}

// clang-format on

 int dp[1000][1000];
const int mod = 1e9 + 7;
int x, y;
const int N = 1e6 + 5;
int fact[N];

int power (int a, int b, int m) {
	int r = 1;
	while (b) {
		if (b & 1) r = (r * a) % m;
		b >>= 1;
		a = (a * a) % m;
	}
	return r;
}


int ncr(int n, int r){
	if (r==0) return 1;
	return (fact[n]* power(fact[r], mod-2, mod) % mod * 
            power(fact[n-r],mod-2, mod) % mod) % mod; 
}

signed main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	cin >> x >> y;
	if (x==1 and y==1){
		pr(1);
		return 0;
	}
	dp[0][0] = 1;
	fr (i, 1, 100) {
		fr (j, 1, 100) {
			if (i == 1 and j == 1) continue;
			if (i == 1) dp[i][j] = dp[i - 1][j - 2];
			if (j == 1)
				dp[i][j] = dp[i - 2][j - 1];
			else
				dp[i][j] = (dp[i - 1][j - 2] + dp[i - 2][j - 1]) % mod;
		}
	}
	cout << "  ";
	fr (i, 0, 30) cout << i << " ";
	cout << "\n";
	fr (i, 0, 40) {
		cout << i << " ";
		fr (j, 0, 40) {
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}
	
	fact[0] = 1;
	fr (i, 1, N) {
		fact[i] = (fact[i - 1] * i) % mod;
	}

	if ((x+y)%3!=0){
		pr(0);
		return 0;
	}

	if (x<y) swap(x, y);
	if (x&1){
		if (y<x/2+2){
			pr(0);
			return 0;
		}
	}else{
		if (y<x/2){
			pr(0);
			return 0;
		}
	}
	if (x&1){
		pr(ncr(x/2 +2, y/2 + 2));
	} else {
		pr(ncr(x/3 * 3, y/3 * 3));
	}
	
	return 0;
}