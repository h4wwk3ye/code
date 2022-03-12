/*
				C++
				encoding: UTF-8
				Modified: <18/Aug/2019 10:37:37 PM>

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
		int n;
		cin >> n;
		int arr[n][n];
		fr (i, 0, n) {
			string tmp;
			cin >> tmp;
			fr (j, 0, n) {
				arr[i][j] = tmp[j] - '0';
			}
		}
		pii cnt[n];
		fr (i, 0, n) {
			int x = 0;
			fr (j, 0, n / 2) if (arr[i][j] == 1) x++;
			cnt[i].ff = x;
			x = 0;
			fr (j, n / 2, n) if (arr[i][j] == 1) x++;
			cnt[i].ss = x;
		}
		int s1 = 0, s2 = 0;
		fr (i, 0, n) {
			s1 += cnt[i].ff;
			s2 += cnt[i].ss;
		}
		int ans = abs (s1 - s2);
		if (s1 == s2) {
			pr (0);
			continue;
		}
		int mn = abs (s1 - s2), idx = 0;
		fr (i, 0, n) {
			if (abs ((s1 - cnt[i].ff + cnt[i].ss) - (s2 - cnt[i].ss + cnt[i].ff)) < mn) {
				mn = abs ((s1 - cnt[i].ff + cnt[i].ss) - (s2 - cnt[i].ss + cnt[i].ff));
				idx = i;
			}
		}

		s1 -= cnt[idx].ff;
		s1 += cnt[idx].ss;
		s2 -= cnt[idx].ss;
		s2 += cnt[idx].ff;
		pr (min (ans, abs (s1 - s2)));
	}
	return 0;
}
