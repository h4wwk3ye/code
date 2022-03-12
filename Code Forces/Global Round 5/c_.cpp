/*
				C++
				encoding: UTF-8
				Modified: <16/Oct/2019 10:04:08 PM>

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

#define         int                    long long
#define         ve                     vector
#define         pb                     push_back
#define         endl                   "\n"
#define         ff                     first
#define         ss                     second
#define         pii                    pair<int, int>
#define         len(v)                 (int)v.size()
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

ve< ve< int > > arr;

int dis (int i, int j) {
	return ((arr[i][0] - arr[j][0]) * (arr[i][0] - arr[j][0]) +
			(arr[i][1] - arr[j][1]) * (arr[i][1] - arr[j][1]) +
			(arr[i][2] - arr[j][2]) * (arr[i][2] - arr[j][2]));
}

struct point {
	int d;
	int i1, j1;
};

bool cmp (point& a, point& b) {
	return a.d < b.d;
}

signed main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	int n;
	cin >> n;

	arr.resize (n);

	fr (i, 0, n) {
		int x, y, z;
		cin >> x >> y >> z;
		arr[i] = {x, y, z, i};
	}

	int x = n * (n - 1) / 2;
	ve< point > mp (x);
	int c = 0;
	fr (i, 0, n) {
		fr (j, i + 1, n) {
			int d = dis (i, j);
			mp[c].d = d;
			mp[c].i1 = i;
			mp[c].j1 = j;
			c++;
		}
	}

	sort (all (mp), cmp);
	ve< int > chk (n, 0);
	for (auto& it : mp) {
		int a = it.i1;
		int b = it.j1;
		if (chk[a] == 1 or chk[b] == 1) {
			continue;
		}
		chk[a] = 1;
		chk[b] = 1;
		pr (a + 1, b + 1);
	}
	return 0;
}
