#include <bits/stdc++.h>
using namespace std;
int beautifulPairs(vector<int> a, vector<int> b)
{
   /* sort(a.begin(),a.end());
    sort(b.begin(),b.end());*/
    int n=a.size();
    int i=0;
    int count=0;
    while(i!=n)
    {
        if(a[i]==b[i])
            {
                count++;
                i++;
            }
        else if(a[i]!=b[i] && flag=0)
        {
            b[i]=a[i];
            flag=1;
        }
        else
            break;
    }
    return count+1;
}
int main()
{
    int n;cin>>n;
    vector <int> a(n);
    vector <int> b(n);
    for(size_t i=0;i<n;i++)
        cin>>a[i];
    for(size_t i=0;i<n;i++)
        cin>>b[i];
    int result=beautifulPairs(a,b);
    cout<<result<<endl;
}
