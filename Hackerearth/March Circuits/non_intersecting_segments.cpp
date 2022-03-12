/*
				C++
				encoding:UTF-8
				Modified: <26/Mar/2019 11:38:00 AM>

				✪ H4WK3yE乡
				Mohd. Farhan Tahir
				Indian Institute Of Information Technology (IIIT),Gwalior
*/

#include <bits/stdc++.h>

using namespace std;

// clang-format off

#define		 ll                     int64_t
#define		 mod                    1000000007
#define		 ve                     vector
#define		 pb                     push_back
#define		 umap                   unordered_map
#define		 pq                     priority_queue
#define		 endl                   "\n";
#define		 ff                     first
#define		 ss                     second
#define		 len(v)                 int(v.size())
#define		 all(v)                 v.begin(), v.end()
#define		 reset(a, b)            memset(a, b, sizeof(a));
#define		 sum(v)                 accumulate(v.begin(), v.end(), (ll)0);
#define		 pr1(x)                 cout<<x<<"\n"
#define		 pr2(x, y)              cout<<x<<" "<<y<<"\n"
#define		 pr3(x, y, z)           cout<<x<<" "<<y<<" "<<z<<"\n";
#define		 prv(v, s, n)           for (int i = s ; i < n ; i++) cout<<v[i]<<" "; cout<<"\n";
#define		 fr(i, s, n)            for (int i = s ; i < n ; i++)
#define		 dfr(i, s, n)           for (int i = s ; i > n ; i--)

ll powermod(ll _a,ll _b,ll _m) {ll _r=1;while(_b){if(_b%2==1)_r=(_r*_a)%_m;_b/=2;_a=(_a*_a)%_m;}return _r;}

// clang-format on

const int N = 1e5 + 5;
pair< pair< int, int >, pair< int, int > > lines[N];
int n;

bool isIntersecting (pair< int, int > p1, pair< int, int > p2, pair< int, int > q1, pair< int, int > q2) {
	return (((q1.ff - p1.ff) * (p2.ss - p1.ss) - (q1.ss - p1.ss) * (p2.ff - p1.ff)) *
			((q2.ff - p1.ff) * (p2.ss - p1.ss) - (q2.ss - p1.ss) * (p2.ff - p1.ff)) <
			0) &&
		   (((p1.ff - q1.ff) * (q2.ss - q1.ss) - (p1.ss - q1.ss) * (q2.ff - q1.ff)) *
			((p2.ff - q1.ff) * (q2.ss - q1.ss) - (p2.ss - q1.ss) * (q2.ff - q1.ff)) <
			0);
}

int recurse (int i) {
	if (i == n) return 0;
	int x1 = lines[i].ff.ff;
	int y1 = lines[i].ff.ss;
	int x2 = lines[i].ss.ff;
	int y2 = lines[i].ss.ss;
	int x = -1;
	fr (j, i + 1, n) {
		int x3 = lines[j].ff.ff;
		int y3 = lines[j].ff.ss;
		int x4 = lines[j].ss.ff;
		int y4 = lines[j].ss.ss;
		if (!isIntersecting ({x1, y1}, {x2, y2}, {x3, y3}, {x4, y4})) {
			x = j;
			break;
		}
	}
	if (x == -1) {
		return max (recurse (i + 1), 1);
	} else
		return max (recurse (i + 1), 1 + recurse (x));
}

int main () {
	ios_base::sync_with_stdio (false), cin.tie (0);
	cin >> n;
	fr (i, 0, n) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		if (x1 > x2) {
			swap (x1, x2);
			swap (y1, y2);
		}
		lines[i] = {{x1, y1}, {x2, y2}};
	}
	sort (lines, lines + n);
	/*fr (i, 1, n + 1) {
		cout << lines[i].ff.ff << " " << lines[i].ff.ss << " " << lines[i].ss.ff << " "
			 << lines[i].ss.ss << endl;
	}*/

	pr1 (recurse (0));

	return 0;
}
