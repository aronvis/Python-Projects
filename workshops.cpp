#include <iostream>
#include <algorithm>
using namespace std;


struct Workshop
{
    int start_time;
    int duration;
    int end_time;
};

struct Available_Workshops
{
    int num;
    Workshop *workshopArray;
    Available_Workshops(int n): num(n), workshopArray(new Workshop[n]){}
};

Available_Workshops* initialize (int start_time[], int duration[], int n)
{
    Available_Workshops * aw = new Available_Workshops(n);  
    for(int i=0; i<n; i++)
    {
        aw->workshopArray[i].start_time  = start_time[i];
        aw->workshopArray[i].duration = duration[i];
        aw->workshopArray[i].end_time = start_time[i] + duration[i];
    }
    return aw;
}

int CalculateMaxWorkshops(Available_Workshops* ptr)
{
    sort(ptr->workshopArray,(ptr->workshopArray) + ptr->num, [](Workshop& x, Workshop& y){return x.end_time < y.end_time;});
    int maxWorkshops =0;
    int currentEnd =0;
    for(int i=0; i<ptr->num; i++)
    {
        if(ptr->workshopArray[i].start_time >= currentEnd)
        {
            maxWorkshops++;
            currentEnd = ptr->workshopArray[i].end_time;
        }
    }
    return maxWorkshops;
}

int main(int argc, char *argv[]) {
    
    int n; // number of workshops
    cin >> n;
    // create arrays of unknown size n
    int* start_time = new int[n];
    int* duration = new int[n];

    for(int i=0; i < n; i++){
        cin >> start_time[i];
    }
    for(int i = 0; i < n; i++){
        cin >> duration[i];
    }

    Available_Workshops * ptr;
    ptr = initialize(start_time,duration, n);
    cout << CalculateMaxWorkshops(ptr) << endl;
    return 0;
}