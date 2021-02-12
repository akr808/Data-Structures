#include<iostream>
#include<stdio.h>

int main()
{
std::string s,p,q;
std::cout<<"Enter the parent String:";
std::cin>>s;
std::cout<<"Enter the pattern String:";
std::cin>>p;
int j = 0;
std::cout<<s<<"\n";
int flg = 1;
int next;
for(int i = 0;i < s.length()-p.length();i = (next != -1?next:i+p.length()))
{

	flg = 1;
	for(int j = 0;j < i;j++)
		std::cout<<" ";
	next = -1;
	for(int j = 0;j < p.length();j++)
	{

		std::cout<<p[j];
		if(s[i+j] == p[0] && next == -1 && j != 0)
			next = i+j;
		if(s[i+j] != p[j])
		{
			if(next == -1)
				next = i+j+1;
			flg = 0;
			break;
		}

		//std::cout<<"\ni = "<<i<<"\nj = "<<j<<"\nNext = "<<next<<"\n";
		//getchar();

}

std::cout<<"\n";
	if(flg == 1)
	{
		std::cout<<"Matched at location "<<i+1<<" from the left!!...\n";
		break;
	}
	
}
return 0;
}
