/*
				C++
				encoding: UTF-8
				Modified: <27/Aug/2019 12:37:11 PM>

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
#define         endl                   "\n";
#define         ff                     first
#define         ss                     second
#define         pii                    pair<int, int>
#define         len(v)                 int(v.size())
#define         all(v)                 v.begin(), v.end()
#define         reset(a, b)            memset(a, b, sizeof(a));
#define         fr(i, s, n)            for (int i = s ; i < n ; ++i)
#define         dfr(i, s, n)           for (int i = s ; i > n ; --i)

void pr () {
    cout << "\n";
}

template < typename T, typename... ARGS > void pr (const T& t, ARGS... args) {
    cout << t << " ";
    pr (args...);
}

// clang-format on


signed main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	int n, m, q;
	cin >> n >> m >> q;

	deque< pair< deque< int >, pii > > arr;
	deque< int > to_place;

	pair< deque< int >, pii > zero;
	zero = make_pair (to_place, make_pair (0, 0));

	int ans = 0;
	fr (i, 0, n) {
		deque< int > curr;
		int x = 0, y = 0;
		fr (j, 0, m) {
			char c;
			cin >> c;
			curr.pb (c - '0');
			if (c == '1') {
				y = 1;
				x++;
				ans++;
			}
		}
		arr.pb (make_pair (curr, make_pair (x, y)));
	}


	while (q--) {
		int t;
		cin >> t;
		if (t == 1) {
			int x, y;
			cin >> x >> y;

			int c = 0;

			while (y > 0) {
				auto it = arr.begin ();
				c += it->ss.ff;
				arr.pop_front ();
				arr.pb (zero);
				y--;
			}

			while (y < 0) {
				auto it = arr.end ();
				it--;
				c += (it->ss).ff;
				arr.pop_back ();
				arr.push_front (zero);
				y++;
			}

			ans -= c;
			if (x > 0) {
				auto it = arr.begin ();
				fr (i, 0, n) {
					if ((it->ss).ss) {
						int tmp = x;
						int c = 0;
						while (tmp > 0) {
							c += (it->ff).front ();
							(it->ff).pop_front ();
							(it->ff).push_back (0);
							tmp--;
						}
						(it->ss).ff -= c;
						ans -= c;
						if ((it->ss).ff == 0) (it->ss).ss = 0;
					}
					it++;
				}
			}
			if (x < 0) {
				auto it = arr.end ();
				it--;
				fr (i, 0, n) {
					if ((it->ss).ss) {
						int tmp = x;
						int c = 0;
						while (tmp < 0) {
							c += (it->ff).back ();
							(it->ff).pop_back ();
							(it->ff).push_front (0);
							tmp++;
						}
						(it->ss).ff -= c;
						ans -= c;
						if ((it->ss).ff == 0) (it->ss).ss = 0;
					}
					it--;
				}
			}
		} else {
			pr (ans);
		}
	}

	return 0;
}
