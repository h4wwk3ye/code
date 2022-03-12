/*
				C++
				encoding: UTF-8
				Modified: <28/Aug/2019 11:15:06 AM>

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

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
typedef cc_hash_table< int, int, hash< int > > ht;

signed main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	int n;
	cin >> n;
	int arr[n + 1];
	ht mp;
	int flag = 1;
	int cnt = 0;
	fr (i, 1, n + 1) {
		cin >> arr[i];
		mp[arr[i]]++;
		if (mp[arr[i]] > 1) flag = 0;
	}
	if (flag) {
		pr (0);
		return 0;
	}

	int ans = n - 1;
	fr (i, 1, n + 1) {
		int low = i, high = n + 1;
		while (low <= high) {
			int mid = (low + high + 1) / 2;
			flag = 1;
			mp.clear ();
			fr (j, 1, i) {
				mp[arr[j]]++;
				if (mp[arr[j]] > 1) {
					flag = 0;
					break;
				}
			}
			if (flag) {
				fr (j, mid + 1, n + 1) {
					mp[arr[j]]++;
					if (mp[arr[j]] > 1) {
						flag = 0;
						break;
					}
				}
			}

			if (flag) {
				high = mid - 1;
				ans = min (ans, mid - i + 1);
				// pr (low, high, mid, i, ans);
			} else
				low = mid + 1;
		}
	}
	pr (ans);
	return 0;
}
