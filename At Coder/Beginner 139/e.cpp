/*
				C++
				encoding: UTF-8
				Last Modified: 2019/09/01 19:15:33

*/

#include <bits/stdc++.h>
#ifdef LOCAL_PROJECT
#	include <prettypr.hpp>
#endif

using namespace std;

// clang-format off

#define		 ll                     long long
#define		 ve                     vector
#define		 pb                     push_back
#define		 endl                   "\n";
#define		 ff                     first
#define		 ss                     second
#define		 pii                    pair<int, int>
#define		 len(v)                 int(v.size())
#define		 all(v)                 v.begin(), v.end()
#define		 reset(a, b)            memset(a, b, sizeof(a));
#define		 fr(i, s, n)            for (int i = s ; i < n ; ++i)
#define		 dfr(i, s, n)           for (int i = s ; i > n ; --i)

void pr () {
    cout << "\n";
}

template < typename T, typename... ARGS > void pr (const T& t, ARGS... args) {
    cout << t << " ";
    pr (args...);
}

// clang-format on

signed main () {
	// ios_base::sync_with_stdio (false), cin.tie (nullptr);
	int n;
	cin >> n;
	ve< deque< int > > arr (n + 1);
	fr (i, 1, n + 1) {
		deque< int > tmp;
		fr (j, 1, n) {
			int x;
			cin >> x;
			tmp.pb (x);
		}
		arr[i] = (tmp);
	}
	bool flag = 0;
	bool f = 0;
	int ans = 0;
	int j = 1;
	int x = n;
	while (x > 0) {
		int cnt = 0;
		unordered_set< int > s;
		s.max_load_factor (0.25);
		s.reserve (n + 1);
	here:
		f = 0;
		fr (i, 1, n + 1) {
			if (arr[i].empty ()) {
				if (j == i) j++;
				continue;
			}
			int x = arr[i].front ();
			if (s.find (x) != s.end ()) continue;
			if (arr[x].empty ()) {
				pr (-1);
				return 0;
			}
			int y = arr[x].front ();
			if (s.find (y) != s.end ()) continue;
			if (y == i) {
				s.insert (x);
				s.insert (y);
				arr[i].pop_front ();
				arr[x].pop_front ();
				f = 1;
				// i--;
			}
		}
		if (f == 1) goto here;
		if (f == 0) break;
		ans++;
	}
	fr (i, 1, n + 1) {
		if (len (arr[i]) != 0) flag = 1;
	}
	if (flag) {
		pr (-1);
	} else {
		int mx = 0;
		pr (ans);
	}
	return 0;
}
