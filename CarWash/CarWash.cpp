/*CSCI 182 - CarWash Assignment
CarWash.cpp


Landon Reekstin
v1.0 5/5/2020 */

#include <iostream>
#include <time.h>
#include <stdlib.h>
#include "SimpleList.h"
#define WASH_TIME 180

using namespace std;
   

int main()
{
    try {


        // Seed the random generator (near the top)
        srand(time(NULL));

        int nSimCarProbPercentage;
        int totalTime;

        float avgWaitTime;

        cout << "Enter a number 0-100 to simulate probability of the arrival of a new car each second: ";
        cin >> nSimCarProbPercentage;
        cout << endl;

        cout << "Enter a number in hours for the total time that the car wash will run: ";
        cin >> totalTime;
        cout << endl;

        totalTime = totalTime * 3600;


        int carCount = 0;

        int carsWashed = 0;

        int entryTime = 0;

        int waitTimeSumTemp = 0;

        int totalWaitTimeSum = 0;

        bool washEmpty = true;

        int carWashTimer = 0;

        SimpleList c1;

        // Loop for total time of the day in seconds
        // Controls cars entering queue and car wash
        for (int i = 0; i < totalTime; i++)
        {

            // For each minute, get a random value.  If you do it like this,
            // you get a number between 0-99
            int q = rand() % 100;
            // Below we check if it's within the probability
            // nSimCarProbPercentage is the percentage entered by the user
            if (q < nSimCarProbPercentage)
            {
                // Process a car into the queue
                c1.QueueItem(entryTime = i);
                carCount++;
            }

            // Sending a car to the wash every 3 minutes
            if (!c1.CheckIfEmpty() && washEmpty)
            {
                carCount--;
                carsWashed++;
                carWashTimer = 0;
                washEmpty = false;

                // Average wait time
                // use return value from DequeueItem (which is equal to entryTime) and sutract from current totalTime
                waitTimeSumTemp = i - c1.DequeueItem();

                // add next time to total sum of wait times
                totalWaitTimeSum = totalWaitTimeSum + waitTimeSumTemp;

            }
            // Keeps track of 3 minute timer in car wash
            // Prevents another car from entering wash while one is still washing
            carWashTimer++;

            if (carWashTimer == 180)
            {
                washEmpty = true;
            }
        }

        // Finding average wait time
        avgWaitTime = totalWaitTimeSum / carsWashed;
        avgWaitTime = avgWaitTime / 60;

        cout << "Number of Cars Washed: " << carsWashed << endl;
        cout << "Number of Cars left in Queue: " << carCount << endl;
        cout << "Average Wait Time: " << avgWaitTime << " minutes" << endl;

    }
    // Exception Handling
    catch (exception& ex)
    {
        cout << "Error found: " << ex.what() << endl;
    }
    catch (...)
    {
        cout << "Really bad error" << endl;
    }

}

