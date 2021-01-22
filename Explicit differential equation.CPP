#include<iostream.h>
#include<math.h>
//using namespace std;
//clrscr();
int main()
{
 double E,sig,r,T,s0,ds,sI,dt,p1;
 int I,k1;
 double p2,s[10],A[10],B[10],C[10],v[10][10];
 cout<<"strike price: "<<endl;
 cin>>E;
 cout<<"volatility: "<<endl;
 cin>>sig;
 cout<<"risk free rate: "<<endl;
 cin>>r;
 cout<<"time to maturity: "<<endl;
 cin>>T;
 cout<<"asset stepslength: "<<endl;
 cin>>ds;
 cout<<"current stock price "<<endl;
 cin>>s0;
 cout<<"time step length: "<<endl;
 cin>>dt;
 sI=140;
 I=(sI-s0)/ds;
 k1=T/dt;
 p1=dt/ds;
 p2=dt/(pow(ds,2));
 for(int i=0;i<=I;i++)   //final condition(when time =T
 {
  s[i]=s0+(i*ds);
  if(s[i]-E>0)
    v[i][0]=s[i]-E;
  else
    v[i][0]=0;
 }
 for(int k=1;k<=k1;k++)    //boundary codition (when s=60 and s=140)
 {
   if(s0-(E*exp(-r*k*dt))>0)
      v[0][k]=s0-(E*exp(-r*k*dt));
   else
      v[0][k]=0;
   if(sI-(E*exp(-r*k*dt))>0)
      v[I][k]=sI-(E*exp(-r*k*dt));
   else
      v[I][k]=0;
 }
 for(int p=0;p<=(k1-1);p++)
 {
   for(int m=1;m<=I-1;m++)
   {
       A[m]=(0.5*pow(sig,2)*pow(s[m],2)*p2)-(0.5*r*s[m]*p1);
       B[m]=1-(pow(sig,2)*pow(s[m],2)*p2)-(r*dt);
       C[m]=(0.5*pow(sig,2)*pow(s[m],2)*p2)+(0.5*r*s[m]*p1);
       v[m][p+1]=(A[m]*v[m-1][p])+(B[m]*v[m][p])+(C[m]*v[m+1][p]);
   }
 }
 cout<<"options values  "<<endl;
 for(int j=0;j<=I;j++)
 {
    for(int n=0;n<=k1;n++)
    {
      cout<<v[j][n]<<"  ";
    }
    cout<<endl;
 }
 return 0;
 }











