#include<iostream>
#include<stdio.h>

int main()
{
std::string s,p,q;
std::cout<<"Enter the parent String:";
std::cin>>s;
std::cout<<"Enter the pattern String:";
std::cin>>p;
for(int i = 0;i < s.length()-p.length();i++)
{
	int flg = 1;
	for(int j = 0;j < p.length();j++)
	{
		if(s[i+j] != p[j])
		{
			flg = 0;
			break;
		}
	}
	if(flg == 1)
	{
		std::cout<<"String matched at location "<<i+1<<"\n";
		break;
	}
	else
	{
		if( i == s.length()-p.length() - 1)
			std::cout<<"No match found!!...\n";
	}
}

return 0;
}
