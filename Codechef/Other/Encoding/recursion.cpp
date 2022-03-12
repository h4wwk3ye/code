#pragma GCC optimize("-O3")
/*
                C++
                encoding: UTF-8
                Last Modified: 30/Oct/19 08:49:24 PM
*/

#include <bits/stdc++.h>
#ifdef H4wk3ye
#	include <prettypr.hpp>
#endif

using namespace std;

// clang-format off

#define		int                    long long
#define		ve                     vector
#define		pb                     push_back
#define		endl                   "\n"
#define		ff                     first
#define		ss                     second
#define		pii                    pair<int, int>
#define		len(v)                 (int)v.size()
#define		all(v)                 v.begin(), v.end()
#define		reset(a, b)            memset(a, b, sizeof(a));
#define		fr(i, s, n)            for (int i = s ; i < n ; ++i)
#define		dfr(i, s, n)           for (int i = s ; i > n ; --i)

template < typename T > void pr (const T& t) {
    cout << t << "\n";
}

template < typename T, typename U, typename... ARGS >
void pr (const T& t, const U& u, const ARGS&... args) {
    cout << t << " ";
    pr (u, args...);
}

// clang-format on

int dp[50];
int dp1[50];
const int mod = 1e9+7;

int rec(int i){
    if (i<=1) return 1;
    if (dp1[i]) return dp1[i];
    dp1[i] = 2*rec(i-1)+3*rec(i-2);
    dp1[i] %=mod;
    return dp1[i];
}

int recurse(int i){
    if (i==0) return 1;
    if (i==1) return 2;
    if (dp[i]) return dp[i];
    dp[i] = 2*recurse(i-1)+3*recurse(i-2)+rec(i);
    dp[i]%=mod;
    return dp[i];
}

signed main () {
   // ios_base::sync_with_stdio (false), cin.tie (nullptr);
    fr(i, 0, 50){
        pr(i, recurse(i));
    }
    return 0;
}