#include<bits/stdc++.h>
using namespace std;

vector<int>maxset(vector<int> &A)
{
    vector<int> tmpArr, maxArr;
    long long int val=0, maxVal = A[0];
    for (int i = 0; i < A.size(); i++)
    {
        if(A[i]<0)
        {
            if(val>maxVal || (val==maxVal && tmpArr.size()>maxArr.size()))
            {
                maxArr = tmpArr;
                maxVal = val;
            }
            tmpArr.clear();
            val = 0;
           
        }
        else
        {
            tmpArr.push_back(A[i]);
            val += A[i];
            
        }
    }
    if(val>maxVal || (val==maxVal && tmpArr.size()>maxArr.size()))
    {
        maxArr = tmpArr;
        maxVal = val;
    }
    return maxArr;
}

int main()
{
    return 0;
}