/*
				C++
				encoding: UTF-8
				Modified: <18/Sep/2019 10:09:13 PM>

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

signed main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	string s;
	cin >> s;
	int n = len (s);
	ve< int > arr (26, 0);

	fr (i, 0, n) {
		int x = (s[i] - 'a');
		bool flag = 0;
		fr (j, 0, x) {
			if (arr[j] != 0) {
				flag = 1;
				break;
			}
		}
		if (flag) {
			pr ("Ann");
		} else {
			pr ("Mike");
		}
		arr[s[i] - 'a'] = 1;
	}
	return 0;
}
