#include<bits/stdc++.h>
using namespace std;

void itenary(unordered_map<string,string> tickets)
{
    //STORING THE 'TO' INFO IN A SET TO FIND THE STARTING POINT THAT DOESNT EXIST IN SET
    unordered_set<string> to;
    for(auto const& [key,value]:tickets)
    {
        to.insert(value);
    }

    //WE FIND THE STARTING POINT
    string start="";
    for(auto const& [key,value]:tickets)
    {
        if(to.find(key)==to.end())
        {
            start=key;
        }
    }

    //WE PRINT THE DESTINATIONS FROM THE STARTING POINT
    while(tickets.count(start))
    {
        cout<<start<<"->";
        start=tickets[start];
    }

    //HERE THE LAST DESTINATION IS PRINTED
    cout<<start;
}

int main()
{
    unordered_map<string,string> tickets;
    tickets["Chennai"]="Mumbai";
    tickets["Mumbai"]="Goa";
    tickets["Goa"]="Delhi";
    tickets["Delhi"]="Bangaluru";

    itenary(tickets);
    
    return 0;
}