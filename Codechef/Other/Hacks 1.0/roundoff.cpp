/*
				C++
				encoding: UTF-8
				Modified: <16/Oct/2019 10:13:20 AM>

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
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	int tc;
	cin >> tc;
	while (tc--) {
		string s;
		cin >> s;
		int c;
		cin >> c;
		int n = len (s);
		if (len (s) >= c) {
			while (len (s) > c) {
				int sum = 0;
				for (int i = n - 1; i >= n - c; i--) {
					sum += (s[i] - '0');
				}
				while (sum > 10) {
					int t = sum;
					sum = 0;
					while (t > 0) {
						sum += t % 10;
						t /= 10;
					}
				}
				if (sum >= c) {
					string tem (s.begin (), s.begin () + n - c);
					s.clear ();
					s = tem;
					s.pb ('0' + c);
				} else {
					string tem (s.begin (), s.begin () + n - c);
					s.clear ();
					s = tem;
				}
			}
		}
		while (len (s) < c) {
			s.pb ('0');
		}
		fr (i, 0, c) cout << s[i];
		cout << endl;
	}
	return 0;
}
