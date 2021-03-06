/*
* Program: To check mathematical expression is valid or not.
*Author: Ashim Shrestha.
Date: July 17, 2016.
Reference:  Data structures using C and C++, chap 2, page 82
*/

#include <stdio.h>
#include <string.h>
#define max 100

typedef struct{
	int top;
	char items[max];
}stack;

void push(stack *,char);
char pop(stack*);
char opening(char);
int main()
{
	char a[max],w,d;
	stack s;
	s.top=-1;
	int i,valid=1;
	
	printf("Enter the equation:\n");
	scanf("%s",&a);
	
	for(i=0;i<strlen(a);i++)
	{
		printf("%d\n",i);
		if(a[i]=='(' || a[i]=='{' || a[i]=='[')
		{
			push(&s,a[i]);
		}
		if (a[i]==')' || a[i]=='}' || a[i]==']')
		{	
			if(s.top==-1)
			{
			valid=0;
			}
			
			else
			{
			w=pop(&s);
			d=opening(a[i]);
			
			
			if(w!=d)
			{
			valid=0;
			}
			}
		
		}
		
	}
	
if(!(s.top==-1))
{
	valid=0;
}

if(valid==1)
{
	printf("valid");
}

else
{
	printf("invalid");
}
}

void push(stack *s, char x)
{
	s->items[++(s->top)]=x;
}

char pop(stack *s)
{
	return s->items[(s->top)--];
}

char opening(char c)
{
	if(c==')')
	{
		return'(';
	}
	else if(c=='}')
	{
		return'{';
	}
	else if(c==']')
	{
		return'[';
	}
}


