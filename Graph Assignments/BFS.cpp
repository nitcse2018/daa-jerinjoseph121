#include<iostream>
#include<list>
using namespace std;
class Graph
{
  int v;
  list<int> *adj;
public:
  Graph(int x)
  {
    v = x;
    adj = new list<int>[v];
  }
  void addEdge(int v, int AdjV)
  {
    adj[v].push_back(AdjV);
  }
  void BFS(int start)
  {
    bool *visited = new bool[v];
    for(int i=0;i<v;i++)
      visited[i] = false;
    list<int> queue;
    visited[start] = true;
    queue.push_back(start);
    list<int> :: iterator val;
    cout<<"\nBFS Traversal:\n";
    while(!queue.empty())
    {
      start = queue.front();
      cout<<start+1<<" ";
      queue.pop_front();
      for(val=adj[start].begin() ; val!=adj[start].end() ; val++)
      {
        if(!visited[*val])
        {
          visited[*val] = true;
          queue.push_back(*val);
        }
        else;
      }
    }
  }
};
int main()
{
  int vertices,v1,v2,edges,start;
  cout<<"Enter the number of vertices\n";
  cin>>vertices;
  Graph G(vertices);
  cout<<"\nNow enter the number of edges\n";
  cin>>edges;
  cout<<"\nEnter the two vertices of the edges\n";
  for(int i=0;i<edges;i++)
  {
    cin>>v1>>v2;
    G.addEdge(v1-1,v2-1);
    G.addEdge(v2-1,v1-1);
  }
  cout<<"\nEnter the vertice to start the traversal from\n";
  cin>>start;
  G.BFS(start-1);
  cout<<endl;
  return 0;
}
