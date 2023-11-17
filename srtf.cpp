#include<bits/stdc++.h>
using namespace std;

class srtf{
  public:
  int at,bt,ct,tat,wt,process;
  srtf(){}
  srtf(int p,int a,int b){
    process=p;
    at=a;
    bt=b;
  }
  void print(){
    
        cout<<process<<" "<<at<<" "<<bt<<endl; 
  }


};

class vec{
  vector<pair<int,pair<int,int>>> v; int start,time;
  srtf* obj1;
   priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;//{bt,{at,p}}
  public:
  int atat,awt;
   vec(){}
   vec(vector<pair<int,pair<int,int>>> newVec,srtf* obj){
    v=newVec;
    obj1=obj;
    start=0;time=0;atat=0;awt=0;

    UntilVecEmpty();
    UntilPqEmpty();
   }  

    void print(){
     for(int i=0;i<v.size();i++){
        cout<<v[i].second.second<<" "<<v[i].first<<" "<<v[i].second.first<<endl; }

        // cout<<"objects\n";
        // for(int i=0;i<v.size();i++){
        //   obj1[i].print();
        // }
  }
   void UntilVecEmpty(){
      while(!v.empty()){
            if(!pq.empty()){
                 pair<int,pair<int,int>> top=pq.top();
                 int bt=top.first;
                 int at=top.second.first;
                 int p=top.second.second;
                 pq.pop();
                 cout<<start<<" to "<<time<<"\t    "<<"p"<<p<<endl;
                 bt--;
                 if(bt<=0){
                  int ct=time;
                  int tat=time-at;
                  int wt=time-at-obj1[p-1].bt;
                   obj1[p-1].ct=ct;
                   obj1[p-1].tat=tat;
                   obj1[p-1].wt=wt;
                  atat+=tat;awt=wt;
                  
                 }
                 else {
                  pq.push({bt,{at,p}});
                 }
            }
            while(!v.empty() && v[0].first<=time){
                int at=v[0].first;
                int bt=v[0].second.first;
                int p=v[0].second.second;
                pq.push({bt,{at,p}});
                v.erase(v.begin());
            }
            start=time;
            time++;

      }
   }

   void UntilPqEmpty(){
       while(!pq.empty()){
         pair<int,pair<int,int>> top=pq.top();
                 int bt=top.first;
                 int at=top.second.first;
                 int p=top.second.second;
                 pq.pop();
                 time=start+bt;
               cout<<start<<" to "<<time<<"    "<<"p"<<p<<endl;
                 int ct=time;
                  int tat=time-at;
                  int wt=time-at-obj1[p-1].bt;
                   obj1[p-1].ct=ct;
                   obj1[p-1].tat=tat;
                   obj1[p-1].wt=wt;
                  atat+=tat;awt=wt;
                   start=time;

       }
   }


};



int main(){
    cout<<"enter the no. of processes: ";
    int n;cin>>n;
    cout<<"enter process no., at, bt of the processes:\n";
    vector<pair<int,pair<int,int>>> v(n);//{at,{bt,p}}
    srtf* obj=new srtf[n];
    for(int i=0;i<n;i++){
         int p,at,bt;
        cin>>p>>at>>bt;
        obj[i]=srtf(p,at,bt);
        v[i]={at,{bt,p}};
    }
    sort(v.begin(),v.end());
    vec* vecObj=new vec(v,obj);
     cout<<"atat is : "<<(float)(vecObj->atat*1.0)/n<<endl;
     cout<<"awt is : "<<(float)(vecObj->awt*1.0)/n<<endl;


}
/*
1 0 8
2 1 6
3 2 5
4 3 2
5 4 4
6 5 1


process : 7
1 5 1
2 2 1 
3 4 3 
4 1 10
5 3 4 
6 1 8
7 2 6

process:5

2 1 4
3 4 2
4 0 6
5 2 3
1 3 1
*/