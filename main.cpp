#include <iostream>
#include <string>
#include <sstream>
using namespace std;

string encri="",decri="",code="",word,finalsen="",extencode="";
int lenword,lencode,lenreply;
bool check=false;
char sub,add;
void reply()
{
  cout << "\033[2J\033[1;1H";
  encri="";
  int rword,rcode,renc;
  string reply;
  cout<<"Enter Reply Message: "<<endl;
    cin>>reply;
    lenreply=reply.size();
    lencode=code.size();
     extencode=code;
     for (int i = 0; i < lenreply; i++)
     extencode+=code; 
    cout<<"Extencode "<<extencode<<endl;
    cout<<"code "<<code<<endl;
    for(int i=0; i<lenreply;i++)
       {
        rword = (int)reply[i];
        rcode= (int)extencode[i];
        renc=rword-rcode;
        sub=(char)renc;
        encri+=sub;
      }
}
void senderMes()
{
    encri="";
    int iword,icode,ienc;
    cout<<"----------------------+"<<endl;
    cout<<"Enter an Encryption Key: "<<endl;
    cin>>code;
    cout<<"Enter Your Message: "<<endl;
    cin>>word;
    lenword=word.size();
    lencode=code.size();
     extencode=code;
     for (int i = 0; i < lenword; i++)
     extencode+=code; 
   // cout<<"Extencode "<<extencode<<endl;
   // cout<<"code "<<code<<endl;
    cout<<encri;
    for(int i=0; i<lenword;i++)
       {
        iword = (int)word[i];
        icode= (int)extencode[i];
        ienc=iword-icode;
        sub=(char)ienc;
        encri+=sub;
      }
}

void receiver()
{
  cout << "\033[2J\033[1;1H";
  decri="";
  int jcode,jword,jdec;
  int attempts=0;
  string checkkey;
  cout<<"-----receiver------+"<<endl;
  cout<<"YOU HAVE A MESSAGE!"<<endl;
  cout<<"Encrypted Message: \n"<<encri<<endl;
  cout<<"-------------------+"<<endl;

  do
 {
  cout<<"Enter the KEY to Decrypt the code!"<<endl;
  cout<<"("<<3-attempts<<" chances remaining!)" <<endl;
  cin>>checkkey;
 
    if(checkkey==code)
    {
      for(int j=0;j<lenword;j++)
       {
        jdec= (int)encri[j];
        jcode= (int)extencode[j];
        jword= jdec+jcode;
        add = (char)jword;
        decri.push_back(add);
       }
       attempts=3;
       check=true;
    }
    else
    attempts++;
 }  
 while(attempts<3);
 if(check==true)
 {
      cout<<"-------------------+"<<endl;
      cout<<"Decrypted Message: \n>>"<<decri<<endl;
      cout<<"-------------------+"<<endl;
 }
  else
  {
      cout<<"-------------------+"<<endl;
      cout<<"Haha Caught you!"<<endl;
      cout<<"-------------------+"<<endl;
  }
}
void receiver2()
{
  cout << "\033[2J\033[1;1H";
  decri="";
  int jcode,jword,jdec;
  int attempts=0;
  string checkkey;
  cout<<"-----receiver------+"<<endl;
  cout<<"YOU HAVE A MESSAGE!"<<endl;
  cout<<"Encrypted Message: \n"<<encri<<endl;
  cout<<"-------------------+"<<endl;

  do
 {
  cout<<"Enter the KEY to Decrypt the code!"<<endl;
  cout<<3-attempts<<"( chances remaining!)"<<endl;
  cin>>checkkey;
 
    if(checkkey==code)
    {
      for(int j=0;j<lenreply;j++)
       {
        jdec= (int)encri[j];
        jcode= (int)extencode[j];
        jword= jdec+jcode;
        add = (char)jword;
        decri.push_back(add);
       }
       attempts=3;
       check=true;
    }
    else
    attempts++;
 }  
 while(attempts<3);
 if(check==true)
 {
      cout<<"-------------------+"<<endl;
      cout<<"Decrypted Message: \n>>"<<decri<<endl;
      cout<<"-------------------+"<<endl;
 }
  else
  {

      cout<<"-------------------+"<<endl;
      cout<<"Haha Caught you!"<<endl;
      cout<<"-------------------+"<<endl;
  }
}


int main()
{   
    int opt;
    int yn;
    cout<<"----------------------+"<<endl;
    cout<<"THE CYBER CYPHER!"<<endl;
    senderMes();
    receiver();
    if(check==true)
    {
    do
    {
     cout<<"////////////////////////////"<<endl;
     cout<<"----------------------------+"<<endl;
    cout<<"1.Enter New KEY and continue.\n2.Reply with same key.\n3.Exit"<<endl;
     cout<<"----------------------------+"<<endl;
    cin>>opt;
    if(opt==1)
    {  
      senderMes();
      receiver();
    }
    else if(opt==2)
    {
      reply();
      receiver2();
    }
    }
    while(opt!=3);
    }
} 