/*
				C++
				encoding: UTF-8
				Modified: <19/Sep/2019 09:35:01 PM>

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
int n;
const int N = 3e5 + 5;
pii arr[N];

int dp[N][3];

int solve (int i, int k) {
	if (i == n + 1) {
		return 0;
	}

	int& ans = dp[i][k];
	if (ans != -1) return ans;

	if (i > 1) {
		if (arr[i].ff == arr[i - 1].ff + k) {
			ans = min (solve (i + 1, 1) + arr[i].ss, solve (i + 1, 2) + arr[i].ss * 2);
		} else if (arr[i].ff + 1 == arr[i - 1].ff + k) {
			ans = min (solve (i + 1, 0), solve (i + 1, 2) + arr[i].ss * 2);
		} else if (arr[i].ff + 2 == arr[i - 1].ff + k) {
			ans = min (solve (i + 1, 0), solve (i + 1, 1) + arr[i].ss);
		} else {
			ans =
			min (solve (i + 1, 0), min (solve (i + 1, 1) + arr[i].ss, solve (i + 1, 2) + 2 * arr[i].ss));
		}
	} else {
		ans =
		min (solve (i + 1, 0), min (solve (i + 1, 1) + arr[i].ss, solve (i + 1, 2) + 2 * arr[i].ss));
	}

	return ans;
}

signed main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	int tc;
	cin >> tc;
	while (tc--) {
		cin >> n;
		fr (i, 1, n + 1) {
			int x, y;
			cin >> x >> y;
			arr[i] = {x, y};

			fr (k, 0, 3) {
				dp[i][k] = -1;
			}
		}
		if (n == 1) {
			pr (0);
			continue;
		}
		pr (solve (1, 0));
	}
	return 0;
}
