/*
				C++
				encoding: UTF-8
				Modified: <27/Sep/2019 09:31:03 PM>

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

bool cmp (string& a, string& b) {
	return len (a) < len (b);
}

signed main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	string s;
	cin >> s;

	unordered_map< char, int > mp;
	for (auto i : s) {
		mp[i]++;
	}

	int n;
	cin >> n;
	string arr[n];
	fr (i, 0, n) cin >> arr[i];
	sort (arr, arr + n, cmp);

	int ans = 0;

	fr (i, 0, n) {
		bool flag = true;
		unordered_map< char, int > tmp;
		for (auto p : mp) {
			tmp[p.ff] = p.ss;
		}
		fr (j, 0, len (arr[i])) {
			if (tmp.find (arr[i][j]) == tmp.end () or tmp[arr[i][j]] == 0) {
				flag = false;
				break;
			}
			tmp[arr[i][j]]--;
		}
		if (flag) {
			// pr (arr[i]);
			fr (j, 0, len (arr[i])) {
				mp[arr[i][j]]--;
			}
			ans++;
		}
	}
	pr (ans);

	return 0;
}
