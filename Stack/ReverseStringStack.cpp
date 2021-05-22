#include<iostream>
#include<string>
#include<stack>
using namespace std;

void reverseStr(string& str,int n)
{
    stack<char> s;
    for (int i = 0; i < n; i++)
    {
        s.push(str[i]);
    }
    for (int i = 0; i < n; i++)
    {
        str[i]=s.top();
        s.pop();
    }
}

int main()
{
    string str;
    cout<<"Enter string: ";
    cin>>str;
    reverseStr(str,str.size());
    cout<<"Output: "<<str<<endl;
    return 0;
}
