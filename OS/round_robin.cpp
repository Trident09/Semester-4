#include <iostream>
#include <queue>

using namespace std;

// Process structure
struct Process {
    int pid; // process ID
    int bt; // burst time
    int art; // arrival time
    int wt; // waiting time
    int tat; // turnaround time
    int rt; // remaining time
    int ct; // completion time

    // Constructor
    Process(int pid, int bt, int art) {
        this->pid = pid;
        this->bt = bt;
        this->art = art;
        this->wt = 0;
        this->tat = 0;
        this->rt = bt;
        this->ct = 0;
    }
};

void findWaitingTime(Process processes[], int n, int quantum) {
    queue<Process> ready_queue;

    int t = 0; // current time
    int total_bt = 0; // total burst time

    // Add all processes to ready queue
    for (int i = 0; i < n; i++) {
        ready_queue.push(processes[i]);
        total_bt += processes[i].bt;
    }

    // Process until ready queue is empty
    while (!ready_queue.empty()) {
        Process p = ready_queue.front();
        ready_queue.pop();

        // If remaining time of process is less than or equal to quantum
        if (p.rt <= quantum) {
            t += p.rt;
            total_bt -= p.rt;
            p.rt = 0;
            p.wt = t - p.bt - p.art;
            p.tat = t - p.art;
            p.ct = t;

            // Print process details
            cout << "Process " << p.pid << ": ";
            cout << "WT = " << p.wt << ", ";
            cout << "TAT = " << p.tat << ", ";
            cout << "CT = " << p.ct << endl;
        }
        // If remaining time of process is greater than quantum
        else {
            t += quantum;
            total_bt -= quantum;
            p.rt -= quantum;

            // Add process back to ready queue
            ready_queue.push(p);
        }
    }

    // Calculate CPU utilization
    float cpu_utilization = 1 - (float)total_bt/t;
    cout << "CPU utilization: " << cpu_utilization << endl;
}

int main() {
    int n, quantum;

    cout << "Enter the number of processes: ";
    cin >> n;

    cout << "Enter the quantum: ";
    cin >> quantum;

    Process processes[n];

    // Input process details
    for (int i = 0; i < n; i++) {
        int pid, bt, art;

        cout << "Enter process " << i+1 << " details:\n";
        cout << "Burst Time: ";
        cin >> bt;
        cout << "Arrival Time: ";
        cin >> art;

        processes[i] = Process(i+1, bt, art);
    }

    // Find waiting time of processes using Round Robin scheduling
    findWaitingTime(processes, n, quantum);

    return 0;
}
