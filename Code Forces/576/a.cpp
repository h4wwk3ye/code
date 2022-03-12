/*
				C++
				encoding: UTF-8
				Modified: <30/Jul/2019 08:09:47 PM>

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
#define         mod                    1000000007
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
	int n, x, y;
	cin >> n >> x >> y;
	int arr[n + 1];
	fr (i, 1, n + 1) cin >> arr[i];
	fr (i, 1, n + 1) {
		bool flag = true;
		fr (j, max (1, i - x), i) if (arr[i] >= arr[j]) flag = false;
		fr (j, i + 1, min (n, i + y) + 1) if (arr[i] >= arr[j]) flag = false;
		if (flag) {
			pr (i);
			return 0;
		}
	}
	return 0;
}
