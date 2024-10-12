# Process Scheduling Simulator

This C program simulates two CPU scheduling algorithms: First-Come, First-Served (FCFS) and Shortest Job First (SJF). It allows users to input process details and view the resulting schedule, including Gantt charts and average waiting, turnaround, and response times.

## Prerequisites

To compile and run this program, you need:

- A C compiler (e.g., GCC)
- Git (for cloning the repository)

## Getting Started

Follow these steps to get the program running on your local machine:

1. **Compile the code**
    
- You'll need a C compiler like GCC. Save the code as scheduling.c and run: `gcc scheduling.c -o scheduling`

2. **Run the program**
    
- `./scheduling`

3. **Enter the number of processes**
    
- You'll be prompted to enter the number of processes you want to simulate.

4. **Enter process details**
    
- For each process, enter its arrival time and burst time.

The program will then display scheduling results for both FCFS (First Come First Served) and SJF (Shortest Job First) algorithms.