#include <stdio.h>

int main()
{
    const int days = 7;
    float temperatures[days];
    float sum = 0.0;
    float highest, lowest;

    // Input temperature readings for the week
    printf("Enter temperature readings for 7 days: \n");
    for (int i = 0; i < days; i++)
    {
        printf("Day %d: ", i + 1);
        scanf("%f", &temperatures[i]);
        sum += temperatures[i];

        // Initialize highest and lowest with the first reading
        if (i == 0)
        {
            highest = lowest = temperatures[i];
        }
20
        // Update highest and lowest temperatures
        if (temperatures[i] > highest)
        {
            highest = temperatures[i];
        }
        if (temperatures[i] < lowest)
        {
            lowest = temperatures[i];
        }
    }

    // Calculate the average temperature
    float average = sum / days;

    // Output the results
    printf("\nAverage temperature of the week: %.2f°C\n", average);
    printf("Highest temperature recorded: %.2f°C\n", highest);
    printf("Lowest temperature recorded: %.2f°C\n", lowest);

    return 0;
}
