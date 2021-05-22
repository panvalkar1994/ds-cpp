// implementing adjacency list format of graph

#include<bits\stdc++.h>
using namespace std;


int main()
{
    int v;
    cout<<"Enter Number of vertices"<<endl;
    cin>>v;
    vector<char> vertices(v,'0');
    cout<<"Enter list of vertices"<<endl;
    for (int i = 0; i < v; i++)
    {
        cin>>vertices[i];
    }

    vector<pair<int,int>> adjList;
    int e;
    pair<int, int> edge;
    cout<<"Enter number of Edges"<<endl;
    cin>>e;
    cout<<"Enter edges"<<endl;
    for (int i = 0; i < e; i++)
    {
        char f,s;
        cin>>f>>s;
        edge.first=( f -'a');
        edge.second=(s -'a');
        adjList.push_back(edge);
    }
    for (int i = 0; i < e; i++)
    {
        cout<<adjList[i].first<<"-->"<<adjList[i].second<<endl;
    }
    
    return 0;
}