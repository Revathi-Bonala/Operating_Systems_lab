#include<bits/stdc++.h>
using namespace std;
//priemptive priority
class premptive{
  public:
  int at,bt,ct,tat,wt,process,priority;
  
  premptive(){}
  premptive(int p,int a,int b,int prior){
    process=p;
    at=a;
    bt=b;
    priority=prior;
   
  }
  void print(){
    
        cout<<process<<" "<<at<<" "<<bt<<endl; 
  }


};

class vec{
  vector<pair<pair<int,int>,pair<int,int>>> v; int start,time;
  premptive* obj1;
  vector<int> priorityVec;
   int minPriority;
   priority_queue<pair<pair<int,int>,pair<int,int>>,vector<pair<pair<int,int>,pair<int,int>>>,greater<pair<pair<int,int>,pair<int,int>>>> pq;//{{priority,at},{p,bt}}
  public:
  int atat,awt;
   vec(){}
   vec(vector<pair<pair<int,int>,pair<int,int>>> newVec,premptive* obj,vector<int> priorVec){
    v=newVec;
    obj1=obj;
    start=0;time=0;atat=0;awt=0;
    priorityVec=priorVec;
     sort(priorityVec.begin(),priorityVec.end());
     minPriority=priorityVec[0];
     priorityVec.erase(priorityVec.begin());
    UntilVecEmpty();
    UntilPqEmpty();
   }  

    void print(){
    //  for(int i=0;i<v.size();i++)
      //  cout<<v[i].second.second<<" "<<v[i].first<<" "<<v[i].second.first<<endl; 

        // cout<<"objects\n";
        // for(int i=0;i<v.size();i++){
        //   obj1[i].print();
        // }
  }
   void UntilVecEmpty(){
      while(!v.empty()){
            if(!pq.empty()){    
                 pair<pair<int,int>,pair<int,int>> top=pq.top();
                 int at=top.first.second;
                 int p=top.second.first;
                 int bt=top.second.second;
                 int prior=top.first.first;
                 pq.pop();
                 if(prior==minPriority){
                    time=start+bt;
                    minPriority=priorityVec[0];
                    priorityVec.erase(priorityVec.begin());
                        bt=0;
                 }
                 else bt--;
                 cout<<start<<" to "<<time<<"\t    "<<"p"<<p<<endl;
                 
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
                   pq.push({{prior,at},{p,bt}});
                 }
            }
            while(!v.empty() && v[0].first.first<=time){
                int at=v[0].first.first;
                int prior=v[0].first.second;
                int bt=v[0].second.second;
                int p=v[0].second.first;
                pq.push({{prior,at},{p,bt}});
                v.erase(v.begin());
            }
            start=time;
            time++;

      }
   }

   void UntilPqEmpty(){
       while(!pq.empty()){
         pair<pair<int,int>,pair<int,int>> top=pq.top();
                int at=top.first.second;
                 int p=top.second.first;
                 int bt=top.second.second;
                 int prior=top.first.first;
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
    cout<<"enter process no., at, bt, priority of the processes:\n";
    vector<pair<pair<int,int>,pair<int,int>>> v(n);//{{at,priority},{p,bt}}
    vector<int> priorityVec(n);
    premptive* obj=new premptive[n];
    int maxip=INT_MIN;
    for(int i=0;i<n;i++){
         int p,at,bt,priority;
        cin>>p>>at>>bt>>priority;
        obj[i]=premptive(p,at,bt,priority);
        v[i]={{at,priority},{p,bt}};
        priorityVec[i]=priority;
        maxip=max(maxip,priority);
    }
    cout<<"choose the given number for priority criteria:\n ";
    cout<<" 1 for smaller number with highest priority (1 >10)\n 2 for larger number with highest priority (10>1) \n"; 
    int option;cin>>option;
    if(option==2){
      for(int i=0;i<n;i++){
        priorityVec[i]=maxip+1-priorityVec[i];
        v[i].first.second=priorityVec[i];

      }
    }

    sort(v.begin(),v.end());
    vec* vecObj=new vec(v,obj,priorityVec);
     cout<<"atat is : "<<(float)(vecObj->atat*1.0)/n<<endl;
     cout<<"awt is : "<<(float)(vecObj->awt*1.0)/n<<endl;


}
/*
1 0 4 2
2 1 3 3
3 2 1 4
4 3 5 5
5 4 2 5


process:4

1 0 5 10
2 1 4 20
3 2 2 30
4 4 1 40

process:5
1 0 3 3
2 1 4 2
3 2 6 4
4 3 4 6
5 5 2 10

process:7
1 0 4 2
2 1 2 4
3 2 3 6
4 3 5 1
5 4 1 8
6 5 4 3
7 11 6 2

highest no. with first priority
1 0 4 2
2 1 3 3
3 2 1 4
4 3 5 5
5 4 2 5
*/