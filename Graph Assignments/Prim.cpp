#include<iostream>
#include<limits>
using namespace std;
int minKey(int* minWeight, bool* mstSet, int V)
{
  int min=INT_MAX, pos;
  for(int i=0;i<V;i++)
  {
    if(mstSet[i]==false && minWeight[i]<min)
    {
      min=minWeight[i];
      pos=i;
    }
  }
  return pos;
}
void printOutput(int* Parent, int** Graph, int V)
{
  cout<<"\n\nThe edges in the MST using Prim's Algorithm are:\n";
  for(int i=1;i<V;i++)
    cout<<Parent[i]<<" -> "<<i<<"  Weight:"<<Graph[Parent[i]][i]<<endl;
}
void Prim(int** Graph,int V)
{
  int* Parent = new int[V];
  int* minWeight = new int[V];
  bool* mstSet = new bool[V];
  for(int i=0;i<V;i++)
  {
    minWeight[i]=INT_MAX;
    mstSet[i]=false;
  }
  minWeight[0]=0;
  Parent[0]=-1;
  int i;
  for(int k=0;k<V-1;k++)
  {
    i=minKey(minWeight,mstSet,V);
    mstSet[i]=true;
    for(int j=0;j<V;j++)
    {
      if(Graph[i][j] && mstSet[j]==false && Graph[i][j]<minWeight[j])
      {
        Parent[j]=i;
        minWeight[j]=Graph[i][j];
      }
    }
  }
  printOutput(Parent,Graph,V);
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
      Graph[i][j]=0;
  }
  cout<<"\nEnter the number of edges\n";
  cin>>E;
  cout<<"\nNow enter the two vertices of each edges with their weights\n";
  for(int i=0;i<E;i++)
  {
    cin>>v1>>v2>>weight;
    Graph[v1][v2]=weight;
    Graph[v2][v1]=weight;
  }
  Prim(Graph,V);
  return 0;
}
