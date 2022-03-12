//#pragma GCC optimize("-O3")
/*
				C++
				encoding: UTF-8
				Last Modified: 21/Apr/20 09:24:22 PM
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
	int tc;
	cin >> tc;
	int mx = 0;
	ve< int > prefix;
	int ans;
	auto overlap = [&] (vector< pii >& intervals) {
		int ans = 0;
		int count = 0;

		prefix.assign (mx + 5, 0);

		fr (i, 0, len (intervals)) {
			prefix[intervals[i].ff]++;
			prefix[intervals[i].ss + 1]--;
		}

		fr (i, 1, len (prefix)) {
			prefix[i] += prefix[i - 1];
			ans = max (ans, prefix[i]); // max overlapping intervals
		}
	};

	while (tc--) {
		int n, k;
		cin >> n >> k;
		mx = 0;
		ans = 0;
		ve< int > arr (n);
		fr (i, 0, n) cin >> arr[i];
		ve< pii > intervals;
		map< int, int > mp;
		fr (i, 0, n / 2) {
			intervals.pb ({min (arr[i], arr[n - i - 1]) + 1, max (arr[i], arr[n - i - 1]) + k});
			mx = max (mx, max (arr[i], arr[n - i - 1]) + k);
			mp[arr[i] + arr[n - i - 1]]++;
		}
		overlap (intervals);

		int changes = 1e18;
		fr (i, 1, len (prefix)) {
			// anything outsie i have to contribute twice
			int k = n / 2 - prefix[i];
			int curr = 2 * k;

			// everything inside has to contribute once
			curr += prefix[i];

			// subtracting those that already have sum i
			curr -= mp[i];

			changes = min (changes, curr);
			// pr (i, prefix[i], k);
		}
		pr (changes);
	}
	return 0;
}