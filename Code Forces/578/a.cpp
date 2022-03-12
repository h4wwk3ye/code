/*
				C++
				encoding: UTF-8
				Modified: <11/Aug/2019 06:10:48 PM>

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

template < typename T, typename... TAIL > void pr (const T& t, TAIL... tail) {
    cout << t << " ";
    pr (tail...);
}

// clang-format on

int arr[10];

signed main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	int n;
	cin >> n;
	string s;
	cin >> s;
	fr (i, 0, n) {
		if (s[i] == 'L') {
			fr (j, 0, 10) {
				if (arr[j] == 0) {
					arr[j] = 1;
					break;
				}
			}
		} else if (s[i] == 'R') {
			dfr (j, 9, -1) {
				if (arr[j] == 0) {
					arr[j] = 1;
					break;
				}
			}
		} else {
			arr[s[i] - '0'] = 0;
		}
	}
	fr (i, 0, 10) cout << arr[i];
	cout << endl;
	return 0;
}
