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
vector<pair<int,int>> ans;
void display(int mxR);

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
  ans.resize(mxR+5);

  int mnC = brute(pv, 0, 0, bw, mxR); // solve naively??
  cout<<"mnC: "<<mnC<<endl;
  
  cout<<"dp[0][0]: "<<dp[0][0]<<endl;
  display(mxR);
  cout<<"WHAT WHAT"<<endl;

  // answer should be in dp[0][0]
  return 0;
}

/********************************************************************
Solution shoudl be in dp[row=0][loc=0] ... 
@param mnC - min cost
@param mnLoc - location/index where mnC is found
*********************************************************************/
int brute(vector<int> &pv, int loc, int row, int bw, int mxR){
  cout<<"\t\t\trow: "<<row<<" loc: "<<loc<<endl;
  if(loc>=pv.size()-1){ ans[row]={loc, pv.size()-1}; return 0; }
  if(row>mxR ) return ((int)1<28); 
  int mnC=1<<28, mnLoc, loc2=loc, t;
  if(dp.count(row) && dp[row].count(loc)) return dp[row][loc];
  for(; loc2<pv.size() && pv[loc2]-(loc==0 ? 0:pv[loc-1])<=bw; loc2++){
    if(loc2==pv.size()-1) { mnC=0; mnLoc=loc2; break; }
    t = pow(bw-(pv[loc2]-(loc==0 ? 0:pv[loc-1])),3) + brute(pv,loc2+1,row+1,bw,mxR); 
    if(t<mnC){ mnC=t; mnLoc=loc2; }
  }
  ans[row]={loc,mnLoc}; 
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
void display(int mxR){
  cout<<dp[0][0]<<endl;
  cout<<"HELLO HELLO"<<endl;
  for(int i=0;i<=mxR;i++){
    cout<<"("<<(ans[i].first)+1<<", "<<(ans[i].second)+1<<") --> "<<endl;
  }
  cout<<"mxR: "<<mxR<<endl;
}
















