/*
				C++
				encoding: UTF-8
				Modified: <28/Jul/2019 09:17:53 PM>

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
#define         pii                    pair<ll, ll>
#define         len(v)                 ll(v.size())
#define         all(v)                 v.begin(), v.end()
#define         reset(a, b)            memset(a, b, sizeof(a));
#define         fr(i, s, n)            for (ll i = s ; i < n ; ++i)
#define         dfr(i, s, n)           for (ll i = s ; i > n ; --i)

void pr (string sep = "\n") {
    cout << sep;
}

template < typename T, typename... TAIL > void pr (const T& t, TAIL... tail) {
    cout << t << " ";
    pr (tail...);
}

// clang-format on

struct Trie {
	Trie* children[2];
	ll val;
	Trie () {
		fr (i, 0, 1) this->children[i] = nullptr;
		this->val = -1;
	}
};

void insert (Trie* node, ll x) {
	for (ll bit = 30; bit >= 0; bit--) {
		ll curr_bit = (x >> bit) & 1;
		if (node->children[curr_bit] == nullptr) node->children[curr_bit] = new Trie;
		node = node->children[curr_bit];
		if (bit == 0) node->val = x;
	}
}

ll get_min (Trie* node, ll x) {
	for (ll bit = 30; bit >= 0; bit--) {
		ll curr_bit = (x >> bit) & 1;
		if (node->children[curr_bit] != nullptr) {
			node = node->children[curr_bit];
		} else {
			curr_bit = 1 ^ curr_bit;
			node = node->children[curr_bit];
		}
		if (bit == 0) return node->val;
	}
}

signed main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	ll n;
	cin >> n;
	ll arr[n + 1];
	ll total = 0;
	fr (i, 1, n + 1) cin >> arr[i], total += arr[i];

	ll dp[n + 1][total + 1], counter[total + 1];
	reset (dp, 0);
	reset (counter, 0);
	counter[0] = 1;
	fr (i, 1, n + 1) {
		dp[i][arr[i]] = 1;
		fr (j, 1, total + 1) {
			if (dp[i - 1][j]) {
				dp[i][j] = 1;
				dp[i][j + arr[i]] = 1;
			}
		}
	}

	fr (x, 1, n + 1) {
		int i = arr[x];
		dfr (j, total - i, -1) {
			if (counter[j]) counter[i + j] += counter[j], counter[i + j] %= mod;
		}
	}

	Trie* root = new Trie ();
	fr (i, 0, total + 1) {
		if (dp[n][i]) {
			insert (root, i);
		}
	}
	ll tc;
	cin >> tc;
	while (tc--) {
		ll x;
		cin >> x;
		ll ans = get_min (root, x);
		cout << ans << " " << counter[ans] << endl;
	}

	return 0;
}
