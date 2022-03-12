/*
				C++
				encoding:UTF-8
				Modified: <10/Mar/2019 12:27:55 AM>

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

bool cmp(const pair<int, int> &p, int v){
    if (p.ff<v)
        return true;
    return false;
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n,m,d;
    cin>>n>>m>>d;
    int a[n];
    set<pair<int, int> > arr;
    fr(i,0,n){
        cin>>a[i];
        arr.insert({a[i],i});
    }
    //sort(all(arr));
    int ans=0, days[n];
    fill(days,days+n,0);
    while (!arr.empty()){
        ans++;
        int i=arr.begin()->ss;
        arr.erase(arr.begin());
        days[i]=ans;
        while(true){
            auto x=arr.upper_bound({a[i]+d, 1e9});
            
            if (x==arr.end())
                break;

            i=x->ss;
            arr.erase(x);
            days[i]=ans;
        }

    }
    pr1(ans);
    fr(i,0,n)
        cout<<days[i]<<" ";
    cout<<endl;

    return 0;
}
