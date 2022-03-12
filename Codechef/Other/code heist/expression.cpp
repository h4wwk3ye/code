//#pragma GCC optimize("-O3")
/*
				C++
				encoding: UTF-8
				Last Modified: 07/Jan/20 11:17:41 PM
*/

#include <bits/stdc++.h>
#ifdef H4wk3ye
#	include <prettypr.hpp>
#endif

using namespace std;

// clang-format off

#define		int                    long long
#define		ve                     vector
#define		pb                     push_back
#define		endl                   "\n"
#define		ff                     first
#define		ss                     second
#define		pii                    pair<int, int>
#define		len(v)                 (int)v.size()
#define		all(v)                 v.begin(), v.end()
#define		reset(a, b)            memset(a, b, sizeof(a));
#define		fr(i, s, n)            for (int i = s ; i < n ; ++i)
#define		dfr(i, s, n)           for (int i = s ; i > n ; --i)

template < typename T > void pr (const T& t) {
    cout << t << "\n";
}

template < typename T, typename U, typename... ARGS >
void pr (const T& t, const U& u, const ARGS&... args) {
    cout << t << " ";
    pr (u, args...);
}

// clang-format on


struct item {
	int left;
	char mn, curr;
	item () {
		mn = '-1';
	}
};


signed main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);

	int tc;
	cin >> tc;
	while (tc--) {
		ve< item > st;
		string s;
		cin >> s;
		ve< pii > to_remove;
		item tmp;
		st.pb (tmp);
		fr (j, 0, len (s)) {
			char& i = s[i];
			if (i != '(' and i != ')' and i != '+' and i != '-' and i != '/' and i != '*') {
				if (i == '(') {
					item tmp;
					tmp.left = j;
					st.pb (tmp);
				} else if (i == ')') {
					item& tmp = st.back ();
					st.pop_back ();
					char right_operator = '-1';
					if (j + 1 != len (s)) {
						char& x = s[j + 1];
						if (x == '+' or x == '-' or x == '*' or x == '/') {
							right_operator = x;
						}
					}

					if (tmp.mn == '-1' and right_operator == '-1') {
						to_remove.pb ({tmp.left, j});
					} else {
						if (right_operator != '1') {
						}
					}

				} else {
					item& tmp = st.back ();
					if (tmp.mn == '-1') {
						tmp.mn = i;
					} else {
						if (tmp.mn == '/') {
							tmp.mn = i;
						} else if (tmp.mn == '*' and i != '/') {
							tmp.mn = i;
						} else if ((tmp.mn == '+' or tmp.mn == '-') and (i != '/' or i != '-')) {
							tmp.mn = i;
						}
					}
					tmp.curr = i;
				}
			}
		}
	}


	return 0;
}