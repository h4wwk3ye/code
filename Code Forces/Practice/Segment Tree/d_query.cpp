/*
				C++
				encoding: UTF-8
				Modified: <04/Oct/2019 01:48:37 PM>

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
#define         mod                    1000000007
#define         ve                     vector
#define         pb                     push_back
#define         endl                   "\n";
#define         ff                     first
#define         ss                     second
#define         pii                    pair<int, int>
#define         len(v)                 int(v.size())
#define         all(v)                 v.begin(), v.end()
#define         reset(a, b)            memset(a, b, sizeof(a));
#define         fr(i, s, n)            for (ll i = s ; i < n ; ++i)
#define         dfr(i, s, n)           for (ll i = s ; i > n ; --i)

void pr () {
    cout << "\n";
}

template < typename T, typename... TAIL > void pr (const T& t, TAIL... tail) {
    cout << t << " ";
    pr (tail...);
}

// clang-format on

const int N = 1e6 + 5;
ll n, q, block_size;
ll arr[N], answer[N];
ll counter[N];

ll mo_left = 0, mo_right = -1, ans = 0;

bool cmp (const ve< ll >& x, const ve< ll >& y) {
	if (x[0] / block_size != y[0] / block_size) return x[0] < y[0];
	return x[1] < y[1];
}

signed main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	cin >> n;
	fr (i, 1, n + 1) cin >> arr[i];
	block_size = sqrt (n);
	cin >> q;
	ve< ll > queries[q];
	fr (i, 0, q) {
		ll l, r;
		cin >> l >> r;
		queries[i] = {l, r, i};
	}
	sort (queries, queries + q, cmp);

	int ans = 0;
	for (auto query : queries) {
		ll &l = query[0], &r = query[1], &idx = query[2];

		while (mo_right != r) {
			if (mo_right < r) {
				mo_right++;
				ll& num = arr[mo_right];
				counter[num]++;
				if (counter[num] == 1) ans++;
			} else {
				ll& num = arr[mo_right];
				counter[num]--;
				if (counter[num] == 0) ans--;
				mo_right--;
			}
		}

		while (mo_left != l) {
			if (mo_left > l) {
				mo_left--;
				ll& num = arr[mo_left];
				counter[num]++;
				if (counter[num] == 1) ans++;
			} else {
				ll& num = arr[mo_left];
				counter[num]--;
				if (counter[num] == 0) ans--;
				mo_left++;
			}
		}
		answer[idx] = ans;
	}

	fr (i, 0, q) cout << answer[i] << "\n";

	return 0;
}
