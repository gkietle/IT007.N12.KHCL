#include <stdio.h>

int main()
{
    int count, j, n, time, remain, flag = 0, time_quantum;
    int wait_time = 0, turnaround_time = 0;
    int at[10], bt[10], rt[10];
    printf("Enter number of processes:\t ");
    scanf("%d", &n);
    remain = n;
    for (count = 0; count < n; count++)
    {
        printf("Enter Busrt time for Process Number %d: ", count + 1);
        at[count] = 0;
        scanf("%d", &bt[count]);
        rt[count] = bt[count];
    }
    printf("Enter Time quantum:\t");
    scanf("%d", &time_quantum);
    printf("\n\nProcess\t|   Stop Time   |  Start Time\n\n");
    for (time = 0, count = 0; remain != 0;)
    {
        if (rt[count] <= time_quantum && rt[count] > 0)
        {
            int starttime;
            starttime = time;
            time += rt[count];
            rt[count] = 0;
            flag = 1;
            printf("P[%d]\t|\t%d\t|\t%d\n", count + 1, time - at[count], starttime);
        }
        else if (rt[count] > 0)
        {
            rt[count] -= time_quantum;
            time += time_quantum;
            printf("P[%d]\t|\t%d\t|\t%d\n", count + 1, time - at[count], time_quantum);
        }
        if (rt[count] == 0 && flag == 1)
        {
            remain--;
            wait_time += time - at[count] - bt[count];
            turnaround_time += time - at[count];
            flag = 0;
        }
        if (count == n - 1)
            count = 0;
        else if (at[count + 1] <= time)
            count++;
        else
            count = 0;
    }
    printf("\nAverage waiting time: %f\n", wait_time * 1.0 / n);
    printf("Average turn around time: %f\n", turnaround_time * 1.0 / n);
    printf("\n");

    return 0;
}
