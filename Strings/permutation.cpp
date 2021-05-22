#include<bits/stdc++.h>
using namespace std;


void permutation(string str, string out)
{
    if(str.length() == 0)
    {
        cout<<out<<'\n';
    }
    else
    {
        for (int i = 0; i < str.length(); i++)
        {
            string rem = str.substr(0,i) + str.substr(i+1);
            permutation(rem, out+str[i]);
        }
        
    }
    
}

int main()
{
    permutation("name","");
    return 0;
}