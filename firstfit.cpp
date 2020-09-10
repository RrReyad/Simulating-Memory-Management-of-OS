#include<bits/stdc++.h>
using namespace std;
void firstfit(int blocksize[],int processsize[],int totalblocks,int totalprocess)
{
    int allocation[totalprocess],sum=0;
    memset(allocation, -1, sizeof(allocation));
    for (int i=0; i<totalprocess; i++)
    {
        for(int j=0; j<totalblocks; j++)
        {
            if(blocksize[j]>=processsize[i])
            {
                allocation[i]=j;
                blocksize[j]-=processsize[i];

                break;
            }

        }

    }
    cout<<"\t\t FIRST FIT\n";
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
    firstfit(blocksize,processsize,totalblocks,totalprocess);


}
