/*
				C++
				encoding:UTF-8
				Modified: <18/Mar/2019 09:05:07 PM>

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
#define		 prv(v, s, n)           for (size_t i = s ; i < n ; i++) cout<<v[i]<<" "; cout<<"\n";
#define		 fr(i, s, n)            for (size_t i = s ; i < n ; i++)
#define		 dfr(i, s, n)           for (size_t i = s ; i > n ; i--)

ll powermod(ll _a,ll _b,ll _m) {ll _r=1;while(_b){if(_b%2==1)_r=(_r*_a)%_m;_b/=2;_a=(_a*_a)%_m;}return _r;}

// clang-format on

const int N = 51;
string matrix[N][N];
int n, m, k;
int visited[N][N];
int curr, flag;

bool check (int i, int j) {
	if (i >= 0 and i < n and j >= 0 and j < m) return true;
	return false;
}

auto neighbours (int i, int j) {
	ve< pair< int, int > > ne = {{i, j - 1}, {i - 1, j}, {i + 1, j}, {i, j + 1}};
	return ne;
}


void dfs (int x, int y) {
	visited[x][y] = 1;
	curr++;
	for (auto& [u, v] : neighbours (x, y)) {
		if (check (u, v) and !visited[u][v] and matrix[u][v] == ".") {
			dfs (u, v);
		}
	}
}

void fll (int x, int y) {
	visited[x][y] = 1;
	matrix[x][y]  = "*";
	for (auto& [p, q] : neighbours (x, y)) {
		if (check (p, q) and !visited[p][q] and matrix[p][q] == ".") fll (p, q);
	}
}

int main () {
	// ios_base::sync_with_stdio (false), cin.tie (0), cout.tie (0);
	cin >> n >> m >> k;
	string s;
	fr (i, 0, n) {
		cin >> s;
		fr (j, 0, m) {
			matrix[i][j] = s[j];
		}
	}

	fr (i, 0, n) {
		fr (j, 0, m) {
			if (i > 0 and i < n - 1 and j > 0 and j < m - 1) continue;
			if (matrix[i][j] == "*") continue;
			dfs (i, j);
		}
	}

	set< pair< int, pair< int, int > > > comp;

	fr (i, 0, n) {
		fr (j, 0, m) {
			if (!visited[i][j] and matrix[i][j] == ".") {
				curr = 0;
				dfs (i, j);
				comp.insert ({curr, {i, j}});
			}
		}
	}

	if (len (comp) == k) {
		pr1 (0);
		fr (i, 0, n) {
			fr (j, 0, m) {
				cout << matrix[i][j];
			}
			cout << endl;
		}
		return 0;
	}
	int ans = 0;
	ve< pair< int, int > > f;
	while (len (comp) != k) {
		auto i = comp.begin ();
		ans += (i->ff);
		comp.erase (i);
		f.pb ({i->ss.ff, i->ss.ss});
	}
	reset (visited, 0);
	for (auto& [u, v] : f) {
		if (!visited[u][v]) { fll (u, v); }
	}
	pr1 (ans);
	fr (i, 0, n) {
		fr (j, 0, m) {
			cout << matrix[i][j];
		}
		cout << endl;
	}

	return 0;
}
