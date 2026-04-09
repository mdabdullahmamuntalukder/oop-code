#include<stdio.h>
#include<stdlib.h>
struct stack
{
  int size;
  int top;
  int *s;
}st;
void push(int n)
{
   if(st.top==st.size-1)
   {
    printf("Stack Overflow\n");
   }
   else
   {
    st.top++;
    st.s[st.top]=n;
   }
}
int pop()
{
  int x=-1;
  if(st.top==-1)
  {
    printf("Stack underflow\n");
  }
  else
  {
    x=st.s[st.top];
    st.top--;
  }
  return x;
}
int stacktop()
{
  if(st.top==-1)
  {
    return -1;
  }
  else
  {
    return st.s[st.top];
  }
}
int peek(int pos)
{
  int x=-1;
  if(st.top-pos+1<0)
  {
    return -1;
  }
  else
  {
    x= st.s[st.top-pos+1];
  }
  return x;
}
int isempty()
{
  if(st.top==-1)
  {
    return 1;
  }
  else
  {
    return 0;
  }
}
int isfull()
{
  if(st.top==st.size-1)
  {
    return 1;
  }
  else
  {
    return 0;
  }
}
void traverse()
{
  for(int i=st.top;i>=0;i--)
  {
     printf("%d",st.s[i]);
  }
}
int main()
{
  st.size=10;
  st.top=-1;
  st.s=(int*)malloc(st.size*sizeof(int));
  push(10);
  push(20);
  push(30);
  traverse();
  pop();
  traverse();
  printf("%d",peek(2));
  

}
