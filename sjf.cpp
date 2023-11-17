#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cout<<"enter the number of process:"<<endl;
    cin>>n;
    cout<<"enter the arrival times and bursttime"<<endl;
    vector<pair<int,pair<int,int>>>v;
    for(int i=0;i<n;i++)
    {
        int p=i+1;
        int a;
        cin>>a;
        int b;
        cin>>b;
        v.push_back(a,{p,b});
    }
    sort(v.begin(),v.end());
    int mat=v[0].first;
    int mp=v[0].second.first;
    int mbt=v[0].second.second;
    int tat=mbt+mat-mat;//tat=ct-at;
    int wt=tat-mbt;//
    float atat=tat;
    float awt=wt;
    int start=mbt+mat;
    cout<<mp<<"\t"<<mat<<"\t"<<mbt<<"\t"<<mbt+mat<<"\t"<<tat<<"\t"<<wt<<endl;
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
    while(pq.size()!=0 || v.size()!=0){
        for(int i=0;i<v.size();i++)
        {
            int a=v[i].first;
            int p=v[i].second.first;
            int b=v[i].second.second;
            if(a<=start)
            {
                pq.push({b,{a,p}});
                pair<int,pair<int,int>>search={a,{p,b}};
                auto it=find(v.begin(),v.end(),search);
                v.erase(it);
            }
        }
        if(pq.size()==0)
        {
            int a=v[0].first;
            int b=v[0].second.second;
            int p=v[0].second.first;
            pq.push({b,{a,p}});
            v.erase(v.begin());
        }
        auto top=pq.top();
        pq.pop();
        mp=top.second.second;
        mat=top.second.first;
        mbt=top.second;
        if(mat>start)
        start=mat;
        int mct=start+mbt;
        tat=mct-mat;
        wt=tat-mbt;
       cout<<mp<<"\t"<<mat<<"\t"<<mbt<<"\t"<<mbt+mat<<"\t"<<tat<<"\t"<<wt<<endl;
       atat+=tat;awt+=wt;
       start=mct;
    }
    atat=atat/n;
    awt=awt/n;
    cout<<"average tat is"<<atat<<endl;
    cout<<"average wt is"<<awt<<endl;
}

/*
p1 4 2
p2 10 1
p3 15 2
p4 20 3
p5 28 8
p1 
p2
*/