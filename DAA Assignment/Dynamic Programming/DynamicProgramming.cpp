//Stacking of boxes problem using Dynamic Programming
//Boxes can be repeated while stacking and the length and breath of the box on top should strictly be less than the one on the bottom
#include<iostream>
#include<algorithm>
using namespace std;
struct box//structure of each box with three dimension
{
  int l;
  int b;
  int h;
};
bool condition(box a,box b)//this condtion is used for sorting all the rotations of boxes based on the decreasing area of the base of the boxes
{
  if((a.l*a.b)>(b.l*b.b))
    return true;
  else
    return false;
}
int maxStack(box* a,int n)
{
  box* boxes=new box[3*n];//stores 3 rotations for all n boxes(rotations meaning that the dimensions are interchanged)
  int k=0;
  for(int i=0;i<n;i++)//this for loop is used to add all the three rotations of a box in the memory which will be used later to analyse the stacks
  {
    boxes[k].h=a[i].h;//note that in all these cases the rotations are entered in such a way that the length is always greater than the breadth while the height is different for all three rotations
    if(a[i].l>=a[i].b)
    {
      boxes[k].l=a[i].l;
      boxes[k].b=a[i].b;
    }
    else
    {
      boxes[k].l=a[i].b;
      boxes[k].b=a[i].l;
    }
    k++;
    boxes[k].h=a[i].l;
    if(a[i].h>=a[i].b)
    {
      boxes[k].l=a[i].h;
      boxes[k].b=a[i].b;
    }
    else
    {
      boxes[k].l=a[i].b;
      boxes[k].b=a[i].h;
    }
    k++;
    boxes[k].h=a[i].b;
    if(a[i].h>=a[i].l)
    {
      boxes[k].l=a[i].h;
      boxes[k].b=a[i].l;
    }
    else
    {
      boxes[k].l=a[i].l;
      boxes[k].b=a[i].h;
    }
    k++;
  }
  sort(boxes,boxes+(3*n),condition);
  int* maxHeight=new int[3*n];//stores the maximum height of all the rotations while they are being stacked
  for(int i=0;i<3*n;i++)
  {
    maxHeight[i]=boxes[i].h;//initial value of the max height will be the original height of each rotation
  }
  for(int i=1;i<3*n;i++)//this nested loop checks all the rotations and analyse which is the best case for stacking to get the max height
  {
    for(int j=0;j<i;j++)
    {
      if(boxes[i].l<boxes[j].l && boxes[i].b<boxes[j].b && maxHeight[i]<maxHeight[j]+boxes[i].h)//the conditions for stacking of box i on box j are listed here
        maxHeight[i]=maxHeight[j]+boxes[i].h;
      else;
    }
  }
  int max=-1;
  for(int i=0;i<3*n;i++)
  {
    if(maxHeight[i]>max)//checks the maximum height of all the maxheight of each boxes after they are stacked
      max=maxHeight[i];
  }
  return max;//max height of the best stacking method is returned
}
int main()
{
  int n,result;
  cout<<"Enter the number of boxes\n";
  cin>>n;
  box* a=new box[n];
  cout<<"\nNow enter the length, breadth and height of all the boxes\n\n";
  for(int i=0;i<n;i++)
    cin>>a[i].l>>a[i].b>>a[i].h;
  result=maxStack(a,n);
  cout<<"\n\nThe maximum height of the stack of boxes is "<<result;
  cout<<endl;
  return 0;
}
