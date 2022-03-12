#include<bits/stdc++.h>
using namespace std;
int main()
{
    int p,s;
    cin>>p>>s;
    vector<pair<int,int>> v;

    for(int i=0;i<p;i++)
    {
        vector<pair<int,int>> a;
        vector<int> x(s),y(s);
        for(int j=0;j<s;j++)
        {
            cin>>x[j];

        }
        for(int j=0;j<s;j++)
        {
            cin>>y[j];
        }
        for(int j=0;j<s;j++)
        {
            a.push_back(make_pair(x[j],y[j]));
        }

        sort(a.begin(),a.end());
        int score=0;
        for(int j=0;j<s-1;j++)
        {
            if(a[j].second>a[j+1].second)
            {
                score++;
            }
        }
      v.push_back(make_pair(score,i+1));

    }

    sort(v.begin(),v.end());
    for(int i=0;i<p;i++)
    {
        cout<<v[i].second<<endl;
    }

}
