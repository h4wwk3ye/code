/*
				C++
				encoding: UTF-8
				Modified: <18/Sep/2019 09:32:30 PM>

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
#define int long long

const int N = 1e5 + 5;
int arr[N];
int n;
unordered_map< int, int > tree[4 * N];
int delta[N];

#define left node << 1;
#define right left + 1;
void build (int node = 1, int start = 0, int end = n - 1) {
	if (start == end) {
		tree[node][arr[start]]++;
		return;
	}
	int mid = (start + end) >> 1;
	build (left, start, mid);
	build (right, mid + 1, end);
	for (aut)
}

signed main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);


	cin >> n;
	fr (i, 0, n) {
		cin >> arr[i];
		if (i > 1) {
			delta[i] = (((arr[i] - 1) * arr[i]) / 2) - (((i - 1) * i) / 2);
			delta[i] = max (delta[i], 0);
		}
	}

	int tc;
	cin >> tc;
	while (tc--) {
		int m, l, r;
		cin >> m >> l >> r;
		if (m == 1) {
			int ans = query (l, r);
			pr (ans);
		} else {
			update (l, r);
		}
	}
	return 0;
}
