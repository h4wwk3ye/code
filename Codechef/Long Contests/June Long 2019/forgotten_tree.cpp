/*
				C++
				encoding:UTF-8
				Modified: <13/Jun/2019 09:54:42 PM>

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
//#define		 endl                   "\n";
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
	int tc;
	cin >> tc;
	while (tc--) {
		int n;
		cin >> n;
		int parent[n + 1];
		string s = "No";
		int curr = 1;
		int root;
		int lb = 1, rb = n;
		unordered_set< int > s;
		s.reserve (n + 1);
		s.max_load_factor (0.25);
		while (1) {
			cout << "Q " << curr << " " << lb << " " << rb << endl;
			cin >> s;
			if (s == "Yes") {
				parent[curr] = -1;
				root = curr;
				break;
			}
			curr++;
		}
	}
	return 0;
}
