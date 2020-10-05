/********************************************************************
Author: Gabriel Hofer
Instructor: Dr. Rebenitsch
Date: October 8, 2020
Course: CSC-372
*********************************************************************/
#include <iostream>
#include <vector>
#include <map>
#include <cmath>
using namespace std;

vector<int> read_v(int n);
vector<int> prefix(vector<int> &v);
int brute(vector<int> &pv, int loc, int row, int bw, int mxR);
map<int,map<int,int>> dp;
int get_mxR(vector<int> &v, int bw);
map<int,pair<int,int>> ans;
void display();

/********************************************************************
*********************************************************************/
int main(){
  int bw, n, mxR;
  vector<int> v, pv;
  cin>>bw>>n; // read board width & number of announcements 

  v=read_v(n); // read announcements
  pv=prefix(v); // make prefix vector
  cout<<"pv: ";
  for(int i=0;i<pv.size();i++){
    cout << pv[i] << ' ';
  }
  cout<<endl;



  mxR = get_mxR(v, bw);
  cout<<"mxR: "<<mxR<<endl;

  int mnC = brute(pv, 0, 0, bw, mxR); // solve naively??
  cout<<"mnC: "<<mnC<<endl;
  // answer should be in dp[0][0]
  return 0;
}

/********************************************************************
Solution shoudl be in dp[row=0][loc=0] ... 
@param mnC - min cost
@param mnLoc - location/index where mnC is found
*********************************************************************/
int brute(vector<int> &pv, int loc, int row, int bw, int mxR){
  if(row>mxR) return ((int)1<30); 
  if(loc==pv.size()) return 0;
  int mnC=1<<30, mnLoc, loc2=loc, t;
  // if(dp.count(row) && dp[row].count(loc)) return dp[row][loc];
  
  for(; loc2<(pv.size()-1) && pv[loc2]-(loc==0 ? 0:pv[loc-1])<=bw; loc2++){

    cout<<"\t\t\t\trow: "<<row<<" loc: "<<loc<<" bw: "<<bw<<endl;
    cout<<"cost: "<<pow(bw-(pv[loc2]-(loc==0 ? 0:pv[loc-1])),3)<<endl;
    cout<<"NEXT: "<< pv[loc2+1]-(loc==0 ? 0:pv[loc-1]) <<endl;
    cout<<"pv.size()-1: "<<pv.size()-1<<endl;
    
    t = 
      pow(bw-(pv[loc2]-(loc==0 ? 0:pv[loc-1])),3) + 
      brute(pv,loc2+1,row+1,bw,mxR); // need to account for loc-1<0
    if(t<mnC){ mnC=t; mnLoc=loc2; }

  }
  ans[row]={loc,loc2}; 
  return dp[row][loc]=mnC;
}

/********************************************************************
*********************************************************************/
int get_mxR(vector<int> &v, int bw){
  int r=0;
  for(int i=0, s=0; i<v.size(); i++){
    s+=v[i]; 
    if(s>bw){ r++; s=v[i]; }
  }
  return r;
}

/********************************************************************
*********************************************************************/
vector<int> prefix(vector<int> &v){
  vector<int> pv=v;
  for(int i=1;i<v.size();i++) pv[i]+=pv[i-1];
  return pv;
}

/********************************************************************
*********************************************************************/
vector<int> read_v(int n){
  vector<int> v(n);
  for(int i=0;i<n;i++) cin>>v[i];
  return v;
}

/********************************************************************
*********************************************************************/
void display(){
  cout<<dp[0][0]<<endl;
  for(auto e:ans)
    cout<<"("<<(e.second).first<<", "<<(e.second).second<<") --> "<<endl;
}
















