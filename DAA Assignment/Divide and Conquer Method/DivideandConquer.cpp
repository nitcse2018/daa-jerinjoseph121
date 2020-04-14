//product multiplication using divide and conquer
//in this method instead of divind the whole polynomials together, we divide into parts
//there is only three polynomial multiplications of small degree taking place
//A=a1x + a0
//B=b1x + b0
//AB=a1b1x^2 + ((a1+a0)(b1+b0) - a1b1 - a0b0)x + a0b0
#include<iostream>
using namespace std;
int* PolyMul(int* a,int* b,int n1)
{
  int n = 2*n1;
  int k;
  int dn=n1/2;
  int* d0=new int[dn+1];
  int* d1=new int[dn+1];
  k=0;
  for(int i=0;i<(dn+1);i++)//storing first half of poly 1 in d0
    d0[i]=a[k++];
  for(int i=0;i<(dn+1);i++)
    d1[i]=0;
  for(int i=0;k<n1+1;k++)//storing second half of poly 1 in d1
    d1[i++]=a[k];
  int en=n1/2;
  int* e0=new int[en+1];
  int* e1=new int[en+1];
  k=0;
  for(int i=0;i<(en+1);i++)//storing first half of poly 2 in e0
    e0[i]=b[k++];
  for(int i=0;i<(en+1);i++)
    e1[i]=0;
  for(int i=0;k<n1+1;k++)//storing second half of poly 2 in e1
    e1[i++]=b[k];
  int* d1e1=new int[dn+en+1];
  for(int i=0;i<(dn+en+1);i++)
    d1e1[i]=0;
  for(int i=0;i<(dn+1);i++)//getting d1*e1 which is stored in d1e1
    for(int j=0;j<(en+1);j++)
      d1e1[i+j]+=d1[i]*e1[j];
  int* d0e0=new int[dn+en+1];
  for(int i=0;i<(dn+en+1);i++)
    d0e0[i]=0;
  for(int i=0;i<(dn+1);i++)//getting d0*e0 which is stored in d0e0
    for(int j=0;j<(en+1);j++)
      d0e0[i+j]+=d0[i]*e0[j];
  int* d1d0e1e0=new int[dn+en+1];
  for(int i=0;i<(dn+en+1);i++)
    d1d0e1e0[i]=0;
  for(int i=0;i<(dn+1);i++)//getting (d0+d1)*(e0+e1) which is stored in d1d0e1e0
    for(int j=0;j<(en+1);j++)
      d1d0e1e0[i+j]+=(d1[i]+d0[i])*(e1[j]+e0[j]);
  int* c=new int[n+1];
  int power;
  if((n1+1)%2==0)
    power=n1+1;
  else
    power=n1+2;
  for(int i=0;i<(n+1);i++)
    c[i]=0;
  for(int i=0;i<(dn+en+1);i++)//adds d1e1*x^n in the final polynomial
    c[i+power]+=d1e1[i];
  for(int i=0;i<(dn+en+1);i++)//adds d1d0e1e0*x^(n/2) in the final polynomial
    c[i+(power/2)]+=(d1d0e1e0[i]-d1e1[i]-d0e0[i]);
  for(int i=0;i<(dn+en+1);i++)//adds d0e0 in the final polynomial
    c[i]+=d0e0[i];
  return c;//adding all these three terms gives us the final polnomial array which is returned back to the main function
}
int main()
{
  int n1;
  cout<<"\nEnter the degree of the two polynomials\n";
  cin>>n1;
  int* a=new int[n1+1];
  cout<<"\nEnter the coefficients of the first polynomial from power 0 to n\n";
  for(int i=0;i<n1+1;i++)//entering first polynomial
    cin>>a[i];
  int* b=new int[n1+1];
  cout<<"\nEnter the coefficients of the second polynomial from power 0 to n\n";
  for(int i=0;i<n1+1;i++)//entering second polynomial
    cin>>b[i];
  cout<<"\nPolynomial 1:\n\n";
  cout<<a[0];
  for(int i=1;i<n1+1;i++)
    cout<<" + "<<a[i]<<"x^"<<i;
  cout<<"\n\nPolynomial 2:\n\n";
  cout<<b[0];
  for(int i=1;i<n1+1;i++)
    cout<<" + "<<b[i]<<"x^"<<i;
  int *result= new int[n1+n1+1];
  if(n1!=0)
    result=PolyMul(a,b,n1);//the function does the multiplcation and stores in an array called result
  else
    result[0]=a[0]*b[0];
  cout<<"\n\n\nProduct of Polynomial 1 and Polynomial 2:\n\n";
  cout<<result[0];
  for(int i=1;i<(n1+n1+1);i++)//printing the product of the polynomials
    cout<<" + "<<result[i]<<"x^"<<i;
  cout<<endl;
  return 0;
}
