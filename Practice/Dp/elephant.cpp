/*
				C++
				encoding: UTF-8
				Modified: <24/Aug/2019 06:40:37 PM>

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

long double dp[51][51][101]; // iteration, index, color

signed main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	int tc;
	cin >> tc;
	while (tc--) {
		reset (dp, 0.0);
		int n, c, k;
		cin >> n >> c >> k;
		fr (i, 1, n + 1) dp[0][i][1] = 1;

		fr (iteration, 1, k + 1) {
			int l, r;
			cin >> l >> r;
			fr (index, 1, n + 1) {
				fr (color, 0, c) {
					if (index >= l and index <= r) {
						fr (m, 0, c) {
							int new_color = (m * j) % c;
							dp[iteration][index][new_color] += dp[iteration - 1][index][color];
						}
						dp[iteration][index][color] += dp[iteration - 1][index][color] * 0.5;
					} else {
						dp[iteration][index][color] = dp[iteration - 1][index][color];
					}
				}
			}
		}

		long double ans = 0;
		fr (i, 1, n + 1)
	}
	return 0;
}
