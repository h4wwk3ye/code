/*
				C++
				encoding: UTF-8
				Last Modified: 17/Oct/2019 04:51:18 PM

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

const int N = 1e4 + 5;
int arr[N];
unordered_map< int, int > mp;
int n;
int answer[N], ans;

void init () {
	fr (i, 0, n + 5) {
		ans[i] = 0;
	}
	mp.clear ();
	mp.max_load_factor (0.25);
	ans = 0;
}

const int block_size = 400;

bool cmp (ve< int >& a, ve< int >& b) {
	if (a[0] / block_size != b[0] / block_size) return a[0] < b[0];
	return a[1] < b[1];
}

int mo_left = 0, mo_right = -1;

signed main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	int tc;
	cin >> tc;
	while (tc--) {
		cin >> n;
		init ();
		int p = 0;
		fr (i, 1, n + 1) {
			int x;
			cin >> x;
			if (mp.find (x) == mp.end ()) {
				p++;
				mp[x] = p;
			}
			arr[i] = mp[x];
		}
		int m;
		cin >> m;
		ve< int > queries[m];
		fr (i, 0, m) {
			int l, r;
			cin >> l >> r;
			queries[i] = {l, r, i};
		}
		sort (queries, queries + m, cmp);

		for (auto& q : queries) {
			int &l = q[0], &r = q[1], &idx = q[2];
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
	}
	return 0;
}
