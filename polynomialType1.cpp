//Mohammad Sadegh Salehi 610395120
#include <iostream>
#include<math.h>
#include<algorithm>
using namespace std;
int* polysum(int* p1,int* p2,bool type)
{
if(!type)
{
    int maximum = max(p1[0],p2[0]);
    int n1= p1[0];int n2=p2[0];
    int* sum = new int[maximum+2] ;
    sum[0]=maximum;
    for(int i = 1; i < maximum+2; i++)
    {
        if(n1>n2)
        {
                    int count =1;
                    int* temp = new int[n1+2];
                    for(int i = 0; i < n1-n2+1; i++)
                    {
                        temp[i]=0;
                    }
                    for(int i=n1-n2+1;i<n1+2;i++)
                    {
                        temp[i]=p2[count];
                        count++;
                    }
                    for(int i = 0; i < n1+2; i++)
                    {
                        sum[i]=temp[i]+p1[i];
                    }
        }
        else if(n2>n1)
        {
                    int count =1;
                    int* temp = new int[n2+2];
                    for(int i = 0; i < n2-n1+1; i++)
                    {
                        temp[i]=0;
                    }
                    for(int i=n2-n1+1;i<n2+2;i++)
                    {
                        temp[i]=p1[count];
                        count++;
                    }
                    for(int i = 0; i < n2+2; i++)
                    {
                        sum[i]=temp[i]+p2[i];
                    }
                    
        }
        else
        {
            for(int i = 1; i < n1+2; i++)
            {
                sum[i]=p1[i]+p2[i];
            }
            
        }
        
    }
return sum;
     
}
}
polyprod(int* p1,int* p2,bool type)
{
    int n1 =p1[0];
    int n2 =p2[0];
    int prod[n1+n2+2];
    prod[0]=n1+n2;
    for(int i=1;i<n1+n2+2;i++)
    {
        prod[i]=0;
    }
    for(int i = 1; i < n1+2; i++)
    {
        for(int j=1;j<n2+2;j++)
        {
            prod[i+j-1]+=p1[i]*p2[j];
        }
    }
    prod[n1+n2+1]=p1[n1+1]*p2[n2+1];
    cout<<"product is:  ";
    for(int i=0;i<n1+n2+2;i++)
    {
        cout<<prod[i]<<" ";
    }
    cout<<endl;
}
int main()
{
int* p1;int* p2;
int n1,n2;
bool type;
cout<<"Enter 0 to START"<<endl;
cin>>type;
if (!type)
{
cout<<"Enter the first polynomial degree"<<endl;
cin>>n1;
cout<<"Enter the second polynomial degree"<<endl;
cin>>n2;
p1=new int[n1+2];
p1[0]=n1;
p2=new int[n2+2];
p2[0]=n2;
cout<<"Enter the first polynomial coeficients"<<endl;
for(int i=1;i<(n1+2);i++)
{
    cin>>p1[i];
}
cout<<"Enter the second polynomial coefficients"<<endl;
for(int i=1;i<(n2+2);i++)
{
    cin>>p2[i];
}
}
int * result=polysum(p1,p2,type);
polyprod(p1,p2,type);
cout<<"sum is: ";
    for(int i = 0; i < result[0]+2; i++)
    {
        cout<<result[i]<<" ";
    }
}