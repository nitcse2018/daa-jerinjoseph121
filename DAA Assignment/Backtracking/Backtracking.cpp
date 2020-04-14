//This program is a maze puzzle Program
//Here, every path in the maze is checked and when there is a dead-end, backtracking happens to go to another path
#include<iostream>
using namespace std;
int FindPath(int** maze,int size,int x,int y,int** sol)
{
  if(x==size-1 && y==size-1 && maze[x][y]==1)//tells that it reached the end point and checks if it is 1 or not
  {
    sol[x][y]=1;//final point of solution is marked 1
    return 1;
  }
  else if(x>=0 && x<size && y>=0 && y<size && maze[x][y]==1)//tells that this element in matrix is a possible path
  {
    sol[x][y]=1;//sets the solution matrix to 1 and it could change to 0 if it is found that path is a dead end
    if(FindPath(maze,size,x+1,y,sol)==1)// checks down if path exist
      return 1;
    else if(FindPath(maze,size,x,y+1,sol)==1)//checks forward if path exist
      return 1;
    else
    {
      sol[x][y]=0;//since no path was found from this particular point, the point is marked 0 in the solution matrix
      return 0;
    }
  }
  return 0;
}
int main()
{
  int n;
  cout<<"\nEnter the size of the square maze\n";
  cin>>n;
  int** a=new int*[n];
  for(int i=0;i<n;i++)
    a[i]=new int[n];
  cout<<"\nEnter the maze path by adding 1s and 0s\n";
  cout<<"where 1 means the path is accessible\n";
  cout<<"0 means the path is inaccessible\n";
  for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
      cin>>a[i][j];
  cout<<"\nThe maze given is:\n";
  for(int i=0;i<n;i++)
  {
    cout<<endl;
    for(int j=0;j<n;j++)
      cout<<a[i][j];
  }
  int** path=new int*[n];
  for(int i=0;i<n;i++)
    path[i]=new int[n];
  for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
      path[i][j]=0;
  if(FindPath(a,n,0,0,path)==1) //tells that a path exist to go to the end point form the start point
  {
    cout<<"\n\nPath is:\n";
    for(int i=0;i<n;i++)
    {
      cout<<endl;
      for(int j=0;j<n;j++)
        cout<<path[i][j];
    }
    cout<<endl;
  }
  else
    cout<<"\n\nThere is no path in the maze\n\n";
  return 0;
}
