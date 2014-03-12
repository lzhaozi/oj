#include <iostream>
#include <stdio.h>
#include <stack>
using namespace std;

int main()
{
	char s[101];
	while(scanf("%s",s)!=EOF)
	{
		stack<int> str;
		char s2[101];
		int i;
		for(i=0;s[i]!='\0';i++)
		{
			if(s[i]=='(')
			{
				str.push(i);
				s2[i]=' ';
			}else if(s[i]==')')
			{
				if(str.empty()==false)
				{
					s2[i]=' ';
					str.pop();
				}else
				{
					s2[i]='?';
				}
			}else
			{
				s2[i]=' ';
			}
		}
		while(!str.empty())
		{
			s2[str.top()]='$';
			str.pop();
		}
		s2[i]='\0';
		printf("%s\n",s);
		printf("%s\n",s2);
	}
	return 0;
}
