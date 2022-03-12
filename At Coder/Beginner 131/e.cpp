/*
				C++
				encoding:UTF-8
				Modified: <22/Jun/2019 07:21:39 PM>

				✪ H4WK3yE乡
				Mohd. Farhan Tahir
				Indian Institute Of Information Technology (IIIT), Gwalior
*/

#include <bits/stdc++.h>

using namespace std;

// clang-format off

#define		 ll                     long long
#define		 mod                    1000000007
#define		 ve                     vector
#define		 pb                     push_back
#define		 umap                   unordered_map
#define		 pq                     priority_queue
#define		 endl                   "\n";
#define		 ff                     first
#define		 ss                     second
#define		 pii                    pair<int, int>
#define		 len(v)                 int(v.size())
#define		 all(v)                 v.begin(), v.end()
#define		 reset(a, b)            memset(a, b, sizeof(a));
#define		 sum(v)                 accumulate(v.begin(), v.end(), (ll)0);
#define		 pr1(x)                 cout<<x<<"\n"
#define		 pr2(x, y)              cout<<x<<" "<<y<<"\n"
#define		 pr3(x, y, z)           cout<<x<<" "<<y<<" "<<z<<"\n"
#define		 prv(v, s, n)           fr(i, s, n) cout<<v[i]<<" "; cout<<"\n"
#define		 fr(i, s, n)            for (ll i = s ; i < n ; ++i)
#define		 dfr(i, s, n)           for (ll i = s ; i > n ; --i)

// clang-format on

signed main () {
	ios_base::sync_with_stdio (false), cin.tie (0);
	int n, k;
	cin >> n >> k;
	if (n == 2) {
		if (k == 0) {
			pr2 (1, 2);
			return 0;
		}
		pr1 (-1);
		return 0;
	}
	if (k > (n - 2) * (n - 1) / 2) {
		pr1 (-1);
		return 0;
	}
	int curr = 0;
	int i = 4;
	int ans = 0;
	ve< pii > op;
	while (curr < k) {
		if (curr == 0) {
			ans += 2;
			op.pb ({1, 2});
			op.pb ({1, 3});
			curr++;
		} else {
			if (curr + i - 2 > k) break;
			op.pb ({1, i});
			curr += (i - 2);
			i++;
			ans++;
		}
	}
	// pr1 (curr);
	int x = i - 1;
	if (curr == k) {
		if (i == n + 1) return 0;
		while (i != n + 1) {
			fr (j, 1, i) {
				ans++;
				op.pb ({j, i});
			}
			i++;
		}
		return 0;
	} else {
		while (true) {
			int flag = 0;
			if (i - 2 + curr >= k) {
				flag = 1;
				int j = k - curr;
				op.pb ({i, i});
				ans++;
				curr++;
				fr (p, j + 1, i - 1) {
					op.pb ({i, p});
					ans++;
					curr++;
				}
			} else {
				op.pb ({x, i});
				ans++;
				curr += (i - 2);
			}
			i++;
			if (flag) break;
		}
	}
	while (i != n + 1) {
		fr (j, 1, i) {
			op.pb ({j, i});
			ans++;
		}
		i++;
	}
	pr1 (ans);
	for (auto p : op) {
		pr2 (p.ff, p.ss);
	}
	return 0;
}
