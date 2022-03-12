/*
				C++
				encoding: UTF-8
				Modified: <11/Oct/2019 07:47:40 PM>

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

signed main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	int tc;
	cin >> tc;
	while (tc--) {
		int n;
		cin >> n;
		int x = (n * (n - 1)) / 2;
		if (x % n) {
			pr ("NO");
		} else {
			int y = x / n;
			int arr[n][n];
			fr (i, 0, n) fr (j, 0, n) arr[i][j] = 0;
			fr (i, 0, n) {
				int cnt = y;
				fr (j, i + 1, n) {
					if (cnt == 0) break;
					arr[i][j] = 1;
					cnt--;
				}
				fr (j, 0, n) {
					if (cnt == 0) break;
					arr[i][j] = 1;
					cnt--;
				}
			}
			pr ("YES");
			fr (i, 0, n) {
				fr (j, 0, n) {
					cout << arr[i][j];
				}
				cout << endl;
			}
		}
	}
	return 0;
}
