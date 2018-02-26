#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int getpriority(char c);
int isempty();
int isoperator(char c);
int evaluate_stack(char *c);

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
  char k[200];
  int point=0;
  for(int i=0;x[i]!='\0';i++)
  {
    if( isoperator(x[i])==0){
    printf("%c",x[i]);
    k[point++]=x[i];
  }
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
        while(isempty()==0 && getpriority(stack[top])>=getpriority(x[i])){
        printf("%c",stack[top--]);
        k[point++]=stack[top+1];
      }

        stack[++top]=x[i];
      }
      else if(x[i]==')')
      {
        while(stack[top]!='('){
        printf("%c",stack[top--]);
        k[point++]=stack[top+1];
      }

        top--;
      }
  }
}

while(isempty()==0)
{
  printf("%c",stack[top--]);
  k[point++]=stack[top+1];
}
printf("\n\n");

printf("The value of the expression is: %d\n",evaluate_stack(k));

}

int evaluate_stack(char *c)
{
  int st[200];
  int to=-1;
  for(int i=0;c[i]!='\0';i++)
  {
    if(isoperator(c[i])==0)
    st[++to]=c[i];
    else{
      int y=st[to--]-48;
      int x=st[to--]-48;
      if(c[i]=='+')
      st[++to]=x+y;
      else if(c[i]=='-')
      st[++to]=x-y;
      else if(c[i]=='*')
      st[++to]=x*y;
      else
      st[++to]=x/y;

    }
  }
  return st[to];
}
