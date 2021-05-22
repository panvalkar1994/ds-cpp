// Implement Evaluation of postfix expression using stack
//postfix  a*b+c is (a b* c +)
#include<iostream>
#include<stack>
#include<string>
using namespace std;

int EvaluationPostFix(string& expression,char delemeter);
int operation(char c, int n1, int n2);

int main()
{
    string s="3 5 * 6 +";
    cout<<EvaluationPostFix(s,' ')<<endl;
    string s2="3,5,*,6,+";
    cout<<EvaluationPostFix(s2,',')<<endl;
    return 0;
}

int EvaluationPostFix(string& expression,char delemeter)
{
    int res;
    stack<int> st;
    int op2, op1;
    for(int i=0; i<expression.size();i++)
    {
        if(expression[i]==delemeter)
        {
            continue;
        }
        else if(isdigit(expression[i]))
        {
            st.push(expression[i]-'0');
        }
        else
        {
            op2=st.top();
            st.pop();
            op1=st.top();
            st.pop();
            int x=operation(expression[i],op1,op2);
            st.push(x);
        }
        
    }
    res=st.top();
    return res;
}

int operation(char c,int n1, int n2)
{
    if(c=='*') return n1*n2;
    if(c=='+') return n1+n2;
    if(c=='-') return n1-n2;
    if(c=='/') return n1/n2;
    return 0;
}