/*
				C++
				encoding:UTF-8
				Modified: <17/Mar/2019 11:33:50 AM>

				✪ H4WK3yE乡
				Mohd. Farhan Tahir
				Indian Institute Of Information Technology (IIIT),Gwalior
*/

#include <bits/stdc++.h>
using namespace std;

#define		 ll                     long long
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
#define		 prv(v)                 for (auto& ijk : v)  cout<<ijk<<" ";cout<<"\n"
#define		 fr(i, s, n)            for (size_t i = s ; i < n ; i++)
#define		 dfr(i, s, n)           for (size_t i = s ; i > n ; i--)

ll powermod(ll _a,ll _b,ll _m) {ll _r=1;while(_b){if(_b%2==1)_r=(_r*_a)%_m;_b/=2;_a=(_a*_a)%_m;}return _r;}


int main() {
    //ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    string s;
    cin>>s;
    ll nb,ns,nc;
    cin>>nb>>ns>>nc;
    int pb,ps,pc;
    cin>>pb>>ps>>pc;
    ll r;
    cin>>r;

    int mp[3];
    fill(mp,mp+3,0);
    for (char i: s){
        if (i=='B')
            mp[0]++;
        else if (i=='S')
            mp[1]++;
        else
            mp[2]++;
    }

    ll low=0, high=1e13, mid;
    while (low<high){
        mid=(low+high+1)/2;
        ll cost=0;
        cost=max((ll)0,(mp[0]*mid-nb))*pb + max((ll)0,(mp[1]*mid-ns))*ps + max((ll)0,(mp[2]*mid-nc))*pc;
        if (cost<=r)
            low=mid;
        else
            high=mid-1;
    }
    pr1(low);


    return 0;
}
