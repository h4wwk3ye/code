/*
				C++
				encoding: UTF-8
				Modified: <08/Sep/2019 04:05:26 PM>

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
#define int long long

int solve (vector< int > Arr) {
	int n = Arr.size ();
	set< pair< int, int > > s;
	for (int i = 0; i < n; i++) {
		if (Arr[i] & 1 == 0) {
			int tmp = Arr[i];
			while (tmp & 1 == 0) {
				s.insert ({tmp, i});
				tmp /= 2;
			}
			s.insert ({tmp, i});
		} else {
			s.insert ({Arr[i], i});
			s.insert ({Arr[i] * 2, i});
		}
	}
	int ans = 1e18;
	auto itr2 = s.begin ();
	for (auto itr1 = s.begin (); itr1 != s.end (); itr1++) {
		itr2 = itr1;
		itr2++;
		if (itr2 == s.end ()) break;
		while ((*itr1).second == (*itr2).second) {
			itr2++;
			if (itr2 == s.end ()) break;
			itr1++;
		}
		ans = min (ans, abs ((*itr1).first - (*itr2).first));
		if (ans == 0) break;
	}
	return ans;
}

signed main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	int tc;
	cin >> tc;
	while (tc--) {
		int n;
		cin >> n;
		ve< int > arr (n);
		fr (i, 0, n) cin >> arr[i];
		int out_ = solve (arr);
		cout << out_ << "\n";
	}
	return 0;
}
