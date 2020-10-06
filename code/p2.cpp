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

int brute(vector<int> &pv, const int loc, const int row, const int bw, const int mxR);
int get_mxR(vector<int> &v, const int bw);
void display(const int mxR, vector<int> &pv);

vector<int> prefix(vector<int> &v);
vector<int> read_v(const int n);
vector<int> ans;
map<int,map<int,int>> dp;

/********************************************************************
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
@param mnC - min cost
@param mnLoc - location/index where mnC is found
*********************************************************************/
int brute(vector<int> &pv, const int loc, const int row, const int bw, const int mxR){
  int mnC=1<<28, mnLoc=-1, loc2=loc, t=-1;
  //cout<<"row: "<<row<<" loc: "<<loc<<endl;
  if(loc>=pv.size()-1){ 
    ans[row]=loc; 
    return 0; 
  }
  if(row>mxR ) 
    return ((int)1<28); 
  if(dp.count(row) && dp[row].count(loc)) {
    return dp[row][loc];
  }
  for(; loc2<pv.size() && pv[loc2]-(loc==0 ? 0:pv[loc-1])<=bw; loc2++){
    if(loc2==pv.size()-1) { 
      //cout<<"ONE "<<"row: "<<row<<" loc: "<<loc<<" mnLoc: "<<mnLoc<<" mnC: "<<mnC<<endl;
      mnC=0; 
      mnLoc=loc2; 
      break; 
    }
    t = pow(bw-(pv[loc2]-(loc==0 ? 0:pv[loc-1])),3) + brute(pv,loc2+1,row+1,bw,mxR); 
    if(t<mnC){ 
      //cout<<"TWO "<<"row: "<<row<<" loc: "<<loc<<" mnLoc: "<<mnLoc<<" mnC: "<<mnC<<endl;
      //cout<<"t: "<<t<<endl;
      mnC=t; 
      mnLoc=loc2; 
    }
  }
  //cout<<"row: "<<row<<" loc: "<<loc<<" mnLoc: "<<mnLoc<<" mnC: "<<mnC<<endl;
  
  ans[row]=mnLoc;
  return dp[row][loc]=mnC;
}

/********************************************************************
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
*********************************************************************/
vector<int> prefix(vector<int> &v){
  vector<int> pv=v;
  for(int i=1;i<v.size();i++) pv[i]+=pv[i-1];
  return pv;
}

/********************************************************************
*********************************************************************/
vector<int> read_v(const int n){
  vector<int> v(n);
  for(int i=0;i<n;i++) cin>>v[i];
  return v;
}

/********************************************************************
*********************************************************************/
void display(const int mxR, vector<int> &pv){
  cout<<"Board cost: "<<dp[0][0]<<endl;
  //ans[mxR]=pv.size()-1;
  for(int i=0, j=0;i<=mxR;i++){
    cout<<"("<<j+1<<", "<<ans[i]+1<<") --> "<<endl;
    j=ans[i]+1;
  }
  cout<<endl;

  /*for(int i=0;i<=mxR;i++){
    cout<<"("<<ans[i]+1<<", "<<(ans[i+1]+1)+1<<") --> "<<endl;
  }
  cout<<"mxR: "<<mxR<<endl;*/
}
















