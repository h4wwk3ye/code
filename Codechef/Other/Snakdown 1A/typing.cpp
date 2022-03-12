#include<bits/stdc++.h>
using namespace std;
int same_hand(char first,char second)
{
    if ((first=='d' or first=='f') and (second=='d' or second=='f'))
        return 1;
    else if ((first == 'j' or first == 'k')and (second == 'j' or second == 'k'))
        return 1;
    else
        return 0;
}
int main()
{
    int t;
    cin>>t;
    for (int i=0;i<t;i++)
    {
        typedef unordered_map<string,float> w_time;
        w_time word_time;
        int n;
        float time=0;
        string word;
        cin>>n;
        int arr[n];
        for (int j=0;j<n;j++)
        {
            cin>>word;
            float local_time=0;
            if (word_time.find(word)==word_time.end())
            {
                local_time+=0.2;
                for (int k=1;k<word.length();k++)
                {
                    if (same_hand(word[k-1],word[k])==1)
                        local_time+=0.4;
                    else
                        local_time+=0.2;
                }
                word_time.insert(pair<string,float>(word,local_time));
                time+=local_time;
            }
            else
            {
                float fnd;
                fnd=word_time.at(word);
                time+=(fnd/2);
            }
        }
        cout<<int(time*10);

    }
return 0;
}
