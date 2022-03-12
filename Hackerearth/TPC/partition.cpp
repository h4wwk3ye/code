//#pragma GCC optimize("-O3")
/*
				C++
				encoding: UTF-8
				Last Modified: 08/Mar/20 09:41:54 PM
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

int n;
string s;
const int N = 1e4 + 5;


signed main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	cin >> n;
	cin >> s;
	ve< int > cnt (N, 0);
	int t = 0;
	fr (i, 1, n + 1) {
		cnt[i] = cnt[i - 1];
		if (s[i - 1] == '1') {
			cnt[i]++;
			t++;
		}
	}
	if (t & 1) {
		pr (-1);
		return 0;
	}

	int ans = 0, mod = 1e9 + 7;
	ve< int > x;
	fr (i, 1, n + 1) {
		if (cnt[i] == 0 or (cnt[i] & 1)) {
			if (ans) x.pb (ans);
			ans = 0;
			continue;
		}
		if (cnt[i] != cnt[n]) {
			ans++;
		}
	}
	int a = 1;
	for (auto& i : x) {
		a *= i;
		a %= mod;
	}
	pr (a);

	return 0;
}