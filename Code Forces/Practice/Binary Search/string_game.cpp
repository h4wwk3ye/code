/*
				C++
				encoding:UTF-8
				Modified: <17/Mar/2019 04:58:56 PM>

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
    string t,p;
    cin>>t;
    cin>>p;
    int n=len(t);
    int arr[n+1];

    fr(i,0,n){
        cin>>arr[i];
        arr[i]--;
    }

    int low=0, high=n,mid;
    while (low+1<high){
        mid=(low+high+1)/2;
        umap<char,int> m;
        string x=t;
        fr(i,0,mid)
            x[arr[i]]='-';
        int pos=0;
        for(char c:p){
            while (pos<n and x[pos]!=c)
                pos++;
            pos++;
        }
        if (pos<=n)
            low=mid;
        else
            high=mid;

    }
    pr1(low);
    return 0;
}
