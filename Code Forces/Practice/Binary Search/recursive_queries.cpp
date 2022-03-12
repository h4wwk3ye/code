/*
				C++
				encoding:UTF-8
				Modified: <04/Mar/2019 08:19:11 PM>

				✪ H4WK3yE乡
				Mohd. Farhan Tahir
				Indian Institute Of Information Technology (IIIT),Gwalior
*/

#include <bits/stdc++.h>
using namespace std;

#define		 ll					long long
#define		 mod					1000000007
#define		 ve					vector
#define		 pb					push_back
#define		 umap					unordered_map
#define		 pq					priority_queue
#define		 endl					"\n";
#define		 ff					first
#define		 ss					second
#define		 len(v)					int(v.size())
#define		 all(v)					v.begin(), v.end()
#define		 reset(a, b)				memset(a, b, sizeof(a));
#define		 sum(v)					accumulate(v.begin(), v.end(), (ll)0);
#define		 pr1(x)					cout<<x<<"\n"
#define		 pr2(x, y)				cout<<x<<" "<<y<<"\n"
#define		 prv(v)					for (auto& ijk : v)  cout<<ijk<<" ";cout<<"\n"
#define		 fr(i, k, n)				for (int i = k ; k < n ? i < n : i > n; k < n ? i += 1 : i -= 1)

ll powermod(ll _a,ll _b,ll _m)	{ll _r=1;while(_b){if(_b%2==1)_r=(_r*_a)%_m;_b/=2;_a=(_a*_a)%_m;}return _r;}

const int N=1e6+5;
int dp[10][N];

int f(int x){
    if (x<10)
        return x;
    int prod=1;
    while (x){
        if (x%10)
            prod*=x%10;
        x/=10;
    }
    return f(prod);
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    fr(i,1,N-4){
        dp[f(i)][i]++;
    }
    fr(i,1,10){
        fr(j,1,N-4){
            dp[i][j]+=dp[i][j-1];
        }
    }
    int q,l,r,k;
    cin>>q;
    while(q--){
        cin>>l>>r>>k;
        pr1(dp[k][r]-dp[k][l-1]);
    }

    return 0;
}
