/*
				C++
				encoding: UTF-8
				Modified: <10/Oct/2019 02:19:23 PM>

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

const int N = 1e5 + 5;
int n;
int dp[N][20];

void init () {
	fr (i, 0, N) {
		fr (j, 0, 20) {
			dp[i][j] = -1;
		}
	}
}

void add (int node, int parent) {
	dp[node][0] = parent;
	fr (i, 1, 20) {
		dp[node][i] = dp[dp[node][i - 1]][i - 1];
		if (dp[node][i] == -1) return;
	}
}

signed main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	int tc;
	cin >> tc;
	while (tc--) {
		cin >> n;
		init ();
		fr (i, 1, n + 1) {
			int x, y;
			cin >> x >> y;
			add (x, y);
		}
		int q;
		cin >> q;
		while (q--) {
			int t;
			cin >> t;
			if (t == 0) {
				int x, y;
				cin >> y >> x;
				add (x, y);
			} else if (t == 1) {
				int x;
				cin >> x;
				fr (i, 0, 20) dp[x][i] = -1;
			} else {
				int x, k;
				cin >> x >> k;
				dfr (i, 19, -1) {
					if ((1 << i) <= k) {
						k -= (1 << i);
						x = dp[x][i];
						if (x == -1) break;
					}
				}
				x = max (x, 0);
				pr (x);
			}
		}
	}
	return 0;
}
