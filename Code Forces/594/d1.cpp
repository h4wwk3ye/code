/*
				C++
				encoding: UTF-8
				Last Modified: 20/Oct/2019 04:34:33 PM

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

int n;
string s;

int swapCount () {
	ve< int > stk;
	int cnt = 0;
	fr (i, 0, n) {
		if (s[i] == '(') {
			stk.pb (i);
		} else {
			if (stk.empty ()) {
				cnt++;
			} else {
				stk.pop_back ();
			}
		}
	}
	if (cnt == 0 and len (stk) == 0) return 0;
	if (cnt == 1 and len (stk) == 1) return 1;
	return -1;
}

signed main () {
	cin >> n;
	cin >> s;
	string tmp = s;
	int ans;
	int cnt = 0;
	fr (i, 0, n) {
		reverse (s.begin (), s.begin () + 1);
		reverse (s.begin () + 1, s.end ());
		reverse (s.begin (), s.end ());
		// pr (s);
		ans = swapCount ();
		if (ans == 0) break;
		if (ans == 1) tmp = s;
		cnt++;
	}
	s = tmp;
	ans = swapCount ();

	if (ans == -1) {
		pr (0);
		pr (1, 1);
		return 0;
	}
	if (ans == 1) {
		int op = 0;
		int p, q;
		ve< int > stk;
		fr (i, 0, n) {
			if (s[i] == '(') {
				stk.pb (i);
			} else {
				if (stk.empty ()) {
					q = i;
				} else {
					stk.pop_back ();
				}
			}
		}
		p = stk[0];
		swap (s[p], s[q]);
		// pr (s);
		stk.clear ();
		fr (i, 0, n) {
			if (s[i] == '(') {
				stk.pb (i);
			} else {
				stk.pop_back ();
				if (stk.empty ()) op++;
			}
		}
		pr (op);
		pr ((p + cnt) % n + 1, (q + cnt) % n + 1);
		return 0;
	}

	ve< int > stk;
	int op = 0;
	fr (i, 0, n) {
		if (s[i] == '(') {
			stk.pb (i);
		} else {
			stk.pop_back ();
			if (stk.empty ()) op++;
		}
	}

	int c = 0;
	ve< int > arr (n, 0);
	fr (i, 0, n) {
		if (s[i] == '(') {
			c++;
		} else {
			c--;
		}
		arr[i] = c;
	}
	int p = 1, q = 1;
	fr (i, 1, n - 2) {
		if (arr[i - 1] == 1 and arr[i] == 2 and arr[i + 1] == 1 and arr[i + 2] == 0) {
			if (s[i - 1] == '(' and s[i] == '(' and s[i + 1] == ')' and s[i + 2] == ')') {
				op++;
				p = i;
				q = i + 1;
				break;
			}
		}
	}
	pr (op);
	pr ((p + cnt) % n + 1, (q + cnt) % n + 1);
	return 0;
}
