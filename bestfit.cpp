#include<bits/stdc++.h>
using namespace std;
void bestfit(int blocksize[],int processsize[],int totalblocks,int totalprocess)
{
    int allocation[totalprocess],sum=0,min,s,flag,temp;
    memset(allocation, -1, sizeof(allocation));
    for (int i=0; i<totalprocess; i++)
    {
        flag = 0;
        s=0;
        min= 2147483647;

        for(int j = 0; j < totalblocks; j++)
        {
            temp = blocksize[j] - processsize[i];

            if(temp>=0)
                if(min > temp)
                {
                    min = temp;
                    s=j;
                    flag=1;
                }
        }

        if(flag==0)
        {

            break;
        }
        allocation[i] = s;
        blocksize[s]-=processsize[i];





    }
    cout<<"\t\t BEST FIT\n";
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
    if (flag!=0)
        cout << "\nNo External Fregmentation\n";
    else
        cout << "\nExternal Fregmentation:"<<sum<<"\n";

}





int main()
{
    int totalblocks=5,totalprocess=10;
    int blocksize[5]= {50,200,70,115,15};
    int processsize[10]= {100,10,35,15,23,6,25,55,88,40};
    bestfit(blocksize,processsize,totalblocks,totalprocess);


}







