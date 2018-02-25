#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int getpriority(char c);
int isempty();
int isoperator(char c);


char stack[500];
int top=-1;

int getpriority(char c)
{
  if(c=='^')
  return 3;
  else if(c=='/' || c=='*')
  return 2;
  else if(c=='+' || c=='-')
  return 1;
}

int isempty()
{
  if(top==-1)
  return 1;
  else
  return 0;
}

int isoperator(char c)
{
  if(c=='+' || c=='-' || c=='*' || c=='/' || c=='^' || c=='(' || c==')')
  return 1;
  else return 0;
}

void print(char *arr)
{
  for(int i=0;arr[i]!='\0';i++)
  {
    printf("%c",arr[i]);
  }
}

int main()
{
  char x[100];
  scanf("%s",x);

  for(int i=0;x[i]!='\0';i++)
  {
    if( isoperator(x[i])==0)
    printf("%c",x[i]);
    else{

      if(isempty()==1 && x[i]!=')')
      {
        stack[++top]=x[i];
      }
      else if(isempty()==0 && x[i]!=')' && getpriority(stack[top])<getpriority(x[i])){
        stack[++top]=x[i];
      }
      else if(x[i]=='(')
      stack[++top]=x[i];
      else if(stack[top]=='(' && x[i]!=')')
      stack[++top]=x[i];
      else if(isempty()==0 && getpriority(stack[top])>=getpriority(x[i]))
      {
        while(isempty()==0 && getpriority(stack[top])>=getpriority(x[i]))
        printf("%c",stack[top--]);

        stack[++top]=x[i];
      }
      else if(x[i]==')')
      {
        while(stack[top]!='(')
        printf("%c",stack[top--]);

        top--;
      }
  }
}

while(isempty()==0)
{
  printf("%c",stack[top--]);
}
printf("\n\n");

}
