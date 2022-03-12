/*
				C++
				encoding: UTF-8
				Modified: <01/Oct/2019 12:31:05 AM>

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

const int N = 55;
int arr[N];
int n, x;


signed main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	int tc;
	cin >> tc;
	while (tc--) {
		cin >> x >> n;

		int p = x;

		int i = 1, j = 1;
		int f = 0;

		ve< pii > possible;


		while (1) {
			if (((n * (n - 1)) / 2) * j >= p) break;
			i = 1;
			while (1) {
				int c = ((n * i) + (((n * (n - 1)) / 2) * j));
				if (c == p) {
					f = 1;
					possible.pb ({i, j});
					break;
				}
				if (c > p) break;
				i++;
			}
			j++;
			if (f) break;
		}
		if (len (possible) == 0) {
			cout << "N\n";
		} else {
			sort (all (possible));
			pr ("Y", possible[0].ss);
		}
	}
	return 0;
}
