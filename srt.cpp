#include<iostream>
#include<iomanip>
using namespace std;
class srtf_alg
{
    int ar[10],id[10],exe[10];
    int n;
    void sort(int *f,int *mid,int *last);
public:
    void getdata();
    void display();
    void cal_wt_tt();
};
void srtf_alg::getdata()
{
    cout<<"How many process to be entered : ";
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cout<<"Enter execution time and arrival time of "<<i+1<<" process : ";
        cin>>exe[i]>>ar[i];
        id[i]=i+1;
    }
}
void srtf_alg::display()
{
    cout<<endl<<"Process ID\tExecution time\tArrival Time "<<endl;
    for(int i=0;i<n;i++)
        cout<<setw(5)<<id[i]<<setw(15)<<exe[i]<<setw(15)<<ar[i]<<endl;
}
void srtf_alg::sort(int *f,int *mid,int *last)
{
    int temp;
    for(int y=0;y<n-1;y++)
    {
        for(int z=0;z<n-1;z++)
            if(f[z]>f[z+1])
            {
                temp=f[z];
                f[z]=f[z+1];
                f[z+1]=temp;
                temp=mid[z];
                mid[z]=mid[z+1];
                mid[z+1]=temp;
                temp=last[z];
                last[z]=last[z+1];
                last[z+1]=temp;
            }
    }
}
void srtf_alg::cal_wt_tt()
{
    int exe2[10],flag=1;
 int at=0,ind,wt,tnt,min,max=exe[0];
 float avg=0,avtnt=0;
 sort(ar,id,exe);
 for(int i=0;i<n;i++)
 {
     exe2[i]=exe[i];
     if(max<exe[i])
        max=exe[i];
 }
    at=ar[0];
 min=max+1;
 cout<<"\nProcess ID \tWaiting time \tTurn Around time "<<endl;
 while(flag)
    {
        for(int i=0;i<n;i++)
        {
            if(at>=ar[i]&&min>exe[i]&&id[i]>0)
            {
                ind=i;
          min=exe[i];
      }
     }
        at++;
        exe[ind]--;
        min=max+1;
        if(exe[ind]==0)
        {
            wt=at-exe2[ind]-ar[ind];
      tnt=at-ar[ind];
      cout<<setw(5)<<id[ind]<<setw(15)<<wt<<setw(15)<<tnt<<endl;
      id[ind]=-1;
      avg+=wt;
      avtnt+=tnt;
        }
        flag=0;
        for(int k=0;k<n;k++)
            if(id[k]!=-1)
               flag=1;
    }
    avg=avg/(float)n;
    avtnt/=(float)n;
    cout<<"\nAverage Waiting time     : "<<avg;
    cout<<"\nAverage turn Around time : "<<avtnt<<endl;
}
int main()
{
 srtf_alg srtf;
 srtf.getdata();
 srtf.display();
 srtf.cal_wt_tt();
    return 0;
}


















