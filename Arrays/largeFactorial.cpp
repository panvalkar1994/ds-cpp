#include<bits/stdc++.h>
using namespace std;

vector<int> product(vector<int> &s, int n)
{
    int mod = 0, carry = 0, val=0;
    int i = 0;
    vector<int> out;
    while (i<s.size())
    {
        val = s[i] * n + carry;
        mod = val % 10;
        carry = val / 10;
        out.push_back(mod);
        i++;
    }

    while (carry)
    {
        out.push_back(carry);
        carry /= 10;
    }
    cout << out[0];
    return out;
}

vector<int> largeFactorial(int n)
{
    vector<int> s;
    s[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        s = product(s, i);
    }
    return s;
}

string vecToStr(vector<int> v)
{
    string s = "";
    for (int i = v.size() - 1; i >= 0; i--)
    {
        // s = s + (char)v[i];
    }
    return s;
}

int main()
{
    int n;
    cout << "Enter number: ";
    cin >> n;
    vector<int> vec = largeFactorial(n);
    string largeFact = vecToStr(vec);
    cout << "factorial of " << n << " is " << largeFact << endl;   
    return 0;

}