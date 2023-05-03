#include <iostream>
#include <iomanip>

using namespace std;

void printGanttChart(int p, int process[], int completion[])
{
    cout << "\nGantt Chart:\n";
    for (int i = 0; i < p; i++)
    {
        cout << "+--------";
    }
    cout << "+\n";
    for (int i = 0; i < p; i++)
    {
        cout << "  | P" << process[i] << "   ";
    }
    cout << "|\n";
    for (int i = 0; i < p; i++)
    {
        cout << "+--------";
    }
    cout << "+\n";
    cout << "0       ";
    for (int i = 0; i < p; i++)
    {
        cout << completion[i] << "       ";
    }
    cout << endl;
}

// Function to input process information
void input(int &p, int process[], int arrival[], int burst[])
{
    cout << "Enter the number of processes: ";
    cin >> p;
    cout << "Enter the arrival time of processes: " << endl;
    for (int i = 0; i < p; i++)
    {
        cout << "Enter the arrival time of " << i + 1 << " process: ";
        cin >> arrival[i];
    }
    cout << "Enter the burst time of processes: " << endl;
    for (int i = 0; i < p; i++)
    {
        cout << "Enter the burst time of " << i + 1 << " process: ";
        cin >> burst[i];
    }
    // Generate process IDs
    for (int i = 0; i < p; i++)
    {
        process[i] = i + 1;
    }
}

// Function to implement FCFS scheduling
void fcfs(int p, int process[], int arrival[], int burst[], int wait[], int turnaround[], int completion[])
{

    wait[0] = 0;
    turnaround[0] = burst[0];
    completion[0] = arrival[0] + burst[0];

    for (int i = 1; i < p; i++)
    {
        // Calculate waiting time as difference between completion time of previous process and arrival time of current process
        wait[i] = completion[i - 1] - arrival[i];
        if (wait[i] < 0)
        {
            wait[i] = 0;
        }
        // Calculate turnaround time as sum of waiting time and burst time
        turnaround[i] = wait[i] + burst[i];
        // Calculate completion time as sum of arrival time, waiting time, and burst time
        completion[i] = arrival[i] + wait[i] + burst[i];
    }
}
void throughput_and_utilization(int p, int burst[], int completion[], float &throughput, float &utilization)
{
    float total_burst_time = 0;
    float total_execution_time = 0;

    for (int i = 0; i < p; i++)
    {
        total_burst_time += burst[i];
        total_execution_time += completion[i];
    }

    throughput = p / total_execution_time;
    utilization = total_burst_time / total_execution_time;
}

int main()
{
    int p; // Number of processes
    int process[100], arrival[100], burst[100], wait[100], turnaround[100], completion[100];

    // Input process information
    input(p, process, arrival, burst);

    // Implement FCFS scheduling
    fcfs(p, process, arrival, burst, wait, turnaround, completion);

    // Print process information
    cout << left << setw(10) << "Process"
         << setw(15) << "Arrival Time"
         << setw(15) << "Burst Time"
         << setw(15) << "Waiting Time"
         << setw(15) << "Completion Time  "
         << "Turnaround Time" << endl;

    for (int i = 0; i < p; i++)
    {
        cout << left << setw(10) << process[i]
             << setw(15) << arrival[i]
             << setw(15) << burst[i]
             << setw(15) << wait[i]
             << setw(15) << completion[i] << "  "
             << turnaround[i] << endl;
    }

    double avg_wait = 0.0, avg_turnaround = 0.0;

    for (int i = 0; i < p; i++)
    {
        avg_wait += wait[i];
        avg_turnaround += turnaround[i];
    }

    avg_wait /= p;
    avg_turnaround /= p;

    cout << "\nAverage Waiting Time: " << avg_wait << endl;
    cout << "Average Turnaround Time: " << avg_turnaround << endl;
    float throughput, utilization;
    throughput_and_utilization(p, burst, completion, throughput, utilization);

    cout << "\nThroughput : " << throughput << endl;
    cout << "CPU Utilization : " << utilization << endl;
    printGanttChart(p, process, completion);
    return 0;
}