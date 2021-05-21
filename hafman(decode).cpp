#include "iostream"
#include <fstream>
#include <stack>
#include <vector>
#include <math.h>
using namespace std;

int mabna(string h)
{
	int out=0;
	for(int i=0;i<h.size();i++)
	{
		if(h[i]=='1')
		{
			out+=pow(2,h.size()-i-1);
		}
	}
	return out;
}

int main()
{
	int n=0;
	int ascii=0;
	int len=1;
	string read="";
	string character;
	string **final_hafman;
	////////////////////////////////////
	ifstream file;
	string line;
	file.open("encode.txt");
	if(file.is_open())
	{
		getline(file,line);
		n=mabna(line);
		
		final_hafman = new string*[n];
		for(int i=0;i<n;i++)
		{
			final_hafman[i] = new string[2];
		}

		for(int i=0;i<n;i++)
		{
			getline(file,line);
			ascii=mabna(line.substr(0,7))+32;
			character=(char)ascii;
			final_hafman[i][0]=character;
			final_hafman[i][1]=line.substr(7,line.size()-7);
			cout<<final_hafman[i][0]<<" : "<<final_hafman[i][1]<<endl;
		}

		ofstream output_file;
		output_file.open ("decode.txt");
		while(getline(file,line))
		{
			//cout<<line<<endl;
			while(line!="")
			{
				read=line.substr(0,len);
				//cout<<read<<","<<len<<endl;
				for(int i=0;i<n;i++)
				{
					if(read==final_hafman[i][1])
					{
						output_file<<final_hafman[i][0];
						line=line.substr(len,line.size()-len);
						len=1;
						break;
					}
				}
				len++;
			}
			output_file<<"\n";
		}
		file.close();
	}
	else
	{
		cout<<"Unable to open file"; 
	}
}