/*
				C++
				encoding: UTF-8
				Modified: <22/Aug/2019 08:25:06 PM>

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
	int n, m;
	cin >> n >> m;
	int a[n + 1][m + 1];
	fr (i, 1, n + 1) fr (j, 1, m + 1) cin >> a[i][j];
	int b[n + 1][m + 1];
	reset (b, 0);
	ve< pii > ans;
	fr (i, 1, n + 1) {
		fr (j, 1, m + 1) {
			if (i < n and j < m) {
				if (a[i][j] == 1 and a[i + 1][j] == 1 and a[i][j + 1] == 1 and a[i + 1][j + 1] == 1) {
					ans.pb ({i, j});
					b[i][j] = 1;
					b[i + 1][j] = 1;
					b[i][j + 1] = 1;
					b[i + 1][j + 1] = 1;
				}
			}
		}
	}

	int flag = 1;
	fr (i, 1, n + 1) {
		fr (j, 1, m + 1) {
			if (a[i][j] != b[i][j]) {
				flag = 0;
				break;
			}
		}
	}
	if (flag) {
		pr (len (ans));
		for (auto x : ans) {
			pr (x.ff, x.ss);
		}
	} else
		pr (-1);
	return 0;
}
