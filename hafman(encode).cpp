#include "iostream"
#include <fstream>
#include <stack>
#include <vector>
using namespace std;
int c=0;
class node
{
		node *left;
		node *right;
		double data;
		string word;
	public:

		node(node *nleft,double ndata,string nword,node *nright)
		{
			left=nleft;
			data=ndata;
			word=nword;
			right=nright;
		}
		void Change(double newdata)
		{
			data=newdata;
			return;
		}
		void set_left_node(node* newleft)
		{
			left=newleft;
			return;
		}
		void set_right_node(node* newright)
		{
			right=newright;
			return;
		}
		node* right_node()
		{
			return right;
		}
		node* left_node()
		{
			return left;
		}
		double get_data()
		{
			return data;
		}
		string get_word()
		{
			return word;
		}

};

void inorder(vector<string> *hafman,string **final_hafman,node *Tree,string side)
{
	if(Tree!=0)
	{
		hafman->push_back(side);
		inorder(hafman,final_hafman,Tree->left_node(),"0");
		if(Tree->get_word()!="-1")
		{
			final_hafman[c][0]=Tree->get_word();
			//cout<<Tree->get_word()<<" : ";
			for(int i=1;i<hafman->size();i++)
			{
				//cout<<(*hafman).at(i);
				final_hafman[c][1]+=(*hafman).at(i);
			}
			//cout<<endl;
			c++;
		}
		inorder(hafman,final_hafman,Tree->right_node(),"1");
		hafman->pop_back();
	}
}

string code_chr_binary(string h)
{
	char character=h[0];
	int ascii=(int)character-32;
	stack<int> binary;
	string out="";
	while(ascii!=0)
	{
		binary.push(ascii%2);
		ascii/=2;
	}
	while(!binary.empty())
	{
		if(binary.top()==1)
		{
			out+="1";
		}
		else
		{
			out+="0";
		}
		binary.pop();
	}
	int os=7-out.size();
	for (int i=0;i<os;i++)
	{
		out="0"+out;
	}
	return out;
}

string mabna(int h)
{
	stack<int> binary;
	string out="";
	while(h!=0)
	{
		binary.push(h%2);
		h/=2;
	}
	while(!binary.empty())
	{
		if(binary.top()==1)
		{
			out+="1";
		}
		else
		{
			out+="0";
		}
		binary.pop();
	}
	return out;
}

int main()
{
	int n=0;
	string word="";
	/////////////////////////////////////////////////////////
	ifstream file;
	string line;
	char character;
	int ascii;
	int chr[94];
	for(int i=0;i<94;i++)
	{
		chr[i]=0;
	}
	file.open("data.txt");
	if(file.is_open())
	{
		while(getline(file,line))
		{
			for(int i=0;i<line.size();i++)
			{
				character = line[i];
				ascii = (int) character;
				chr[ascii-32]++;
			}
		}
		file.close();
	}
	else
	{
		cout<<"Unable to open file"; 
	}
	
	for(int i=0;i<94;i++)
	{
		if(chr[i]!=0)
		{
			n++;
		}
	}
	/////////////////////////////////////////////////////////
	int index_min1;
	double min1;
	int index_min2;
	double min2;
	vector<node*> keep;
	node* node_min1;
	node* node_min2;
	string **final_hafman;
	final_hafman = new string*[n];
	for(int i=0;i<n;i++)
	{
		final_hafman[i] = new string[2];
	}
	////////////////////////////////////////////////////////
	for(int i=0;i<94;i++)
	{
		if(chr[i]!=0)
		{
			word=(char)(i+32);
			cout<<word<<" "<<chr[i]<<endl;
			node *newnode = new node(0,chr[i],word,0);
			keep.push_back(newnode);
		}
	}
	
	/////////////////////////////////////////////////////////
	
	while(keep.size()!=1)
	{
		index_min1=0;
		min1=keep[0]->get_data();
		for(int i=1;i<keep.size();i++)
		{
			if(keep[i]->get_data()<min1)
			{
				min1=keep[i]->get_data();
				index_min1=i;
			}
		}
		node_min1=keep[index_min1];
		keep.erase(keep.begin() + index_min1);
		////
		index_min2=0;
		min2=keep[0]->get_data();
		for(int i=1;i<keep.size();i++)
		{
			if(keep[i]->get_data()<min2)
			{
				min2=keep[i]->get_data();
				index_min2=i;
			}
		}
		node_min2=keep[index_min2];
		keep.erase(keep.begin() + index_min2);
		////
		node *newnode = new node(node_min1,min1+min2,"-1",node_min2);
		keep.push_back(newnode);
	}
	///////////////////////////////////////////////////////////
	vector<string> *hafman = new vector<string>;
	inorder(hafman,final_hafman,keep[0],"0");
	///////////////////////////////////////////////////////////
	for(int i=0;i<n;i++)
	{
		cout<<final_hafman[i][0]<<" : "<<final_hafman[i][1]<<endl;
	}
	///////////////////////////////////////////////////////////
	ofstream output_file;
	output_file.open ("encode.txt",ios::binary);
	string s="";
	output_file<<mabna(n)<<"\n";
	for(int i=0;i<n;i++)
	{
		output_file<<code_chr_binary(final_hafman[i][0])<<final_hafman[i][1]<<"\n";
	}
	file.open("data.txt");
	if(file.is_open())
	{
		while(getline(file,line))
		{
			for(int i=0;i<line.size();i++)
			{
				s=line[i];
				for(int j=0;j<n;j++)
				{
					if(final_hafman[j][0]==s)
					{
						output_file<<final_hafman[j][1];
					}
				}
			}
			output_file<<"\n";
		}
		file.close();
	}
	else
	{
		cout<<"Unable to open file"; 
	}
	output_file.close();
}