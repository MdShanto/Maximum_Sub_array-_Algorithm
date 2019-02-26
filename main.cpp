#include <iostream>
#include <vector>

using namespace std;

vector<int> maxcrosssubarray(int ar[],int low,int mid,int high)
{
    int left_sum=-9999;
    int  i,left_pos,sum=0;
    for(i=mid;i>=low;i--)
    {
      sum=sum+ar[i];
      if(sum>left_sum)
      {
         left_sum=sum;
         left_pos=i;
      }
    }
      sum=0;
    int right_sum=-9999,right_pos;
    for(i=mid+1;i<=high;i++)
    {
        sum=sum+ar[i];
    if(sum>right_sum)
    {
        right_sum=sum;
        right_pos=i;
    }
    }
    vector <int> mix;
    mix.push_back(left_pos);
    mix.push_back(right_pos);
    mix.push_back(left_sum+right_sum);
    return mix;
}

vector<int>maximumsubarray(int ar[],int low,int high)
{
    if(low==high)
    {
        vector<int> store;
        store.push_back(low);
        store.push_back(high);
        store.push_back(ar[low]);
        return store;
    }

  else
    {
           int mid=(low+high)/2;
           vector<int>left,right,cross;
           left=maximumsubarray(ar,low,mid);
           right=maximumsubarray(ar,mid+1,high);
           cross= maxcrosssubarray(ar,low,mid,high);
          if(left[2]>=right[2] && left[2]>=cross[2])
            return left;
           if(right[2]>=left[2] && right[2]>=cross[2])
            return right;
           if(cross[2]>=left[2] && cross[2]>=right[2])
            return cross;
  }
}
int main()
{
    int a[100],i,n;
    cout<<"enter the size:"<<endl;
    cin>>n;
    cout<<"array element are:"<<endl;
    for(i=1;i<=n;i++)
    {
      cin>>a[i];
    }
    vector<int>temp = maximumsubarray(a,1,n);
    cout <<"Starting point= "<<temp[0]<<endl;
    cout<<"Ending point="<<temp[1]<<endl;
    cout<<"Sum="<<temp[2]<<endl;
    return 0;
}
