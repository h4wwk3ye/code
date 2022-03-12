/*
				C++
				encoding: UTF-8
				Modified: <07/Oct/2019 01:45:52 PM>

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
int arr[N];
int bit[N][2];
int n, q;

void update (int i, int val) {
	while (i <= n) {
		bit[i][0] += val;
		bit[i][1] *= val;
		i += (i & (-i));
	}
}

ve< int > query (int i) {
	ve< int > ans = {0, 1};

	while (i > 0) {
		ans[0] += bit[i][0];
		ans[1] *= bit[i][1];
		i -= (i & (-i));
	}
	return ans;
}

signed main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	int tc;
	cin >> tc;
	while (tc--) {
		cin >> n >> q;
		fr (i, 0, n + 5) {
			bit[i][0] = 0;
			bit[i][1] = 1;
		}
		string s;
		cin >> s;
		fr (i, 1, n + 1) {
			if (s[i - 1] == 'O') {
				arr[i] = 1;
			} else {
				arr[i] = 2;
			}
			update (i, arr[i]);
		}
		while (q--) {
			int t, l, r;
			cin >> t >> l >> r;
			ve< int > a = query (l - 1);
			ve< int > b = query (r);

			if (t == 1) {
				int x = (b[0] - a[0]);
				if (x & 1) {
					pr ("O");
				} else {
					pr ("E");
				}
			} else {
				int x = b[1] / a[1];
				if (x & 1) {
					pr ("O");
				} else {
					pr ("E");
				}
			}
		}
	}
	return 0;
}
