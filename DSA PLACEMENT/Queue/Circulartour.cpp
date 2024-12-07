#include <bits/stdc++.h>
using namespace std;

// Structure to represent a petrol pump
struct petrolpump
{
    int petrol;   // amount of petrol available at the pump
    int distance; // distance to the next petrol pump
};

int tour(petrolpump p[], int n)
{
    int deficit = 0; // kitni kami hai
    int balance = 0; // kitna bacha hua hai
    int start = 0;   // starting karunga first index se
    for (int i = 0; i < n; i++)
    {
        balance += p[i].petrol - p[i].distance; // balance nikal liya samne jane k liye kitna chahite
        if (balance < 0)
        {                        // agar balance neg aya then
            deficit = deficit-balance; // itne ki kami aa rahi hai
            start = i + 1;       // new start kiya
            balance = 0;         // to balance bhi zero hoga
        }
    }
    if (deficit + balance >= 0)//jokhon new start theke ghure aschi new start korar por then jodi amar komi +balance >=0 hoy tahole to pohuchei jabo desitnation e
    {
        return start;//desitination e pohuche gache so start ta return kore dao
    }
    else
    {
        return -1;
    }
}

int main()
{
    int n;
    cout << "Enter the number of petrol pumps: ";
    cin >> n;
    petrolpump p[n];
    cout << "Enter petrol and distance for each petrol pump:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> p[i].petrol >> p[i].distance;
    }

    int start = tour(p, n);
    if (start != -1)
    {
        cout << "Start the tour at petrol pump index: " << start << endl;
    }
    else
    {
        cout << "Tour is not possible.\n";
    }
    return 0;
}
