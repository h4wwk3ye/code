/*
				C++
				encoding: UTF-8
				Last Modified: 17/Oct/2019 06:04:17 PM

				✪ H4WK3yE乡
				Mohd. Farhan Tahir
				Indian Institute Of Information Technology (IIIT), Gwalior
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

signed main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	int n;
	cin >> n;
	int arr[n];
	fr (i, 0, n) cin >> arr[i];
	sort (arr, arr + n);
	int pref[n];
	pref[0] = arr[0];

	fr (i, 1, n) {
		pref[i] = pref[i - 1] + arr[i];
	}

	int tc;
	cin >> tc;
	while (tc--) {
		int k;
		cin >> k;
		if (k == 0) {
			pr (pref[n - 1]);
			continue;
		}
		int j = ceil (n * 1.0 / (k + 1));
		// pr (j);
		pr (pref[j - 1]);
	}
	return 0;
}
