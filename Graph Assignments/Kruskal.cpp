#include<iostream>
#include<algorithm>
using namespace std;
struct Edge
{
  int v1;
  int v2;
  int weight;
};
struct Set
{
  int parent;
  int rank;
};
int Comp(const void* a,const void* b)
{
  struct Edge* a1=(struct Edge*)a;
  struct Edge* b1=(struct Edge*)b;
  return a1->weight > b1->weight;
}
class Graph
{
  int V;
  int E;
public:
  struct Edge* edge;
  Graph(int v, int e)
  {
    V=v;
    E=e;
    edge=new struct Edge[e];
  }
  int Find(struct Set sets[], int i)
  {
    if(sets[i].parent != i)
      sets[i].parent=Find(sets ,sets[i].parent);
    return sets[i].parent;
  }
  void Union(struct Set sets[],int x, int y)
  {
    int xroot=Find(sets,x);
    int yroot=Find(sets,y);
    if(sets[xroot].rank < sets[yroot].rank)
      sets[xroot].parent = yroot;
    else if(sets[xroot].rank > sets[yroot].rank)
      sets[yroot].parent = xroot;
    else
    {
      sets[yroot].parent=xroot;
      sets[xroot].rank++;
    }
  }
  void Kruskal()
  {
    struct Edge* Result= new struct Edge[V];
    int e=0;
    int se=0;
    qsort(edge, E, sizeof(edge[0]), Comp);
    struct Set *sets = new struct Set[(V*sizeof(struct Set))];
    for(int i=0;i<V;i++)
    {
      sets[i].parent=i;
      sets[i].rank=0;
    }
    while(e<V-1 && se<E)
    {
      struct Edge next_edge= edge[se++];
      int x = Find(sets,next_edge.v1);
      int y = Find(sets,next_edge.v2);
      if(x!=y)
      {
        Result[e++]=next_edge;
        Union(sets,x,y);
      }
      else;
    }
    cout<<"\n\nThe edges in the MST using Kruskal's Algorithm are:\n";
    for(int i=0;i<e;i++)
      cout<<Result[i].v1<<" -> "<<Result[i].v2<<"  Weight:"<<Result[i].weight<<endl;
  }
};
int main()
{
  int V,E;
  cout<<"\nEnter the number of vertices\n";
  cin>>V;
  cout<<"\nEnter the number of edges\n";
  cin>>E;
  Graph G(V,E);
  cout<<"\nNow enter the two vertices of each edges with their weights\n";
  for(int i=0;i<E;i++)
  {
    cin>>G.edge[i].v1>>G.edge[i].v2>>G.edge[i].weight;
  }
  G.Kruskal();
  return 0;
}
