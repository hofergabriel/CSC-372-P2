/********************************************************************
Author: Gabriel Hofer
Instructor: Dr. Rebenitsch
Date: October 8, 2020
Course: CSC-372
*********************************************************************/
#include <iostream>
#include <vector>
#include <map>
#define inf 1e9
using namespace std;

void readv(int n);
vector<int> prefix(vector<int> &v);
void brute(vector<int> &pv, int loc, int row, int bw);
map<int,map<int,int>> dp;

/********************************************************************
*********************************************************************/
int main(){
  int bw, n;
  cin>>bw>>n; // read board width & number of announcements 

  v=readv(n) // read announcements
  pv=prefix(v); // make prefix vector
  brute(v); // solve naively??

  return 0;
}

/********************************************************************
Solution shoudl be in dp[row=0][loc=0] ... 
@param mnC - min cost
@param mnLoc - location/index where mnC is found
*********************************************************************/
void brute(vector<int> &pv, int loc, int row, int bw){
  if(row>mxR) return inf; 
  if(loc==v.size()) return 0;
  for(int loc2=loc, mnC=1e9, mnLoc, t; pv[loc2]-(loc==0 ? 0:pv[loc-1])<=bw; loc2++){
    t = 
      pow(bw-(pv[loc2]-(loc==0 ? 0:pv[loc-1])),3) + 
      brute(pv,loc2+1,row+1,bw); // need to account for loc-1<0
    if(t<mnC){ mnC=t; mnLoc=loc2; }
  }
  return dp[row][loc]=mnC;
}

/********************************************************************
*********************************************************************/
vector<int> prefix(vector<int> &v){
  vector<int> pv=v;
  for(int i=1;i<n;i++) pv[i]+=v[i-1];
  return pv;
}

/********************************************************************
*********************************************************************/
void readv(int n){
  vector<int> v(n);
  for(int i=0;i<n;i++) cin>>v[i];
  return v;
}





