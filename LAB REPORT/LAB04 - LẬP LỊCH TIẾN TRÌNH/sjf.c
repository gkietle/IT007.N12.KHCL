#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void deleteThenInsert(int a[], int n, int cu, int moi)
{
    int temp = a[cu];
    if (cu < 0 || moi < 0 || cu >= n || moi >= n || moi == cu)
        return;
    else if (moi < cu)
    {
        for (int i = cu; i > moi; i--)
            a[i] = a[i - 1];
        a[moi] = temp;
    }
    else
    {
        for (int i = cu; i < moi; i++)
            a[i] = a[i + 1];
        a[moi] = temp;
    }
}

int minAtIndex(int a[], int n, int start, int end)
{
    if (start > end || start < 0 || end >= n)
        return -1;
    int index = start;
    for (int i = start + 1; i <= end; i++)
        if (a[i] < a[index])
            index = i;
    return index;
}

void main()
{
    int pn[20], arr[20], bur[20], star[20], finish[20], tat[20],
        wt[20], i, j, k, n;
    int totwt = 0, tottat = 0;
    float awt, atat;

    printf("Enter the number of processes: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("Enter the Process Name, Arrival Time & Burst Time: ");
        scanf("%d%d%d", &pn[i], &arr[i], &bur[i]);
    }
    for (i = 0; i < n - 1; i++)
        for (j = i + 1; j < n; j++)
            if (arr[i] > arr[j])
            {
                swap(&arr[i], &arr[j]);
                swap(&bur[i], &bur[j]);
                swap(&pn[i], &pn[j]);
            }
    i = 1;
    while (i < n && arr[i] == arr[0])
        i++;
    j = minAtIndex(bur, n, 0, i - 1);

    if (j != 0)
    {
        deleteThenInsert(arr, n, j, 0);
        deleteThenInsert(bur, n, j, 0);
        deleteThenInsert(pn, n, j, 0);
    }

    star[0] = arr[0];
    wt[0] = 0;
    finish[0] = star[0] + bur[0];
    tat[0] = finish[0] + arr[0];

    for (k = 1; k < n; k++)
    {
        if (arr[k] > finish[k - 1])
        {
            i = k + 1;
            while (i < n && arr[i] == arr[k])
                i++;
            j = minAtIndex(bur, n, k, i - 1);
            if (j != k)
            {
                deleteThenInsert(arr, n, j, k);
                deleteThenInsert(bur, n, j, k);
                deleteThenInsert(pn, n, j, k);
            }
            star[k] = arr[k];
        }
        else
        {
            i = k + 1;
            while (i < n && arr[i] <= finish[k - 1])
                i++;
            j = minAtIndex(bur, n, k, i - 1);
            if (j != k)
            {
                deleteThenInsert(arr, n, j, k);
                deleteThenInsert(bur, n, j, k);
                deleteThenInsert(pn, n, j, k);
            }
            star[k] = finish[k - 1];
        }
        finish[k] = star[k] + bur[k];
        wt[k] = star[k] - arr[k];
        tat[k] = finish[k] - star[k];
    }

    printf("\nPName\tArrTime\tBurTime\tStart\tFinish\tTAT\tWT");
    for (i = 0; i < n; i++)
    {
        printf("\n%5d\t%7d\t%7d\t%5d\t%6d\t%3d\t%2d", pn[i],
               arr[i], bur[i], star[i], finish[i], tat[i], wt[i]);
        totwt += wt[i];
        tottat += tat[i];
    }

    awt = (float)totwt / n;
    atat = (float)tottat / n;
    printf("\n\nAverage waiting time: %f\n", awt);
    printf("Average turn around time: %f\n", atat);
}