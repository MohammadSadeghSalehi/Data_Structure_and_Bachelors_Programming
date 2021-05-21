//Mohammad Sadegh Salehi

//order of input arrays are decending
#include <iostream>
using namespace std;
int* merge(int* v1,int l1,int* v2,int l2,int number)
{
    int*result=new int[l1+l2];
int i=0,j=0,k=0;
    while((l1)!=i&&(l2)!=j){
        if(v1[i]>=v2[j])
        {
            result[k]=v1[i];
            i++;
        }
        else
        {
            result[k]=v2[j];
            j++;
        }
        k++;
    }
    if ((l1)!=i) {
        while((l1)!=i){
            result[k]=v1[i];
            i++;
            k++;
        }
    }
    else if ((l2)!=j) {
        while((l2)!=j){
            result[k]=v2[j];
            j++;
            k++;
        }
    }
    if (number==2)
    {
        for(int i = 0; i < l1+l2; i++)
        {
            cout<<result[i]<<endl;
        }
    }
    else
    {
        return result;
    }
    
}
int main()
{   cout<<"enter number of arrays (2 or 3)"<<endl;
    int number=2;
    cin>>number;
    int l1,l2,l3;
    cin>>l1;
    cin>>l2;
    int*v1=new int[l1];
    int*v2=new int[l2];
    for(int i=0;i<l1;i++)
    {
        cin>>v1[i];
    }
    for(int i=0;i<l2;i++)
    {
        cin>>v2[i];
    }
    int * v3=merge(v1,l1,v2,l2,number);
    if (number==3)
    {   
        cout<<"enter the length of third array"<<endl;
        cin>>l3;
        int*v4=new int[l3];
        for(int i=0;i<l3;i++)
        {
            cin>>v4[i];
        }
        number=2;
        int *temp=merge(v3,l1+l2,v4,l3,number);
    }
    
}
