#include "iostream"
#include <vector>
using namespace std;

void TE(int **matrix,int *te,int ras,int n)
{
	for(int i=0;i<n;i++)
	{
		if(matrix[ras][i]!=0)
		{
			if(te[i] < te[ras] + matrix[ras][i])
			{
				te[i] = te[ras] + matrix[ras][i];
			}
			TE(matrix,te,i,n);
		}
	}
}

void TL(int **matrix,int *tl,int *te,int n)
{
	for(int i=0;i<n;i++)
	{
		for (int j=0;j<n;j++)
		{
			if(matrix[i][j]!=0)
			{
				if(tl[i] > te[j] - matrix[i][j])
				{
					tl[i] = te[j] - matrix[i][j];
				}
			}	
		}
	}
}

void CriticalPathes(int **matrix,int *te,int *tl,vector<int> *way,int ras,int n)
{
	if(ras==n-1)
	{
		for (int i=0;i<way->size()-1;i++)
		{
			cout << (*way)[i]+1 << "->";
		}
		cout<<(*way)[way->size()-1]+1<<endl;
		return;
	}
	else
	{
		for(int i=0;i<n;i++)
		{
			if(matrix[ras][i]!=0 && te[i]==tl[i])
			{
				way->push_back(i);
				CriticalPathes(matrix,te,tl,way,i,n);
				way->pop_back();
			}
		}
	}
}

int main()
{
	////////////Sakhtan matrix mojaverat geraf////
	int n=0;
	cout<<"Tedad rous ra vared konid : ";
	cin>>n;
	int vertex1,vertex2,weight;
	int **matrix;
	matrix = new int*[n];
	for(int i=0;i<n;i++)
	{
		matrix[i] = new int[n];
		for(int j=0;j<n;j++)
		{
			matrix[i][j]=0;
		}
	}
	cout<<"Moshakhasat yal ha (ebteda enteha weight)"<<endl;
	cin>>vertex1>>vertex2>>weight;
	while(weight!=-1)
	{
		matrix[vertex1-1][vertex2-1]=weight;
		cin>>vertex1>>vertex2>>weight;
	}
	cout<<endl;
	////////////////////////////////////////////////
	int *te=new int[n];
	te[0]=0;
	TE(matrix,te,0,n);
	////////////////////////////////////////////////
	int *tl=new int[n];
	for (int i=0;i<n;i++)
	{
		tl[i]=te[n-1];
	}
	TL(matrix,tl,te,n);
	////////////////////////////////////////////////
	for (int i=0;i<n;i++)
	{
		cout<<"Rase "<<i+1<<" : TE = "<<te[i]<<" , TL = "<<tl[i]<<endl;
	}
	////////////////////////////////////////////////
	vector<int> *way = new vector<int>;
	way->push_back(0);
	cout<<endl<<"CriticalPathes :"<<endl;
	CriticalPathes(matrix,te,tl,way,0,n);
}