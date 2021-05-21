#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 1e3 + 10;

int n , m;
int a[MAXN][MAXN];
int dp[MAXN];

void input(){
  cout << "Enter the dimensions:" << endl;
  cin >> n >> m;
  cout << "Enter 0 for white 1 for black" << endl;
  for(int i = 0 ; i < n ; i++)
    for(int j = 0 ; j < m ; j++)
      cin >> a[i][j];
}

int max_r(){
  vector <int> s;
  int max_area = 0;
  int top;
  int top_area;

  int i = 0;
  while(i < m){
    if(s.size() == 0 || dp[s[s.size() - 1]] <= dp[i])
      s.push_back(i++);
    else{
      top = s[s.size() - 1];
      s.pop_back();
      top_area = dp[top] * (s.size() == 0 ? i : i - s[s.size() - 1] - 1);
      max_area = max(max_area , top_area);
    }
  }
  while(s.size() != 0){
    top = s[s.size() - 1];
    s.pop_back();
    top_area = dp[top] * (s.size() == 0 ? i : i - s[s.size() - 1] - 1);
    max_area = max(max_area , top_area);
  }
  return max_area;
}

int solve(){
  for(int i = 0 ; i < m ; i++)
    dp[i] = a[0][i];
  int res = max_r();
  for(int i = 1 ; i < n ; i++){
    for(int j = 0 ; j < m ; j++)
      dp[j] = (a[i][j] == 1 ? dp[j]+1 : 0);
    res = max(res , max_r());
  }
  return res;
}

void init(){
  for(int i = 0 ; i < n ; i++)
    for(int j = 0 ; j < m ; j++)
      a[i][j] = 1 - a[i][j];
}

int main(){
  input();
  int res_black = solve();
  init();
  int res_white = solve();
  if(res_white > res_black)
    cout << res_white << " white" << endl;
  else
    cout << res_black << " black" << endl;
  
  return 0;
}
