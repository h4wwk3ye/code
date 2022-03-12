/*
				C++
				encoding: UTF-8
				Modified: <20/Sep/2019 10:50:52 PM>

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
		int arr[n + 1];
		fr (i, 1, n + 1) cin >> arr[i];
		int x;
		cin >> x;
		ve< int > a (n + 2, 0), b (n + 2, 0);
		fr (i, 1, n + 1) {
			a[i] = arr[i] + a[i - 1];
		}
		dfr (i, n, 0) {
			b[i] = arr[i] + b[i + 1];
		}


		ve< long double > aa (n + 2, 0), bb (n + 2, 0);

		fr (i, 2, n + 1) {
			aa[i] = ((a[i - 1] * 1.0) / x);
			// aa[i]++;
		}
		dfr (i, n - 1, 0) {
			bb[i] = (long double)(b[i + 1]);
			// bb[i]++;
		}

		/*fr (i, 1, n + 1) {
			cout << aa[i] << " ";
		}
		cout << endl;
		dfr (i, n, 0) {
			cout << bb[i] << " ";
		}
		cout << endl;*/
		int ans1 = 1, ans2 = 1;
		fr (i, 2, n) {
			// pr (aa[i], bb[i]);
			if (aa[i] < bb[i]) {
				ans1++;
			} else if (bb[i] < aa[i]) {
				ans2++;
			} else {
				if (i >= ceil ((n * 1.0) / 2)) {
					ans1++;
				} else {
					ans2++;
				}
			}
		}
		pr (ans1, ans2);
	}
	return 0;
}
