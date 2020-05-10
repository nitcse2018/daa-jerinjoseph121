#include<iostream>
#include<limits>
using namespace std;
int minKey(int* minDist, bool* mstSet, int V)
{
  int min=INT_MAX, pos;
  for(int i=0;i<V;i++)
  {
    if(mstSet[i]==false && minDist[i]<min)
    {
      min=minDist[i];
      pos=i;
    }
  }
  return pos;
}
void printOutput(int* Parent, int* minDist, int** Graph, int V, int start)
{
  int j;
  cout<<"\n\nShortest Path from vertex "<<start<<" using Dijkstra's Algorithm is:";
  for(int i=0;i<V;i++)
  {
    if(i!=start)
    {
      j=i;
      cout<<"\n\nPath to "<<j<<":\n";
      cout<<j;
      while(Parent[j]!=-1)
      {
        cout<<" <- "<<Parent[j];
        j=Parent[j];
      }
      cout<<"\nTotal Distance: "<<minDist[i]<<endl;
    }
    else;
  }
}
void Dijkstra(int** Graph,int V,int start)
{
  int* Parent = new int[V];
  int* minDist = new int[V];
  bool* mstSet = new bool[V];
  for(int i=0;i<V;i++)
  {
    minDist[i]=INT_MAX;
    mstSet[i]=false;
  }
  minDist[start]=0;
  Parent[start]=-1;
  int i;
  for(int k=0;k<V-1;k++)
  {
    i=minKey(minDist,mstSet,V);
    mstSet[i]=true;
    for(int j=0;j<V;j++)
    {
      if(Graph[i][j] && mstSet[j]==false && minDist[j]>(minDist[i]+Graph[i][j]))
      {
        Parent[j]=i;
        minDist[j]=minDist[i]+Graph[i][j];
      }
    }
  }
  printOutput(Parent,minDist,Graph,V,start);
}
int main()
{
  int V,E,v1,v2,weight,start;
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
  cout<<"\nEnter the start vertex\n";
  cin>>start;
  Dijkstra(Graph,V,start);
  return 0;
}
