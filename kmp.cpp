#include<bits/stdc++.h>
using namespace std;


void prefixar(string str1,int pre[])
{
    pre[0]=0;
    int i=0;
    for(int j=1;j<str1.size();j++)
    {
        if(str1[i]==str1[j])
        {
            pre[j]=i+1;
            i++;
        }
        else
        {
            while(i!=0)
            {
                i=pre[i-1];
                if(str1[i]==str1[j])
                {
                    pre[j]=i+1;
                    i++;
                    break;
                }  
            }
            if(i==0)
            pre[j]=0;
        }
    }
}


void kmp(string str,string str1)
{
    int pref[str1.size()];
    prefixar(str1,pref);
    //Print 
    cout<<"Prefix Array"<<endl;
    for(int i=0;i<str1.size();i++)
    {
        cout<<pref[i]<<" ";
    }
    cout<<endl;

    int i=0,check=0;
    for(int j=0;j<str.size();j++)
    {
        if(str1[i]!=str[j])
        {
            while(i!=0)
            {
                i=pref[i-1];
                if(str1[i]==str[j])
                {
                    i++;
                    break;
                }
            }
        }
        else
        {
            if(i==str1.size()-1)
            {
                cout<<"Found at index:"<<j-i<<endl;
                i=pref[i-1];
                j--;
                check=1;
            }
            else
            {
                i++;
            }
        } 
    }
    if(check==0)
    cout<<"Pattern Not found"<<endl;
}

int main()
{
    string str,str1;
    cout<<"Enter string "<<endl;
    cin>>str;
    cout<<"Enter pattern "<<endl;
    cin>>str1;
    kmp(str,str1);
    return 0;
}