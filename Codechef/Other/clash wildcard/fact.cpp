/*
                C++
                encoding: UTF-8
                Modified: <18/Sep/2019 07:58:52 PM>

                ✪ H4WK3yE乡
                Mohd. Farhan Tahir
                Indian Institute Of Information Technology (IIIT), Gwalior
*/

#include <bits/stdc++.h>
#ifdef LOCAL_PROJECT
#    include <prettypr.hpp>
#endif

using namespace std;

 // clang-format off

#define         ll                     long long
#define         ve                     vector
#define         pb                     push_back
#define         endl                   "\n"
#define         ff                     first
#define         ss                     second
#define         pii                    pair<int, int>
#define         len(v)                 int(v.size())
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
#define int long long

const int N=1e6+5;
int ans[N];
bool prime[N];

void pre(){
	reset (prime, true);

	for (int p = 2; p * p < N; p++) {
		if (prime[p] == true) {
			for (int i = p * p; i < N; i += p){
                prime[i] = false;

            }
				prime[i] = false;
		}
	}
	for (int p = 2; p < N; p++)
		if (prime[p]) {

        }
}

signed main () {
    ios_base::sync_with_stdio (false), cin.tie (nullptr);
    pre();
    return 0;
}