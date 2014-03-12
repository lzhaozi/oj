#include <stack>
#include <stdio.h>
using namespace std;

stack<double> in;//the stack to store the data to be calculated
stack<int> op;//the stack to store the operator

//the priority number that stands for the five operators #,+,-,*,/
//if mat[i][j]==1, that means operator i is more priority than operator j
int mat[5][5]=
{
	1,0,0,0,0,
	1,0,0,0,0,
	1,0,0,0,0,
	1,1,1,0,0,
	1,1,1,0,0
};

//char array to store the expression
char str[220];

//function to get the next data
//if the next data is operator, then the reto is true and the retn is the op
//if the next data is figure, then the reto is false and the retn is the figure
void nextdata(bool &reto,int &retn,int &idx)
{
	char tmp;
	tmp=str[idx];
	if(tmp>='0'&&tmp<='9')
	{
		reto=false;
		retn=str[idx]-'0';
	}else
	{
		reto=true;
		if(str[idx]=='+')
			retn=1;
		else if(str[idx]=='-')
			retn=2;
		else if(str[idx]=='*')
			retn=3;
		else if(str[idx]=='/')
			retn=4;
		else
			retn=0;
		if(retn)
			idx+=2;
		return;
	}
	while(true)
	{
		idx++;
		if(str[idx]>='0'&&str[idx]<='9')
		{
			retn*=10;
			retn=retn+str[idx]-'0';
		}else if(str[idx]==' ')
		{
			idx++;
			break;
		}else if(str[idx]==0)
		{
			break;
		}
	}
}

int main()
{
	while(gets(str))
	{
		//if the expression is 0, then the program is over
		if(str[0]=='0'&&str[1]==0)
			break;

		char tmp;
		int idx=0;
		bool retop=false;
		int retnum=-1;

		while(true)
		{
			//get the next data
			nextdata(retop,retnum,idx);

			if(retop==true)
			{
				if(op.empty())//the first operator of the expression
				{
					op.push(0);
					op.push(retnum);
				}else if(mat[retnum][op.top()]==1)//the new op has higher priority
				{
					op.push(retnum);
				}else if(mat[retnum][op.top()]==0)//the new op has lower priority
				{
					//calculate until the lower priority op happens
					while(mat[retnum][op.top()]==0)
					{
						//this is the bug which costs too much time
						//remember filo, so the first double is 2,not 1
						double in2=in.top();
						in.pop();
						double in1=in.top();
						in.pop();
						int opr=op.top();
						op.pop();
						switch(opr)
						{
							case 1:
								in1=in1+in2;
								break;
							case 2:
								in1=in1-in2;
								break;
							case 3:
								in1=in1*in2;
								break;
							case 4:
								in1=in1/in2;
								break;
							default:
								break;
						}
						in.push(in1);
					}
					if(op.top()!=0)
						op.push(retnum);
					else if(retnum!=0)
						op.push(retnum);
					else
						break;
				}
			}else if(retop==false)
			{
				in.push(retnum);
			}
			double top=in.top();
		}
		printf("%.2f\n",in.top());
	}
	return 0;
}
