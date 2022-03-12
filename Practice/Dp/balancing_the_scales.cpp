/*
				C++
				encoding: UTF-8
				Modified: <28/Aug/2019 12:03:05 PM>

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

ve< int > dp;
int n, l, d, w;


signed main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	int tc;
	cin >> tc;
	while (tc--) {
		cin >> n >> l >> d;
		ve< int > weights;
		string s;
		w = 0;
		int base = 1;
		for (auto i : s) {
			if (i == '1') w += base;
			base *= 2;
		}

		fr (i, 0, n) {
			int weight = 1 << i;
			if (weight > w) break;
			weights.pb (weight);
		}
		dp.resize (n, -1);
		dp[0] = 1;
		fr (i, 0, n) {
			for (auto weight : weights) {
				if (weight > i) break;
				dp[i] += dp[i - weight];
			}
		}
		pr (dp[w]);
	}
	return 0;
}
