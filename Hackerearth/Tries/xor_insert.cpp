/*
				C++
				encoding: UTF-8
				Modified: <19/Jul/2019 07:12:59 PM>

				✪ H4WK3yE乡
				Mohd. Farhan Tahir
				Indian Institute Of Information Technology (IIIT), Gwalior
*/

#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#	include <prettyprint.hpp>
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
#define         prv(v, s, n)           fr(i, s, n) cout<<v[i]<<" "; cout<<"\n"

void print (string sep = "\n") {
    cout << sep;
}

template < typename T, typename... TAIL > void print (const T& t, TAIL... tail) {
    cout << t << " ";
    print (tail...);
}

// clang-format on

const int BITS = 30;

struct TrieNode {
	TrieNode* children[2];
};

void insert (TrieNode* node, int number, int bit) {
	if (bit < 0) return;

	int curr_bit = (number >> bit) & 1;
	if (node->children[curr_bit] == nullptr) {
		node->children[curr_bit] = new TrieNode ();
	}
	insert (node->children[curr_bit], number, bit - 1);
}

int get_min (TrieNode* node, int number) {
	int ans = 0;
	dfr (bit, BITS, -1) {
		int curr_bit = (number >> bit) & 1;
		if (node->children[curr_bit])
			node = node->children[curr_bit];
		else {
			ans |= 1 << bit;
			node = node->children[1 - curr_bit];
		}
	}
	return ans;
}

signed main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	TrieNode* root = new TrieNode ();
	insert (root, 0, BITS);
	int tc;
	cin >> tc;
	int curr = 0;
	while (tc--) {
		int t, x;
		cin >> t;
		if (t == 1) {
			cin >> x;
			insert (root, x ^ curr, BITS);
		} else if (t == 2) {
			cin >> x;
			curr ^= x;
		} else {
			print (get_min (root, curr));
		}
	}
	return 0;
}
