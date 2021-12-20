#include<iostream>
#include<bits/stdc++.h>

using namespace std;

char m[50],g[50],r[50],q[50],temp[50];
void shiftleft();
void calrem()
{
    int i,j;

    for(i=1;i<=16;i++)
        r[i-1] =((int)temp[i]-48)^((int)g[i]-48)+48;
}

void crc(int n)
{

    int i,j;

    for(i = 0;i<n;i++)
    {
        temp[i]=m[i];
    }

    for(i=0;i<16;i++)
        r[i]=m[i];

    cout<<"Intermediate remainder :";
    for(i=0;i<n-16;i++)
    {
        if(r[0]=='1')
        {
            q[i]='1';
            calrem();
        }
        else
        {
            q[i]='0';
            shiftleft();
        }

        r[16]=m[17+i];
        r[17]='\0';

        cout<<"REMAINDER "<<i<<" :"<<r<<endl;

        for(j=0;j<=17;j++)
            temp[j]=r[j];
    }
    q[n-16]='\0';
}

void shiftleft()
{

    int i;
    for(i=1;i<=16;i++)
        r[i-1]=r[i];
}

void caltrans(int n)
{
    int i,k=0;
    for(i=n-16;i<n;i++)
        m[i]=((int)m[i]-48)^((int)r[k++]-48)+48;
    m[i]='\0';
}

int main()
{
  int n,i=0;
  char ch;
  int flag=0;

  cout<<"Enter the frame bits: ";
  while((ch=getc(stdin))!='\n')
    m[i++]=ch;
  n=i;
  for(i=0;i<16;i++)
    m[n++]='0';
  m[n]='\0';

  //divisor
  for(i=0;i<16;i++)
    g[i]='0';
  g[0]=g[4]=g[11]=g[16]='1';
  g[17]='\0';

  cout<<"Generator :"<<g<<endl;
  crc(n);

  cout<<"Quotient :"<<q<<endl;
  caltrans(n);
  cout<<"Transmitted frame :"<<m;
  char d;
  cout<<endl<<"Do you want to change transmitted frame?(y,n";
  cin>>d;
if(d=='y')
{
    cout<<"Enter transmitted frame: ";
    cin>>m;
}
  cout<<"CRC Checking"<<endl;
  crc(n);

  for(i=0;i<16;i++)
  {
      if(r[i]!='0')
      flag =1;

  }

      if(flag==1)
        cout<<"Error during transmission";
      else
      cout<<"correct";

}
