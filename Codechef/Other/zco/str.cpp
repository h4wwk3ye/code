//#pragma GCC optimize("-O3")
/*
				C++
				encoding: UTF-8
				Last Modified: 04/Mar/20 12:00:25 PM
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


signed main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	int n, k;
	cin >> n >> k;
	string p;
	cin >> p;
	vector< int > pi (n, 0);

	for (int i = 1; i < n; ++i) {
		int j = pi[i - 1];
		while (j > 0 and p[i] != p[j])
			j = pi[j - 1];
		if (p[i] == p[j]) j++;
		pi[i] = j;
	}
	if (!pi.back ()) {
		string ans;
		fr (i, 0, k) cout << p;
		cout << endl;
	} else {
		string tmp;
		fr (i, pi.back (), n) tmp += p[i];
		cout << p;
		fr (i, 1, k) cout << tmp;
		cout << endl;
	}
	return 0;
}