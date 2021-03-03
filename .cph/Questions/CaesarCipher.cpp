 
#include<iostream>
using namespace std;
 
string encrypt(char text[]){
    string etext="";
    for (int i = 0; i < n; i++)
    {
        if(text[i]==' '){
            etext.append(" "));
        }
        else{
            text[i]=(text[i]+3)%26;
        }
    }
    
}

int main()
{
    int n;
    char text[n];
    for (int i = 0; i < n; i++)
    {
        cin>>text[i];
    }
    int choice;
    cin>>choice;
    if(choice==1){
        cout<<encrypt(text);
    }
    else{
        cout<<decrypt(text);
    }
    return 0;
}