//#pragma GCC optimize("-O3")
/*
				C++
				encoding: UTF-8
				Last Modified: 12/Apr/20 05:53:27 PM
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
	int n;
	cin >> n;
	string s;
	cin >> s;
	ve< ve< int > > cnt (n + 1, ve< int > (3));
	cnt[0][0] = cnt[0][1] = cnt[0][2] = 0;
	fr (i, 1, n + 1) {
		cnt[i] = cnt[i - 1];
		if (s[i - 1] == 'R') {
			cnt[i][0]++;
		} else if (s[i - 1] == 'G') {
			cnt[i][1]++;
		} else {
			cnt[i][2]++;
		}
	}

	int ans = 0;

	fr (i, 1, n) {
		fr (j, i + 1, n) {
			if (s[i - 1] == s[j - 1]) continue;

			if ((s[i - 1] == 'R' and s[j - 1] == 'G') or (s[i - 1] == 'G' and s[j - 1] == 'R')) { // find k count ahead of j
				ans += cnt[n][2] - cnt[j][2];

				int r = j - i;
				if (j + r > n) continue;
				if (s[j + r - 1] == 'B') ans--;
			} else if ((s[i - 1] == 'B' and s[j - 1] == 'G') or (s[i - 1] == 'G' and s[j - 1] == 'B')) {
				ans += cnt[n][0] - cnt[j][0];

				int r = j - i;
				if (j + r > n) continue;
				if (s[j + r - 1] == 'R') ans--;
			} else {
				ans += cnt[n][1] - cnt[j][1];

				int r = j - i;
				if (j + r > n) continue;
				if (s[j + r - 1] == 'G') ans--;
			}
		}
	}
	pr (ans);

	return 0;
}