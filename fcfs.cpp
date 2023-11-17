#include <bits/stdc++.h> 
using namespace std;

void fcfs(vector<pair<int,pair<string,int>>> &v){
 vector<pair<pair<string,int>,pair<int,int>>> ans; //process ct tat wt
 int start=0;float tat,wt,atat=0,awt=0;
 cout<<"p\t"<<"CT\t"<<"TAT\t"<<"WT\t"<<endl;
 
  for(int i=0;i<v.size();i++){
      int at=v[i].first;
      string p=v[i].second.first;
      int bt=v[i].second.second;
    
  if(start<at) {
    start=at;
  }
      int ct=start+bt;
      tat=ct-at; 
      wt=tat-bt;
      atat+=tat;
      awt+=wt;
      ans.push_back({{p,ct},{tat,wt}});
      start=ct;
  }
 int n=v.size();
 atat=atat/n;
 awt=awt/n;
 for(auto it:ans){
    cout<<it.first.first<<"\t"<<it.first.second<<"\t"<<it.second.first<<"\t"<<it.second.second<<endl;
 }
 cout<<"average tat is "<<atat<<endl;
 cout<<"average wt is "<<awt<<endl;
 
}




int main()
{ vector<pair<int,pair<string,int>>> v;
 cout<<"enter the no. of process "<<endl;
 int n;cin>>n;
 cout<<"enter proccess no. ,arrival time and brust time "<<endl;
 for(int i=0;i<n;i++){
    string p;
   int at,bt;
    
    cin>>p>>at>>bt;
    v.push_back({at,{p,bt}});

 } cout<<endl;
 sort(v.begin(),v.end());
//  for(int i=0;i<n;i++){
//     cout<<v[i].second.first<<" "<<v[i].first<<" "<<v[i].second.second<<endl;
//  }
 fcfs(v);
   return 0;
}