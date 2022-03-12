/*
				C++
				encoding: UTF-8
				Modified: <30/Jul/2019 12:58:27 AM>

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

const int N = 2e5 + 5;
ll n, q, block_size;
ll arr[N], answer[N];
ll counter[(int)1e6 + 5];

ll mo_left = 0, mo_right = -1, ans = 0;

bool cmp (const ve< ll >& x, const ve< ll >& y) {
	if (x[0] / block_size != y[0] / block_size) return x[0] < y[0];
	return x[1] < y[1];
}

signed main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	cin >> n >> q;
	fr (i, 1, n + 1) cin >> arr[i];
	block_size = sqrt (n);
	ve< ll > queries[q];
	fr (i, 0, q) {
		ll l, r;
		cin >> l >> r;
		queries[i] = {l, r, i};
	}
	sort (queries, queries + q, cmp);

	for (auto query : queries) {
		ll &l = query[0], &r = query[1], &idx = query[2];
		while (mo_right != r) {
			if (mo_right < r) {
				mo_right++;
				ll& num = arr[mo_right];
				ans -= counter[num] * counter[num] * num;
				counter[num]++;
				ans += counter[num] * counter[num] * num;
			} else {
				ll& num = arr[mo_right];
				ans -= counter[num] * counter[num] * num;
				counter[num]--;
				ans += counter[num] * counter[num] * num;
				mo_right--;
			}
		}

		while (mo_left != l) {
			if (mo_left > l) {
				mo_left--;
				ll& num = arr[mo_left];
				ans -= counter[num] * counter[num] * num;
				counter[num]++;
				ans += counter[num] * counter[num] * num;
			} else {
				ll& num = arr[mo_left];
				ans -= counter[num] * counter[num] * num;
				counter[num]--;
				ans += counter[num] * counter[num] * num;
				mo_left++;
			}
		}
		answer[idx] = ans;
	}

	fr (i, 0, q) cout << answer[i] << "\n";

	return 0;
}
