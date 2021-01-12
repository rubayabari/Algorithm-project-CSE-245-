#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,k,Rank,piece,weight,sum=0;
    string name;
    cout<<"Enter Inputs: "<<endl;
    cin>>n>>k;
    vector< pair<int, pair<string, pair<int, int> > > >arr,element;
    for(int i=0; i<n; i++)
    {
        cin>>Rank>>name>>piece>>weight;
        sum+=weight;
        arr.push_back({Rank,{name,{piece,weight}}});
    }
    sort(arr.begin(),arr.end());

    cout<<"\n\nAfter sorting the ranklist: "<<endl
        <<" "<<"Rank"
        <<" "<<"Items"
        <<"	"<<"Amount"
        <<"	"<<"Weight"<<endl;
    for(int i=0; i<n; i++)
    {
        cout<<setw(3)<<arr[i].first<<" "
            <<setw(10)<<arr[i].second.first<<" "
            <<setw(2)<<arr[i].second.second.first<<" pieces "
            <<setw(6)<<arr[i].second.second.second<<" gm/piece"
            <<endl;
    }

    for (int i = 0; i < n; i++)
    {
        Rank=arr[i].first;
        name=arr[i].second.first;
        piece=arr[i].second.second.first-1;
        weight=arr[i].second.second.second;

        if(piece>0)
        {
            if (sum+(piece*weight) <= k)
            {
                sum+=(piece*weight);
                piece++;
                element.push_back({Rank, {name, {piece, piece*weight}}});
            }
            else
            {
                int remain=(k-sum), piece=remain/weight;
                if(remain>=weight && piece>0)
                {
                    sum+=(piece*weight);
                    piece++;
                    element.push_back({Rank, {name, {piece, piece*weight}}});
                }
                else
                    element.push_back({Rank, {name, {1, weight}}});
            }
        }
        else
            element.push_back({Rank, {name, {1, weight}}});

    }

    cout<<"\n\nSelected Elements: "<<endl
        <<"  "<<"Amount"
        <<"	"<<"Items"
        <<"	"<<"Weight"<<endl;
    for(int i=0; i<element.size(); i++)
    {
        cout<<setw(2)<<element[i].second.second.first<<" pieces "
            <<setw(10)<<element[i].second.first<<" "
            <<setw(7)<<element[i].second.second.second<<" gm"
            <<endl;
    }
    cout<<"	"<<"Total: "
        <<setw(7)<<sum<<" gm"<<endl;

    return 0;
}
