//use of Branch and Bound to find the optimal worker for a particular job which uses less cost
#include<iostream>
#include<queue>
using namespace std;
struct node//every worker-job pair is added in a node to check if it has minimum cost or not
{
  node* parent;
  int pathCost;
  int cost;
  int workerID;
  int jobID;
  int N;
  bool* assigned = new bool[N];
};
node* newNode(int x, int y, bool* assigned, node* parent, int N)//this is used to create a new node of struct node in the memory and assign certain values to the node
{
  node* a = new node;
  a->N=N;
  for(int j = 0; j < N; j++)
    a->assigned[j] = assigned[j];
  a->assigned[y] = true;
  a->parent = parent;
  a->workerID = x;
  a->jobID = y;
  return a;
}
int calculateCost(int **costMatrix, int x, int y, bool* assigned, int N)//this is used to calculate the cost of a node by checking through all the possibilities of the matrix
{
  int cost = 0;
  bool available[N] = {true};
  for(int i = x + 1; i < N; i++)
  {
    int min = INT_MAX, minIndex = -1;
    for (int j = 0; j < N; j++)
    {
      if (!assigned[j] && available[j] && costMatrix[i][j] < min)
      {
        minIndex = j;
        min = costMatrix[i][j];
      }
    }
    cost += min;
    available[minIndex] = false;
  }
  return cost;
}
struct comp//this structure is used in priority queue to give priority for the nodes with less cost
{
  bool operator()(const node* a, const node* b) const
  {
    return a->cost > b->cost;
  }
};
void printAssignments(node* min)//this prints the workers with their jobs for minimum cost once all the branches are made
{
  if(min->parent==NULL)
    return;
  printAssignments(min->parent);
  cout<<"Assign Worker "<<char(min->workerID + 'A')<< " to Job " << (min->jobID)+1 << endl;
}
int findMinCost(int** costMatrix, int N)
{
  priority_queue<node*,vector<node*>, comp> pq;//creates a stack where nodes are pushed and popped
  bool assigned[N] = {false};
  node* root = newNode(-1, -1, assigned, NULL, N);
  root->pathCost = 0;
  root->cost = 0;
  pq.push(root);
  while (!pq.empty())//this loop links the nodes with minimum cost and chooses the best worker-job pair nodes with minimum cost
  {
    node* min = pq.top();
    pq.pop();
    int i = min->workerID + 1;
    if (i == N)
    {
      printAssignments(min);
      return min->cost;//the minimum cost is calculated and returned to the main function
    }
    for (int j = 0; j < N; j++)
    {
      if (!min->assigned[j])
      {
        node* child = newNode(i, j, min->assigned, min, N);
        child->pathCost = min->pathCost + costMatrix[i][j];//the path cost indicates the total cost of all the pairs the node is linked with
        child->cost = child->pathCost + calculateCost(costMatrix, i, j, child->assigned, N);
        pq.push(child);
      }
    }
  }
}
int main()
{
  int N;
  cout<<"\nEnter the number of workers/jobs\n";
  cin>>N;
  int** cost=new int*[N];//cost matrix is the worker-job matrix which tells the cost of every worker in every job and is the input of the program
  for(int i=0;i<N;i++)
    cost[i]=new int[N];
  cout<<"\n\nNow enter the costs of every worker in every job\n";
  for(int i=0;i<N;i++)
    for(int j=0;j<N;j++)
      cin>>cost[i][j];
  cout<<"\nThe Worker-Job table created is: \n\n";
  for(int i=0;i<N;i++)
  {
    for(int j=0;j<N;j++)
      cout<<cost[i][j]<<" ";
    cout<<endl;
  }
  cout<<endl;
  int min;
  min=findMinCost(cost,N);
  cout<<"\nMinimum cost is: "<<min<<endl;
  return 0;
}
