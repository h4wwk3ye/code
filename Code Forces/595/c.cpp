/*
				C++
				encoding: UTF-8
				Last Modified: 22/Oct/2019 08:59:30 PM
*/

#include <bits/stdc++.h>
#ifdef LOCAL_PROJECT
#	include <prettypr.hpp>
#endif

using namespace std;

// clang-format off

#define		 int                    long long
#define		 ve                     vector
#define		 pb                     push_back
#define		 endl                   "\n"
#define		 ff                     first
#define		 ss                     second
#define		 pii                    pair<int, int>
#define		 len(v)                 (int)v.size()
#define		 all(v)                 v.begin(), v.end()
#define		 reset(a, b)            memset(a, b, sizeof(a));
#define		 fr(i, s, n)            for (int i = s ; i < n ; ++i)
#define		 dfr(i, s, n)           for (int i = s ; i > n ; --i)

template < typename T > void pr (const T& t) {
    cout << t << "\n";
}

template < typename T, typename U, typename... ARGS >
void pr (const T& t, const U& u, const ARGS&... args) {
    cout << t << " ";
    pr (u, args...);
}

// clang-format on

const int N = 1e5 + 5;
set< int > dp;
ve< int > p;
set< pii > mp;

void solve (int i, int j) {
	if (i >= len (p)) return;
	if (mp.find ({i, j}) != mp.end ()) return;
	mp.insert ({i, j});
	dp.insert (p[i] + j);
	solve (i + 1, j);
	solve (i + 1, j + p[i]);
}

signed main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	fr (i, 0, 30) {
		p.pb (pow (3, i));
	}
	solve (0, 0);
	int tc;
	cin >> tc;
	while (tc--) {
		int n;
		cin >> n;
		auto it = dp.lower_bound (n);
		pr (*it);
	}
	return 0;
}
