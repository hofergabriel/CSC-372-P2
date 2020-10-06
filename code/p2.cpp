/********************************************************************
Author: Gabriel Hofer
Instructor: Dr. Rebenitsch
Date: 7am, October 8, 2020
Course: CSC-372
*********************************************************************/
#include <iostream>
#include <vector>
#include <map>
#include <cmath>
using namespace std;

int brute(vector<int> &pv, const int loc, const int row, const int bw, const int mxR);
int get_mxR(vector<int> &v, const int bw);
void display(const int mxR, vector<int> &pv);

vector<int> prefix(vector<int> &v);
vector<int> read_v(const int n);
vector<int> ans;
map<int,map<int,int>> dp;

/********************************************************************
Main
*********************************************************************/
int main(){
  int bw, n, mxR;
  vector<int> v, pv;
  cin>>bw>>n; // read board width & number of announcements 
  v=read_v(n); // read announcements
  pv=prefix(v); // make prefix vector
  mxR = get_mxR(v, bw); // get max row number
  ans.resize(mxR+5); // resize answer vector
  int mnC = brute(pv, 0, 0, bw, mxR); // solve
  display(mxR,pv); // display answer
  return 0;
}

/********************************************************************
Solution should be in dp[row=0][loc=0] ... 
@param pv - prefix sum vector of v
@param loc - index of announcement in v that starts the row
@param row - current row number 
@param bw - board width 
@param mxR - maximum row number 
*********************************************************************/
int brute(vector<int> &pv, const int loc, const int row, const int bw, const int mxR){
  pair<int,int> mn_C_Loc={1<<28, -1};
  int loc2=loc, t=-1;
  if(row>mxR ) return ((int)1<28); 
  if(loc>=pv.size()-1){ 
    ans[row]=loc; 
    return 0; 
  }
  if(dp.count(row) && dp[row].count(loc)) return dp[row][loc];
  for(; loc2<pv.size() && pv[loc2]-(loc==0 ? 0:pv[loc-1])<=bw; loc2++){
    if(loc2==pv.size()-1) { 
      mn_C_Loc={0,loc2}; 
      break; 
    }
    t = pow(bw-(pv[loc2]-(loc==0 ? 0:pv[loc-1])),3) + brute(pv,loc2+1,row+1,bw,mxR); 
    if(t<mn_C_Loc.first) mn_C_Loc={t,loc2};
  }
  ans[row]=mn_C_Loc.second;
  return dp[row][loc]=mn_C_Loc.first;
}

/********************************************************************
@param v - contains announcements
@param bw - board width 
*********************************************************************/
int get_mxR(vector<int> &v, const int bw){
  int r=0;
  for(int i=0, s=0; i<v.size(); i++){
    s+=v[i]; 
    if(s>bw){ r++; s=v[i]; }
  }
  return r;
}

/********************************************************************
@param v - contains announcements
*********************************************************************/
vector<int> prefix(vector<int> &v){
  vector<int> pv=v;
  for(int i=1;i<v.size();i++) pv[i]+=pv[i-1];
  return pv;
}

/********************************************************************
@param n - number of announcements to read from stdin
*********************************************************************/
vector<int> read_v(const int n){
  vector<int> v(n);
  for(int i=0;i<n;i++) cin>>v[i];
  return v;
}

/********************************************************************
@param mxR - max row number
@param pv - prefix of v
*********************************************************************/
void display(const int mxR, vector<int> &pv){
  cout<<"Board cost: "<<dp[0][0]<<endl;
  //ans[mxR]=pv.size()-1;
  for(int i=0, j=0;i<=mxR;i++){
    cout<<"("<<j+1<<", "<<ans[i]+1<<") --> "<<pv[ans[i]]-(j==0 ? 0:pv[j-1])<<endl;
    j=ans[i]+1;
  }
  cout<<endl;
}
















