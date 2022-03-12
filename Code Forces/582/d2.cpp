/*
				C++
				encoding: UTF-8
				Modified: <30/Aug/2019 09:56:15 PM>

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

#define         int                    long long
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

int n, k;
const int N = 2e5 + 5;
int arr[N];

int check (int x, int j) {
	int cnt = 0;
	int ans = 0;
	fr (i, j, n) {
		if (arr[i] < x) continue;
		if (arr[i] == x) {
			cnt++;
		} else {
			int tmp = arr[i];
			int p = 0;
			while (tmp > x) {
				p++;
				tmp /= 2;
			}
			if (tmp == x) {
				ans += p;
				cnt++;
			}
		}
		if (cnt == k) break;
	}
	if (cnt == k) return ans;
	return 2e18;
}

signed main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	cin >> n >> k;
	set< int > s;
	fr (i, 0, n) {
		cin >> arr[i];
		s.insert (arr[i]);
	}
	sort (arr, arr + n);

	unordered_map< int, int > mp;
	fr (i, 0, n) {
		mp[arr[i]]++;
		if (mp[arr[i]] == k) {
			pr (0);
			return 0;
		}
	}

	int ans = check (0, 0);
	for (int i : s) {
		int j = lower_bound (arr, arr + n, i) - arr;
		if (n - j < k) break;
		ans = min (ans, check (i, j));
		if (ans == 0) break;
		// pr (ans, i, j);
	}
	pr (ans);
	return 0;
}
