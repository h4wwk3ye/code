/*
				C++
				encoding: UTF-8
				Modified: <26/Aug/2019 08:37:51 PM>

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

signed main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	int tc;
	cin >> tc;
	while (tc--) {
		int n, m;
		cin >> n >> m;
		int person[n + 1];
		fr (i, 1, n + 1) cin >> person[i];
		int health[m + 1];
		fr (i, 1, m + 1) cin >> health[i];
		ve< int > ans (n + 1, -1);
		fr (i, 1, m + 1) {
			int j = i;
			while (j <= n) {
				if (ans[j] == -1 and person[j] <= health[i]) ans[j] = i;
				j += i;
			}
		}
		fr (i, 1, n + 1) pr (ans[i]);
	}
	return 0;
}
