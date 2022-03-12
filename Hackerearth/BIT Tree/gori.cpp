/*
				C++
				encoding: UTF-8
				Modified: <01/Oct/2019 03:25:27 PM>

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
int n, q, k;
int bit[N];

void update (int x, int val) {
	for (; x <= n; x += x & (-x)) {
		if (val >= k) bit[x]++;
	}
}

int query (int x) {
	int ans = 0;
	for (; x > 0; x -= x & (-x)) {
		ans += bit[x];
	}
	return ans;
}

signed main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	cin >> n >> q >> k;
	fr (i, 1, n + 1) cin >> arr[i];
	while (q--) {
		int t;
		cin >> t;
		if (t == 0) {
			int x, y;
			cin >> x >> y;
			arr[x] = y;
			update (x, y);
		} else {
			int a, b, c, d;
			cin >> a >> b >> c >> d;
			if (c > b or d < a) {
				pr (-1);
			} else {
				if (c >= a) {
					int x = query (c);
					int y = query (b - 1);
					if (y - x >= k) {
						pr ("Propose");
					} else {
						pr ("Do not propose");
					}
				} else {
					int x = query (a);
					int y = query (d - 1);
					if (y - x >= k) {
						pr ("Propose");
					} else {
						pr ("Do not propose");
					}
				}
			}
		}
	}
	return 0;
}
