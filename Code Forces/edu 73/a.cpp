/*
				C++
				encoding: UTF-8
				Modified: <19/Sep/2019 08:14:38 PM>

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

#define         ll                     long long
#define         ve                     vector
#define         pb                     push_back
#define         endl                   "\n"
#define         ff                     first
#define         ss                     second
#define         pii                    pair<int, int>
#define         len(v)                 int(v.size())
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
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	int tc;
	cin >> tc;
	while (tc--) {
		int n;
		cin >> n;
		multiset< int > s;
		bool f = 0;
		int mn = 1e9;
		fr (i, 0, n) {
			int x;
			cin >> x;
			if (x == 2048) f = 1;
			s.insert (x);
			mn = min (mn, x);
		}
		if (f) {
			pr ("Yes");
			continue;
		}
		if (mn > 2048) {
			pr ("No");
			continue;
		}
		if (n == 1) {
			int x = *s.begin ();
			if (x == 2048) {
				pr ("Yes");
			} else {
				pr ("No");
			}
		} else {
			bool flag = 0;
			while (len (s) != 1) {
				auto it = s.begin ();
				int x = *it;
				s.erase (it);
				it = s.begin ();
				int y = *it;
				s.erase (it);
				// pr (x, y);
				if (x != y) {
					s.insert (y);
					continue;
				}
				if (x + y == 2048) {
					flag = 1;
					pr ("Yes");
					break;
				}
				s.insert (x + y);
			}
			if (!flag) {
				auto it = s.begin ();
				if (*it == 2048) {
					pr ("Yes");
				} else {
					pr ("No");
				}
			}
		}
	}
	return 0;
}
