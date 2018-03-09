#include <bits/stdc++.h>

#define sz(v)	((int)((v).size()))

using namespace std;
typedef long long ll;
class car
{
public:
    //rides taken by the car
    vector<int>ride;
    //current position of the car
    int row=0,col=0;
    //the taken steps
    ll step=0;
};
class Ride
{
public:
    ///(row,col)
    int start_point[2],
        end_point[2];
    int start,finish;
    int distance;
};
bool freq[10000000]= {0};
int main()
{
    speedio;

    int row,col,vic,ride,bonus,steps;
    freopen("c_no_hurry.out","w",stdout);
    freopen("c_no_hurry.in","r",stdin);
    while( cin>>row>>col>>vic>>ride>>bonus>>steps)
    {
        for(int i=0; i<10000000; i++)freq[i]=0;
        car cars[vic];
        Ride rides[ride];
        int arr[ride];
        for(int i=0; i<ride; i++)arr[i]=i;
        for(int i=0; i<ride; i++)
        {
            cin>>rides[i].start_point[0];
            cin>>rides[i].start_point[1];
            cin>>rides[i].end_point[0];
            cin>>rides[i].end_point[1];
            cin>>rides[i].start;
            cin>>rides[i].finish;
            rides[i].distance=(abs(rides[i].start_point[0]-rides[i].end_point[0])+abs(rides[i].start_point[1]-rides[i].end_point[1]));
        }
       for(int n=0; n<vic; n++)
        {
        for(int i=0; i<vic; i++)
        {
            cars[i].step=0;
            for(int k=0; k<ride; k++)
            {
                int r=k;
                for(int j=0; j<ride; j++)
                    if(freq[j]==0&&freq[r]==0&&rides[j].distance>=rides[r].distance) r=j;
                if(freq[r]==0)
                {
                    ll d=(cars[i].step+(abs(cars[i].row-rides[r].start_point[0])+abs(cars[i].col-rides[r].start_point[1]))+rides[r].distance);
                    if(d<steps)
                    {
                        cars[i].ride.push_back(r);
                        cars[i].row=rides[r].end_point[0];
                        cars[i].col=rides[r].end_point[1];
                        cars[i].step=d;
                        freq[r]=1;
                    }
                }
            }
        }
        }
      for(int i=0; i<vic; i++)
        {
            cout<<sz(cars[i].ride)<<" ";
            for(auto j:cars[i].ride)
            {
                cout<<j<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}
