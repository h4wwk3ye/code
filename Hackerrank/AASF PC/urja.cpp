/*
				C++
				encoding: UTF-8
				Modified: <28/Sep/2019 01:00:08 PM>

				Mohd. Farhan Tahir
				Indian Institute Of Information Technology (IIIT), Gwalior
*/

#include <bits/stdc++.h>
#ifdef LOCAL_PROJECT
#	include <prettypr.hpp>
#endif

using namespace std;

// clang-format off

#define         int                    long long
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
pii arr[N];
int n, x;

int chk (int mid) {
	int curr = 0;
	fr (i, 1, n + 1) {
		if (arr[i].ff <= mid and arr[i].ss >= mid) {
			curr += mid;
		}
	}
	if (curr == x) return 0;
	if (curr > x) return 1;
	return 2;
}

signed main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	cin >> n >> x;
	int low = 1e18, high = 0;
	fr (i, 1, n + 1) {
		cin >> arr[i].ff >> arr[i].ss;
		low = min (low, arr[i].ff);
		high = max (high, arr[i].ss);
	}

	int ans;
	if (n == 1) {
		pr (0);
		return 0;
	}

	while (low <= high) {
		int mid = (low + high) >> 1;
		// pr (low, mid, high, chk (mid));

		int t = chk (mid);
		if (t == 0) {
			ans = mid;
			high = mid - 1;
		} else if (t == 1) {
			high = mid - 1;
		} else {
			low = mid + 1;
		}
	}

	int mn = 1;
	fr (i, 1, n + 1) {
		if (arr[i].ff <= ans and arr[i].ss >= ans) {
			continue;
		} else {
			mn = 0;
		}
	}
	// pr (mn);
	if (mn == 1) {
		pr (0);
		return 0;
	}
	pr (ans);
	return 0;
}
