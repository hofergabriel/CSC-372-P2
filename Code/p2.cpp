#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;


/**********************************************************
Read the Announcements 
***********************************************************/
map<int,int> readm(int n){
  map<int,int> m;
  for(int e, i=0;i<n;i++) 
    cin>>m[i];
  return m;
}

/**********************************************************
Make a Row in the Board
***********************************************************/
set<int> makeRow(map<int,int> &m, int bw){
  int dp[bw+1]; 
  for(int i=0;i<=bw;i++) dp[i]=-1; // initialize
  dp[0]=-2;
  for(map<int,int>::iterator it=m.begin(); it!=m.end(); ++it){
    for(int j=bw; j>=it->second; --j){
      if(dp[j]==-1 && dp[j-(it->second)]!=-1)
        dp[j]=it->first;
      if(dp[bw]!=-1) break; // break early if we find a complete row
    }
    dp[it->second]=it->first;
  }
  // construct the row
  set<int> row;
  int idx=-1;
  for(int i=bw; i>=0 && idx==-1; --i)
    if(dp[i]!=-1) idx=i;
  if(idx==-1) return {}; 
  int cpy;
  while(idx!=0){
    row.insert(dp[idx]);
    cpy=dp[idx];
    idx-=m[dp[idx]];
    m.erase(cpy);
  }
  return row;
}

/**********************************************************
make Board
***********************************************************/
vector<set<int>> makeBoard(map<int,int> &m, int bw){
  vector<set<int>> board;  
  while(!m.empty())
    board.push_back(makeRow(m,bw));
  return board;
}

/**********************************************************
Main function
***********************************************************/
int main(){
  int bw, n;
  map<int,int> m;
  vector<set<int>> bb;

  // read board width
  cin>>bw;
  cout<<"Board Width: "<<bw<<endl;
  cin>>n;
  cout<<"Announcements: "<<n<<endl;
  m=readm(n);
  cout<<"read board"<<endl;

  bb=makeBoard(m,bw);

  for(int i=0;i<bb.size();i++){
    for(auto e:bb[i])
      cout<<e<<' ';
    cout<<endl;
  }
  return 0;
}




