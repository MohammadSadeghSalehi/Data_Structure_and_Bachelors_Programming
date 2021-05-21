#include "iostream"
#include <stack>
#include <vector>
using namespace std;
void Dijkstra(int **matrix,int source,int n)
{
	int min=0;
	int w=0,wn=0;
	///////////////////////////////////
	vector<int> h;//V-S
	for(int i=0;i<n;i++)
	{
		if(i!=source)
			h.push_back(i);
	}
	////////////////////////////////////
	int D[n];
	int Prev[n];
	for(int i=0;i<h.size();i++)
	{
		D[h[i]]=matrix[source][h[i]];
		Prev[h[i]]=source;
	}
	////////////////////////////////////
	for(int i=0;i<n-1;i++)
	{
		min=D[h[0]];
		w=h[0];
		wn=0;
		for(int j=1;j<h.size();j++)
		{
			if(min>D[h[j]])
			{
				min=D[h[j]];
				w=h[j];
				wn=j;
			}
		}
		h.erase(h.begin() + wn);
		for(int j=0;j<h.size();j++)
		{
			if( D[w]+matrix[w][h[j]] < D[h[j]])
			{
				D[h[j]]=D[w]+matrix[w][h[j]];
				Prev[h[j]]=w;
			}
		}
	}
	/////////////////////////////////////
	stack<int> Way;
	int b=0;
	cout<<"Az rase V"<<source+1<<endl;
	for(int i=0;i<n;i++)
	{
		if(i!=source)
		{
			if(D[i]!=100000)
			{
				cout<<"Ta rase V"<<i+1<<" "<<D[i]<<" ( Way : "<<source+1;
				b=i;
				Way.push(b);
				while(Prev[b]!=source)
				{
					Way.push(Prev[b]);
					b=Prev[b];
				}
				while(!Way.empty())
				{
					cout<<" -> "<<Way.top()+1;
					Way.pop();
				}
				cout<<" )"<<endl;
			}
			else
				cout<<"Ta rase V"<<i+1<<" No"<<endl;
		}
	}
	cout<<endl;
}
int main()
{
	////////////matrix mojaverat graph////
	int n=0;
	cout<<"Tedad rous ra vared konid : ";
	cin>>n;
	int ras1,ras2,vazn;
	int **matrix;
	matrix = new int*[n];
	for(int i=0;i<n;i++)
	{
		matrix[i] = new int[n];
		for(int j=0;j<n;j++)
		{
			matrix[i][j]=100000;
		}
	}
	cout<<"Moshakhasat yal ha (ebteda enteha vazn)"<<endl;
	cin>>ras1>>ras2>>vazn;
	while(vazn!=-1)
	{
		matrix[ras1-1][ras2-1]=vazn;
		cin>>ras1>>ras2>>vazn;
	}
	cout<<endl;
	//////////////////////////////////////////////
	for(int i=0;i<n;i++)
	{
		Dijkstra(matrix,i,n);
	}
}