#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HEADING "PID\tAT\tBT\tWT\tTAT\tRT\n"
#define PLACEHOLDER "%d\t%d\t%d\t%d\t%d\t%d\n"
#define AWT "Average Waiting Time: %f\n"
#define ATT "Average Turnaround Time: %f\n"
#define ART "Average Response Time: %f\n"

struct Process
{
    int pid;
    int arrival_time;
    int burst_time;
    int turnaround_time;
    int waiting_time;
    int response_time;
};

enum Scheduling
{
    FCFS,
    SJF
};

int burstAndArrivalComparator(const void *a, const void *b)
{
    struct Process *p1 = (struct Process *)a;
    struct Process *p2 = (struct Process *)b;
    int result = p1->arrival_time - p2->arrival_time;
    if (result != 0)
    {
        return result;
    }
    else
    {
        return p1->burst_time - p2->burst_time;
    }
}

int arrivalComparator(const void *a, const void *b)
{
    struct Process *p1 = (struct Process *)a;
    struct Process *p2 = (struct Process *)b;
    return p1->arrival_time - p2->arrival_time;
}

void printTable(struct Process *processes, int n, enum Scheduling type)
{
    int twt = 0, ttt = 0, trt = 0;

    switch (type)
    {
    case FCFS:
        printf("=== First Come First Served (FCFS) ===\n");
        break;
    case SJF:
        printf("=== Shortest Job First (SJF) ===\n");
        break;
    }

    printf("Gantt Chart: ");
    for (int i = 0; i < n; i++)
    {
        printf("| P%d ", processes[i].pid);
    }
    printf("|\n");
    printf(HEADING);
    for (int i = 0; i < n; i++)
    {
        struct Process p = processes[i];
        twt += p.waiting_time;
        ttt += p.turnaround_time;
        trt += p.response_time;
        printf(PLACEHOLDER, p.pid, p.arrival_time, p.burst_time, p.waiting_time, p.turnaround_time, p.response_time);
    }

    printf(AWT, (double)twt / n);
    printf(ATT, (double)ttt / n);
    printf(ART, (double)trt / n);
}

void fcfs(struct Process *processes, int n)
{
    int position = 0;

    qsort(processes, n, sizeof(struct Process), arrivalComparator);
    position = processes[0].burst_time;
    processes[0].turnaround_time = processes[0].burst_time;
    processes[0].waiting_time = processes[0].turnaround_time - processes[0].burst_time;
    processes[0].response_time = 0;

    for (int i = 1; i < n; i++)
    {
        position += processes[i].burst_time;
        processes[i].turnaround_time = position - processes[i].arrival_time;
        processes[i].waiting_time = processes[i].turnaround_time - processes[i].burst_time;
        processes[i].response_time = processes[i - 1].turnaround_time + processes[i - 1].arrival_time;
    }

    printTable(processes, n, FCFS);
}

void sjf(struct Process *processes, int n)
{
    int position = 0;

    qsort(processes, n, sizeof(struct Process), burstAndArrivalComparator);
    position = processes[0].burst_time;
    processes[0].turnaround_time = processes[0].burst_time;
    processes[0].waiting_time = processes[0].turnaround_time - processes[0].burst_time;
    processes[0].response_time = 0;

    for (int i = 1; i < n; i++)
    {

        for (int j = i + 1; j < n; j++)
        {
            if (processes[j].arrival_time < position && processes[j].burst_time < processes[i].burst_time)
            {
                struct Process temp = processes[i];
                processes[i] = processes[j];
                processes[j] = temp;
            }
        }

        position += processes[i].burst_time;
        processes[i].turnaround_time = position - processes[i].arrival_time;
        processes[i].waiting_time = processes[i].turnaround_time - processes[i].burst_time;
        processes[i].response_time = processes[i - 1].turnaround_time + processes[i].arrival_time;
    }
    printTable(processes, n, SJF);
}

int main()
{
    struct Process *processes1;
    struct Process *processes2;
    int i, n, sum = 0;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    if (n <= 0)
    {
        printf("Processes number should be bigger than 0\n");
        return 1;
    }

    processes1 = (struct Process *)malloc(n * sizeof(struct Process));

    if (processes1 == NULL)
    {
        printf("Memory allocation failed!\n");
        return 1;
    }

    for (i = 0; i < n; i++)
    {
        processes1[i].pid = i + 1;

        printf("Enter the arrival time and burst time for process %d: ", i + 1);
        scanf("%d %d", &processes1[i].arrival_time, &processes1[i].burst_time);
    }

    memcpy(processes2, processes1, n * sizeof(struct Process));

    printf("\n");
    fcfs(processes1, n);
    printf("\n");
    sjf(processes2, n);

    return 0;
}