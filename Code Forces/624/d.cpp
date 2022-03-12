//#pragma GCC optimize("-O3")
/*
				C++
				encoding: UTF-8
				Last Modified: 24/Feb/20 09:34:07 PM
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
	// ios_base::sync_with_stdio (false), cin.tie (nullptr);
	int tc;
	cin >> tc;
	while (tc--) {
		int a, b, c;
		cin >> a >> b >> c;

		if (a == b == c) {
			pr (0);
			pr (a, b, c);
			continue;
		}


		auto change = [&]() -> vector< int > {
			ve< int > ans (4, 1e18);
			int p, curr, w, q, x, r, y, s, z;
			dfr (i, a, 0) {
				curr = a - i;

				p = (b / i) * i;
				w = abs (b - p);

				if (p == 0) goto second;

				q = (c / p) * p;
				x = abs (c - q);

				r = (c / p) * p + p;
				y = abs (r - c);

				s = (c / p) * p - p;
				z = abs (s - c);

				if (ans[0] > curr + w + x and i > 0 and p > 0 and q > 0) {
					ans = {curr + w + x, i, p, q};
				}
				if (ans[0] > curr + w + y and i > 0 and p > 0 and r > 0) {
					ans = {curr + w + y, i, p, r};
				}
				if (ans[0] > curr + w + z and i > 0 and p > 0 and s > 0) {
					ans = {curr + w + z, i, p, s};
				}


			second:
				p = (b / i) * i;
				p += i;
				w = abs (b - p);

				if (p == 0) goto third;

				q = (c / p) * p;
				x = abs (c - q);

				r = (c / p) * p;
				r += p;
				y = abs (r - c);

				s = (c / p) * p - p;
				z = abs (s - c);

				if (ans[0] > curr + w + x and i > 0 and p > 0 and q > 0) {
					ans = {curr + w + x, i, p, q};
				}
				if (ans[0] > curr + w + y and i > 0 and p > 0 and r > 0) {
					ans = {curr + w + y, i, p, r};
				}
				if (ans[0] > curr + w + z and i > 0 and p > 0 and s > 0) {
					ans = {curr + w + z, i, p, s};
				}

			third:
				p = (b / i) * i;
				p -= i;
				w = abs (b - p);

				if (p == 0) continue;

				q = (c / p) * p;
				x = abs (c - q);

				r = (c / p) * p;
				r += p;
				y = abs (r - c);

				s = (c / p) * p - p;
				z = abs (s - c);

				if (ans[0] > curr + w + x and i > 0 and p > 0 and q > 0) {
					ans = {curr + w + x, i, p, q};
				}
				if (ans[0] > curr + w + y and i > 0 and p > 0 and r > 0) {
					ans = {curr + w + y, i, p, r};
				}
				if (ans[0] > curr + w + z and i > 0 and p > 0 and s > 0) {
					ans = {curr + w + z, i, p, s};
				}
			}

			fr (i, a + 1, 1e4 + 1) {
				curr = abs (a - i);

				p = (b / i) * i;
				w = abs (b - p);

				if (p == 0) goto second1;

				q = (c / p) * p;
				x = abs (c - q);

				r = (c / p) * p + p;
				y = abs (r - c);

				s = (c / p) * p - p;
				z = abs (s - c);

				if (ans[0] > curr + w + x and i > 0 and p > 0 and q > 0) {
					ans = {curr + w + x, i, p, q};
				}
				if (ans[0] > curr + w + y and i > 0 and p > 0 and r > 0) {
					ans = {curr + w + y, i, p, r};
				}
				if (ans[0] > curr + w + z and i > 0 and p > 0 and s > 0) {
					ans = {curr + w + z, i, p, s};
				}


			second1:
				p = (b / i) * i;
				p += i;
				w = abs (b - p);

				if (p == 0) goto third1;

				q = (c / p) * p;
				x = abs (c - q);

				r = (c / p) * p;
				r += p;
				y = abs (r - c);

				s = (c / p) * p - p;
				z = abs (s - c);

				if (ans[0] > curr + w + x and i > 0 and p > 0 and q > 0) {
					ans = {curr + w + x, i, p, q};
				}
				if (ans[0] > curr + w + y and i > 0 and p > 0 and r > 0) {
					ans = {curr + w + y, i, p, r};
				}
				if (ans[0] > curr + w + z and i > 0 and p > 0 and s > 0) {
					ans = {curr + w + z, i, p, s};
				}

			third1:
				p = (b / i) * i;
				p -= i;
				w = abs (b - p);

				if (p == 0) continue;

				q = (c / p) * p;
				x = abs (c - q);

				r = (c / p) * p;
				r += p;
				y = abs (r - c);

				s = (c / p) * p - p;
				z = abs (s - c);

				if (ans[0] > curr + w + x and i > 0 and p > 0 and q > 0) {
					ans = {curr + w + x, i, p, q};
				}
				if (ans[0] > curr + w + y and i > 0 and p > 0 and r > 0) {
					ans = {curr + w + y, i, p, r};
				}
				if (ans[0] > curr + w + z and i > 0 and p > 0 and s > 0) {
					ans = {curr + w + z, i, p, s};
				}
			}
			return ans;
		};

		ve< int > ans = change ();
		pr (ans[0]);
		fr (i, 1, 4) cout << ans[i] << " ";
		cout << endl;
	}
	return 0;
}