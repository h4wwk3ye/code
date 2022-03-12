/*
				C++
				encoding: UTF-8
				Modified: <27/Aug/2019 05:57:47 PM>

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

int X, Y;

struct Point {
	int x, y, id;
};

bool cmp (Point point1, Point point2) {
	// return point1.x * point1.x + point1.y * point1.y < point2.x * point2.x + point2.y * point2.y;
	if (point1.x != point2.x)
		return point1.x < point2.x;
	else
		return point1.y < point2.y;
}

signed main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	// freopen ("inp.txt", "r", stdin);
	int n, g;
	cin >> n >> g;
	Point arr[n];
	fr (i, 0, n) {
		cin >> arr[i].x >> arr[i].y;
		arr[i].id = i + 1;
		X += arr[i].x;
		Y += arr[i].y;
	}
	X /= n;
	Y /= n;
	sort (arr, arr + n, cmp);

	// fr (i, 0, n) pr (arr[i].x, arr[i].y);
	// best inc = 20
	int inc = (n / 25);
	int x = n / (g + inc);
	int j = 0;
	unordered_map< int, ve< int > > op;
	int curr = 0;
	fr (i, 0, x) {
		int cnt = 0;
		while (cnt != g + inc) {
			if (j == n) break;
			op[i].pb (arr[j].id);
			j++;
			cnt++;
		}
		curr++;
	}
	fr (i, j, n) {
		op[curr - 1].pb (arr[i].id);
	}

	pr (len (op));
	for (auto i : op) {
		pr (len (i.ss));
		for (auto j : i.ss)
			cout << j << " ";
		cout << endl;
	}
	return 0;
}
