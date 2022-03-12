/*
				C++
				encoding: UTF-8
				Modified: <31/Aug/2019 08:52:54 PM>

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
		int n, k;
		cin >> n >> k;
		int arr[n];
		fr (i, 0, n) cin >> arr[i];

		if (k == 2) {
			int ans[n];
			bool flag = 0;
			int j;
			fr (i, 0, n) {
				if (arr[i] != -1) {
					flag = 1;
					j = i;
					ans[i] = arr[i];
					break;
				}
			}
			if (!flag) {
				pr ("YES");
				int f = 0;
				fr (i, 0, n) {
					if (f == 0)
						cout << 1 << " ";
					else
						cout << 2 << " ";
					f = 1 - f;
				}
				cout << endl;
			} else {
				int f;
				if (arr[j] == 1)
					f = 0;
				else
					f = 1;
				dfr (i, j - 1, -1) {
					if (f == 0) {
						ans[i] = 2;
					} else {
						ans[i] = 1;
					}
					f = 1 - f;
				}
				if (arr[j] == 1)
					f = 0;
				else
					f = 1;
				fr (i, j + 1, n) {
					if (f == 0) {
						ans[i] = 2;
					} else {
						ans[i] = 1;
					}
					f = 1 - f;
				}

				string op = "YES";
				fr (i, 1, n) {
					if (arr[i] != -1 and ans[i] != arr[i]) {
						op = "NO";
						break;
					}
					if (ans[i] == ans[i - 1]) {
						op = "NO";
						break;
					}
				}
				if (op == "YES") {
					pr (op);
					fr (i, 0, n) cout << ans[i] << " ";
					cout << endl;
				} else {
					pr (op);
				}
			}
		} else {
			int ans[n];
			bool flag_ = 1;
			fr (i, 0, n) {
				if (arr[i] != -1) {
					ans[i] = arr[i];
				} else {
					int a = -1, b = -1;
					if (i > 0) a = ans[i - 1];
					if (i + 1 < n) b = arr[i + 1];

					bool flag = 1;
					fr (j, 1, k + 1) {
						if (j != a and j != b) {
							ans[i] = j;
							flag = 0;
							break;
						}
					}
					if (flag) {
						flag_ = 0;
						break;
					}
				}
			}
			if (!flag_) {
				pr ("NO");
				continue;
			}
			string op = "YES";
			fr (i, 1, n) {
				if (ans[i] == ans[i - 1]) {
					op = "NO";
				}
			}
			if (op == "YES") {
				pr (op);
				fr (i, 0, n) cout << ans[i] << " ";
				cout << endl;
			} else {
				pr (op);
			}
		}
	}
	return 0;
}
