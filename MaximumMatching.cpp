#include "iostream"
#include <stack>
#include <queue>
#include <vector>
#include <limits.h>
using namespace std;

bool bfs(int **matrix,int *Pair_U,int *Pair_V,int *Dist,vector<int> *U,vector<int> *V)
{
	int u=0;
	queue<int> Q;
	for(int u=1;u<=U->size();u++)
	{
		if(Pair_U[u]==0)
		{
			Dist[u]=0;
			Q.push(u);
		}
		else
		{
			Dist[u] = INT_MAX;
		}
	}
	Dist[0] = INT_MAX;
	while(!Q.empty())
	{
		u = Q.front();
		Q.pop();
		if(Dist[u]<Dist[0])
		{
			for (int i=0;i<V->size();i++)
			{
				if(matrix[u][(*V)[i]]!=0)
				{
					if(Dist[Pair_V[(*V)[i]]]==INT_MAX)
					{
						Dist[Pair_V[(*V)[i]]]=Dist[u]+1;
						Q.push(Pair_V[(*V)[i]]);
					}
				}
			}
		}
	}
	return Dist[0] != INT_MAX;
}

bool dfs(int **matrix,int *Pair_U,int *Pair_V,int *Dist,vector<int> *U,vector<int> *V,int u)
{
	if(u!=0)
	{
		for (int i=0;i<V->size();i++)
		{
			if(matrix[u][(*V)[i]]!=0)
			{
				if(Dist[Pair_V[(*V)[i]]]==Dist[u]+1)
				{
					if(dfs(matrix,Pair_U,Pair_V,Dist,U,V,Pair_V[(*V)[i]]))
					{
						Pair_V[(*V)[i]]=u;
						Pair_U[u]=(*V)[i];
						return true;
					}
				}
			}
		}
		Dist[u] = INT_MAX;
		return false;
	}
	return true;
}

int Maximum_Matching(int **matrix,vector<int> *U,vector<int> *V)
{
	int *Pair_U = new int[U->size()+1];
	int *Pair_V = new int[V->size()+1];
	int *Dist = new int[U->size()+1];

	for(int u=0;u<=U->size();u++)
	{
		Pair_U[u] = 0;
	}
	for(int v=0;v<=V->size();v++)
	{
		Pair_V[v] = 0;
	}
	int matching=0;
	while(bfs(matrix,Pair_U,Pair_V,Dist,U,V))
	{
		for(int u=1;u<=U->size();u++)
		{
			if(Pair_U[u]==0)
			{
				if(dfs(matrix,Pair_U,Pair_V,Dist,U,V,u))
				{
					matching++;
				}
			}
		}
	}
	return matching;
}

int main()
{
	////////////Sakhtan matrix mojaverat geraf////
	int n=0;
	cout<<"Tedad rous ra vared konid : ";
	cin>>n;
	int ras1,ras2;
	int **matrix;
	vector<int> *U = new vector<int>;
	vector<int> *V = new vector<int>;
	matrix = new int*[n+1];
	for(int i=0;i<=n;i++)
	{
		matrix[i] = new int[n+1];
		for(int j=0;j<=n;j++)
		{
			matrix[i][j]=0;
		}
	}
	int x=0,y=0;
	cout<<"Tedad rous bakhshe U : ";
	cin>>x;
	for(int i=1;i<=x;i++)
	{
		U->push_back(i);
	}
	cout<<"Tedad rous bakhshe V : ";
	cin>>y;
	for(int i=1;i<=y;i++)
	{
		V->push_back(i);
	}
	cout<<"Moshakhasat yal ha (Ebteda(U) Enteha(V))"<<endl;
	cin>>ras1>>ras2;
	while(ras2!=-1)
	{
		matrix[ras1][ras2]=1;
		matrix[ras2][ras1]=1;
		cin>>ras1>>ras2;
	}
	//////////////////////////////////////////////
	int MaximumMatching = Maximum_Matching(matrix,U,V);
	cout<<"Maximum Matching : "<<MaximumMatching<<endl;
	if(n%2==0 && MaximumMatching==n/2)
	{
		cout<<"Tataboq kamel"<<endl;
	}
}