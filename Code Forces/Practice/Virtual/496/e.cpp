/*
				C++
				encoding: UTF-8
				Last Modified: 17/Oct/2019 03:49:41 PM

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

#define		 int                    long long
#define		 ve                     vector
#define		 pb                     push_back
#define		 endl                   "\n"
#define		 ff                     first
#define		 ss                     second
#define		 pii                    pair<int, int>
#define		 len(v)                 (int)v.size()
#define		 all(v)                 v.begin(), v.end()
#define		 reset(a, b)            memset(a, b, sizeof(a));
#define		 fr(i, s, n)            for (int i = s ; i < n ; ++i)
#define		 dfr(i, s, n)           for (int i = s ; i > n ; --i)

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
	int n, m;
	cin >> n >> m;
	int arr[n];
	int idx;
	fr (i, 0, n) {
		cin >> arr[i];
		if (arr[i] == m) idx = i;
	}

	ve< int > pref1 (idx), pref2 (n - idx - 1);

	dfr (i, idx - 1, -1) {
		if (arr[i] < m)
			pref1[i] = -1;
		else
			pref1[i] = 1;
	}
	dfr (i, idx - 2, -1) {
		pref1[i] += pref1[i + 1];
	}

	fr (i, 0, n - idx - 1) {
		if (arr[idx + i + 1] < m)
			pref2[i] = -1;
		else
			pref2[i] = 1;
	}
	fr (i, 1, n - idx - 1) {
		pref2[i] += pref2[i - 1];
	}


	map< int, int > mp;
	for (auto i : pref2) {
		mp[i]++;
	}

	int ans = 1;
	for (auto i : pref1) {
		if (i == 0 or i == 1) {
			ans++;
		}
		if (mp.find (-i) != mp.end ()) {
			ans += mp[-i];
		}
		if (mp.find (-i + 1) != mp.end ()) {
			ans += mp[-i + 1];
		}
	}
	ans += mp[0];
	ans += mp[1];
	pr (ans);
	return 0;
}
