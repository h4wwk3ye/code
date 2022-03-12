/*
				C++
				encoding: UTF-8
				Modified: <07/Aug/2019 10:16:34 AM>

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
#define         mod                    1000000007
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

template < typename T, typename... TAIL > void pr (const T& t, TAIL... tail) {
    cout << t << " ";
    pr (tail...);
}

// clang-format on

const int N = 1e5 + 5;
int n;
int c[N], h[N], a[N], b[N];

signed main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	int tc;
	cin >> tc;
	while (tc--) {
		cin >> n;
		fr (i, 1, n + 2) a[i] = b[i] = 0;
		fr (i, 1, n + 1) cin >> c[i];
		fr (i, 1, n + 1) cin >> h[i];

		fr (i, 1, n + 1) {
			r = i + c[i];
			a[i]++;
			if (r < n) a[r + 1]--;
		}

		dfr (i, n, 0) {
			l = i - c[i];
			b[i]++;
			if (l > 1) b[l - 1]--;
		}

		fr (i, 1, n + 1) a[i] += a[i - 1];
		dfr (i, n, 0) b[i] += b[i + 1];

		fr (i, 1, n + 1) {
			a[i] += b[i];
			a[i]--;
		}
		sort (a + 1, a + n + 1);
		sort (h + 1, h + n + 1);

		string ans = "YES";
		fr (i, 1, n + 1) {
			if (a[i] != h[i]) {
				ans = "NO";
				break;
			}
		}
		pr (ans);
	}
	return 0;
}
