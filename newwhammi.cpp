#include <bits/stdc++.h>
#include<conio.h>
using namespace std;
int p[3][4]={{1,3,5,7},{2,3,6,7},{4,5,6,7}};
int code[7]={0};

int* error(int code[]){
srand(time(0)); 
int r = rand()%7; 
if((rand()%10)<7){
if(code[r]==0)
 code[r]=1;
 else
 code[r]=0;}

return code;}

int* encode(int data){
  code[2]=data%10;
  code[4]=(data/10)%10;
  code[5]=(data/100)%10;
  code[6]=(data/1000)%10;
 // for(int i=6;i>=0;i--)
 // cout<<code[i]<<"   ";
 // cout<<endl;
  
  for(int i=0;i<3;i++){
    for(int k=0;k<4;k++){
      code[(int)pow(2,i)-1]^=code[p[i][k]-1];
    }
  }
  return code;
}


int main() {
  //encoding
  int data,tokarr[10];
  cout<<"Enter 4 digit Data   ";
  cin>>data;
  int u=0;
 while(data>0)
{ tokarr[u]=data%10000;
  data=data/10000;
  u++;
}
  int* tokcod[10];
  for(int i=0;i<u;i++)
  tokcod[i]=encode(tokarr[i]);

 for(int k=0;k<u;k++)
  {cout<<"code formed at sender end is : "<<endl;
  for(int i=6;i>=0;i--)
  cout<<tokcod[u][i]<<"   ";
  cout<<endl;}

  int* errarr[10];
  for(int k=0;k<u;k++)
  {errarr[k]=error(tokcod[k]);
  cout<<"code recieved by reciever is: "<<endl;
  for(int i=6;i>=0;i--)
  cout<<errarr[k][i]<<"   ";
  cout<<endl;}
  //decode
   int errbit=0;
   for(int i=0;i<3;i++){
    for(int k=1;k<4;k++)
      errarr[(int)pow(2,i)-1]^=errarr[p[i][k]-1];
    if(errarr[(int)pow(2,i)-1]==1)
      errbit+=pow(2,i);
  }
  if(errbit>0 && errbit<8)
  {cout<<"error occurred at "<<errbit<<" position"<<endl;
   code[errbit-1]^=1;
   cout<<"Extracted & Corrected data word is  "<<code[6]<<" "<<code[5]<<" "<<code[4]<<" "<<code[2];
  }
  else 
  cout<<"no error in bit";
  
  
  
  getch();
}
