/*
				C++
				encoding:UTF-8
				Modified: <17/Mar/2019 09:02:49 PM>

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
#define		 pr3(x, y, z)           cout<<x<<" "<<y<<" "<<z<<"\n";
#define		 prv(v, s, n)           for (size_t i = s ; i < n ; i++) cout<<v[i]<<" "; cout<<"\n";
#define		 fr(i, s, n)            for (size_t i = s ; i < n ; i++)
#define		 dfr(i, s, n)           for (size_t i = s ; i > n ; i--)

ll powermod(ll _a,ll _b,ll _m) {ll _r=1;while(_b){if(_b%2==1)_r=(_r*_a)%_m;_b/=2;_a=(_a*_a)%_m;}return _r;}


int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n; cin>>n;
    ve<pair<int,int>> r(n);
    int u,v;
    int flag=1;
    ll total=0;
    fr(i,0,n){
        cin>>u>>v;
        r[i]={u,v};

        total+=u;
    }


    int cnt[2]={0,0};
    fr(i,0,n){
        if (r[i].ss==1)
            cnt[0]++;
        else
            cnt[1]++;
    }


    if (cnt[1]==0){
        pr1("Infinity");
        return 0;
    }
    reverse(all(r));

    ll low=-2e9+5, high=2e9+5, mid;

    while (low+1<high){
        mid=low+(high-low)/2;
        //pr3(low,mid,high);
        ll curr=mid;
        flag=0;
        fr(i,0,n){
            curr-=r[i].ff;
            if (r[i].ss==2 and curr>=1900){
                flag=1;
                break;
            }
            if (r[i].ss==1 and curr<1900){
                flag=0;
                break;
            }
        }
        if (flag==0)
            low=mid;
        else
            high=mid;
    }

    ll curr=low;
    fr(i,0,n){
        curr-=r[i].ff;
        if (curr>=1900 and r[i].ss==2){
            pr1("Impossible");
            return 0;
        }
        if (curr<1900 and r[i].ss==1){
            pr1("Impossible");
            return 0;
        }
    }

    pr1(low);

    return 0;
}
