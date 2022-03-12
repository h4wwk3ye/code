/*
				C++
				encoding: UTF-8
				Modified: <16/Oct/2019 10:01:38 AM>

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

#define         int                    long long
#define         ve                     vector
#define         pb                     push_back
#define         endl                   "\n"
#define         ff                     first
#define         ss                     second
#define         pii                    pair<int, int>
#define         len(v)                 (int)v.size()
#define         all(v)                 v.begin(), v.end()
#define         reset(a, b)            memset(a, b, sizeof(a));
#define         fr(i, s, n)            for (int i = s ; i < n ; ++i)
#define         dfr(i, s, n)           for (int i = s ; i > n ; --i)

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
	// ios_base::sync_with_stdio (false), cin.tie (nullptr);
	int n;
	cin >> n;
	ve< int > arr (n, 0), color (n, 0);
	fr (i, 0, n) cin >> arr[i];
	sort (all (arr));
	// pr ("here");
	int c = 0;
	fr (i, 0, n) {
		if (color[i]) continue;
		c++;
		fr (j, i, n + 1) {
			if (arr[j] % arr[i] == 0) {
				color[j] = c;
			}
		}
	}
	unordered_set< int > s;
	fr (i, 0, n) {
		int c = color[i];
		s.insert (c);
	}

	pr (len (s));
	return 0;
}
