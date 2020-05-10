#include<iostream>
#include<limits>
#define INF 99999999
using namespace std;
void printOutput(int** Graph, int V)
{
  cout<<"\nShortest Distance for all pairs are:\n\n";
  for(int i=0;i<V;i++)
  {
    for(int j=0;j<V;j++)
    {
      cout<<i<<" -> "<<j;
      if(Graph[i][j]>=INF)
        cout<<" Minimum Distance: No path found"<<endl;
      else
        cout<<" Minimum Distance: "<<Graph[i][j]<<endl;
    }
  }
}
void floydWarshall(int** Graph, int V)
{
  for(int k=0;k<V;k++)
  {
    for(int i=0;i<V;i++)
    {
      for(int j=0;j<V;j++)
      {
        if(Graph[i][j]>(Graph[i][k]+Graph[k][j]))
          Graph[i][j]=Graph[i][k]+Graph[k][j];
        else;
      }
    }
  }
  printOutput(Graph,V);
}
int main()
{
  int V,E,v1,v2,weight;
  cout<<"\nEnter the number of vertices\n";
  cin>>V;
  int** Graph = new int*[V];
  for(int i=0;i<V;i++)
  {
    Graph[i] = new int[V];
    for(int j=0;j<V;j++)
    {
      if(i==j)
        Graph[i][j]=0;
      else
        Graph[i][j]=INF;
    }
  }
  cout<<"\nEnter the number of edges\n";
  cin>>E;
  cout<<"\nNow enter the two vertices of each edges with their weights\n";
  for(int i=0;i<E;i++)
  {
    cin>>v1>>v2>>weight;
    Graph[v1][v2]=weight;
  }
  floydWarshall(Graph,V);
  return 0;
}
