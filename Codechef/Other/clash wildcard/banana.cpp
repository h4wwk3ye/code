/*
				C++
				encoding: UTF-8
				Modified: <18/Sep/2019 08:19:40 PM>

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
#define int long long
ve< ve< int > > arr;
ve< ve< int > > dp;
int r, c, k;

int solve (int i, int j) {
	if (i >= r or j < 0 or j >= c) return -1e9;
	if (i == r - 1) return arr[i][j];

	int& ans = dp[i][j];
	if (ans != -1) return ans;

	ans = max (ans, arr[i][j] + max (0LL, max (solve (i + 1, j - 1), solve (i + 1, j + 1))));

	ans = max (ans, arr[i][j] + max (0LL, max (solve (i + k + 1, j - 1), solve (i + k + 1, j + 1))));

	return ans;
}

signed main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	int tc;
	cin >> tc;
	while (tc--) {
		cin >> r >> c >> k;
		arr.clear ();
		dp.clear ();

		arr.resize (r + 5, ve< int > (c + 5, 0));
		dp.resize (r + 5, ve< int > (c + 5, -1));

		fr (i, 0, r) {
			fr (j, 0, c) {
				cin >> arr[i][j];
			}
		}

		int ans = 0;
		fr (i, 0, c) {
			// dp.resize (r, ve< int > (c, -1));
			ans = max (ans, solve (0, i));
		}
		pr (ans);
	}
	return 0;
}
