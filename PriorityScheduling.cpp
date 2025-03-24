// 4. Priority Scheduling
#include <iostream>
using namespace std;

void priorityScheduling(int processes[], int n, int burst_time[], int priority[]) {
    int waiting_time[n], turnaround_time[n];
    int temp_burst, temp_pid, temp_priority;

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (priority[i] > priority[j]) {
                temp_burst = burst_time[i];
                burst_time[i] = burst_time[j];
                burst_time[j] = temp_burst;

                temp_pid = processes[i];
                processes[i] = processes[j];
                processes[j] = temp_pid;

                temp_priority = priority[i];
                priority[i] = priority[j];
                priority[j] = temp_priority;
            }
        }
    }

    waiting_time[0] = 0;
    turnaround_time[0] = burst_time[0];

    for (int i = 1; i < n; i++) {
        waiting_time[i] = burst_time[i - 1] + waiting_time[i - 1];
        turnaround_time[i] = burst_time[i] + waiting_time[i];
    }

    cout << "Priority Scheduling:\n";
    cout << "Process\tBurst Time\tPriority\tWaiting Time\tTurnaround Time\n";
    for (int i = 0; i < n; i++) {
        cout << processes[i] << "\t" << burst_time[i] << "\t\t" << priority[i] << "\t\t" << waiting_time[i] << "\t\t" << turnaround_time[i] << endl;
    }

    double avg_waiting_time = 0, avg_turnaround_time = 0;
    for (int i = 0; i < n; i++) {
        avg_waiting_time += waiting_time[i];
        avg_turnaround_time += turnaround_time[i];
    }
    cout << "Average Waiting Time: " << avg_waiting_time / n << endl;
    cout << "Average Turnaround Time: " << avg_turnaround_time / n << endl << endl;
}

int main() {
    int processes[] = {1, 2, 3};
    int burst_time[] = {5, 2, 8};
    int priority[] = {3, 1, 2};
    int n = sizeof(processes) / sizeof(processes[0]);
    
    priorityScheduling(processes, n, burst_time, priority);
    
    return 0;
}
