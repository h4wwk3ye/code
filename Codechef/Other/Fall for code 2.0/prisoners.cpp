/*
				C++
				encoding: UTF-8
				Modified: <02/Oct/2019 11:47:37 PM>

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
const int N = 1e5 + 5;
int arr[N + 1], xor_[N + 1], pref_xor[N + 1];

signed main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	int tc;
	cin >> tc;
	while (tc--) {
		int n, q;
		cin >> n >> q;
		pref_xor[0] = 0;
		fr (i, 1, n + 1) {
			cin >> arr[i];
			pref_xor[i] = pref_xor[i - 1] ^ arr[i];
		}
		ve< int > chk[n + 1];
		fr (i, 1, n + 1) {
			xor_[i] = pref_xor[n] ^ pref_xor[i - 1];
		}
	}
	return 0;
}
