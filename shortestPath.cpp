#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 1e2;
const int INF = 1e9;

int n , m;
int dist[MAXN][MAXN];
int between[MAXN][MAXN];

void floyd_warshall(){
  for(int k = 0 ; k < n ; k++){
    for(int i = 0 ; i < n ; i++)
      for(int j = 0 ; j < n ; j++)
	if(k != i && k != j && dist[i][j] > dist[i][k] + dist[k][j]){
	  dist[i][j] = dist[i][k] + dist[k][j];
	  between[i][j] = k;
	}
  }
}

void print(int x , int y){
  int z = between[x][y];
  if(x == y){
    cout << x << " ";
    return;
  }
  if(z == x || z == y){
    cout << x << " ";
    return;
  }
  print(x , z);
  print(z , y);
}

void prepareForPrint(){
  for (int x = 0; x < n; x++)
  {
	  for (int y = 0; y < n; y++)
	  {
		cout << "Minimum dist  "<<x <<"->"<<y <<"= "<< dist[x][y] << endl;
    	print(x , y);
    	cout << y << endl;
	  } 
  }
  
}

int main(){
//give input and initialize
  int x , y , w;
  cout << "Enter the number of vertices then the number of edges:" << endl;
  cin >> n >> m;
//initialize the matrix of distances and auxiliary matrix
for(int i = 0 ; i < n ; i++){
    for(int j = 0 ; j < n ; j++)
      dist[i][j] = INF;
    dist[i][i] = 0;
    between[i][i] = i;
  }
//input matrix of graph
  for(int i = 0 ; i < m ; i++){
    cin >> x >> y >> w;
    dist[x][y] = w;
    between[x][y] = x;
  }
  floyd_warshall();
  prepareForPrint();
}
