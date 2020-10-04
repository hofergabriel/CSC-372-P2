#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

void readv(int n);
vector<int> prefix(vector<int> &v);
void brute(vector<int> &v, vector<int> &pv, int a, int b, int row, int bw);


int main(){
  int bw, n;
  cin>>bw>>n;

  v=readv(n)
  pv=prefix(v);
  brute(v);

  return 0;
}

void brute(vector<int> &v, vector<int> &pv, int loc, int row, int bw){

  if(pv[b]-pv[a-1]>bw) return;
  // [insert memoization here]
  int cost = bw-(pv[loc2]-pv[loc-1]);

  int loc2=loc+1;
  for(int loc2=loc+1; pv[b]-pv[a-1]<=bw; loc2++){
    // get min
    brute(v,pv,loc2,row+1,bw) 
  }
  return cost + mn;
}

vector<int> prefix(vector<int> &v){
  vector<int> pv=v;
  for(int i=1;i<n;i++) pv[i]+=v[i-1];
  return pv;
}

void readv(int n){
  vector<int> v(n);
  for(int i=0;i<n;i++) cin>>v[i];
  return v;
}



























