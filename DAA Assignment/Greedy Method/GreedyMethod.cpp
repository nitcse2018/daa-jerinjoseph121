//To make a real program with greedy algo
//Program based on Fractional Knapsack using Greedy Algorithm
#include<iostream>
#include<algorithm>
using namespace std;
float* Knapsack(float W,float* w,float* v,int n)
{
  float* A= new float[n+1]; //array which stores all the weights of items added in the knapsack and last element tells the total value of knapsack
  for(int i=0;i<n+1;i++)
    A[i]=0;
  int item;
  float max,num;
  for(int i=0;i<n;i++) //checks all the items until the weight of the knapsack is full
  {
    if(W==0) //it means that the knapsack is fulls
     return A;
    else
    {
      max=0;
      item=0;
      num=0;
      for(int j=0;j<n;j++) //used to find the maximum value/weight ratio of an item and places that item in the knapsack
      {
        if(w[j]>0 && (v[j]/w[j])>max)
        {
          max = v[j]/w[j];
          item = j;
        }
        else;
      }
      if(w[item]<W)
        num = w[item];
      else
        num = W;
      A[n] = A[n] + (num/w[item])*v[item]; //Records the value of the knapsack after adding an item (here A[n] is the total value element)
      w[item] = w[item] - num; //decreases the weigths of items which are added to the knapsack to show the weight remaining which could be added
      A[item] = A[item] + num; //records the weight of an item added to the knapsack
      W = W - num; //decrements the weight until it becomes 0 which means its full
    }
  }
  return A;
}
int main()
{
  float W;
  cout<<"\nEnter total weight of knapsack\n";
  cin>>W;
  int n;
  cout<<"\nEnter the number of items\n";
  cin>>n;
  float* w = new float[n];
  float* v = new float[n];
  cout<<"\nNow enter weights and values of all the items\n";
  for(int i=0;i<n;i++)
    cin>>w[i]>>v[i];
  float* result= new float[n+1];
  result = Knapsack(W,w,v,n);
  cout<<"\n\nThe maximum value of the knapsack is: "<<result[n];
  cout<<"\n\nList of all items with their weights added in the knapsack: \n";
  for(int i=0;i<n;i++)
    cout<<"Item no: "<<(i+1)<<"   Weight Added: "<<result[i]<<endl;
  return 0;
}
