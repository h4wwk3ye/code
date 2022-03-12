/*
				C++
				encoding: UTF-8
				Modified: <18/Aug/2019 11:19:41 PM>

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

template < typename T, typename... TAIL > void pr (const T& t, TAIL... tail) {
    cout << t << " ";
    pr (tail...);
}

// clang-format on

signed main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	int tc;
	cin >> tc;
	while (tc--) {
		int n, q;
		cin >> n >> q;
		string s;
		cin >> s;
		int dp[n + 1][26];
		reset (dp, 0);
		set< int > se;
		fr (i, 1, n + 1) {
			fr (j, 0, 26) dp[i][j] = dp[i - 1][j];
			dp[i][s[i - 1] - 'a']++;
			if (i >= 3) {
				if (dp[i][s[i - 1] - 'a'] - dp[i - 3][s[i - 1] - 'a'] >= 2) {
					se.insert (i);
					// pr (s[i - 1], i);
				}
			}
		}
		// pr (se);
		/*fr (i, 1, n + 1) {
			fr (j, 0, 26) {
				cout << dp[i][j] << " ";
			}
			cout << endl;
		}*/
		while (q--) {
			int l, r;
			cin >> l >> r;
			string ans = "NO";
			auto it = se.upper_bound (l);
			if (it == se.end ()) {
				pr (ans);
				continue;
			}
			while (it != se.end ()) {
				if (*it > r) break;
				if (*it - l >= 3) {
					ans = "YES";
					break;
				}
				it++;
			}
			pr (ans);
		}
	}
	return 0;
}
