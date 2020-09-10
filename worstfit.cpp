#include<bits/stdc++.h>
using namespace std;
void worstfit(int blocksize[],int processsize[],int totalblocks,int totalprocess)
{
    int allocation[totalprocess],sum=0,max,s,flag;
    memset(allocation, -1, sizeof(allocation));
    for (int i=0; i<totalprocess; i++)
    {
        flag = 0;
        max=-2147483648;

        for(int j = 0; j < totalblocks; j++)
        {
            if(blocksize[j] > max)
            {
                max = blocksize[j];
                s=j;
            }
        }
        if(blocksize[s]>=processsize[i])
        {
            allocation[i]=s;
            blocksize[s]-=processsize[i];

            flag=1;
        }
        if(flag==0)
            break;


    }
    cout<<"\t\t WORST FIT\n";
    cout<<"\nProcess Size\tBlock Number\n";
    for(int i=0; i<totalprocess; i++)
    {
        cout<<processsize[i]<<"\t\t";
        if (allocation[i] != -1)
            cout <<"Block"<< allocation[i] + 1;
        else
            cout << "Not Allocated";
        cout << endl;
    }
    for(int i=0; i<totalblocks; i++)
    {
        sum=sum+blocksize[i];
    }
    cout << "\nExternal Fregmentation:"<<sum<<"\n";

}





int main()
{
    int totalblocks=5,totalprocess=10;
    int blocksize[5]= {50,200,70,115,15};
    int processsize[10]= {100,10,35,15,23,6,25,55,88,40};
    worstfit(blocksize,processsize,totalblocks,totalprocess);


}







