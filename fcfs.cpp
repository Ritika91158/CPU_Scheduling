#include <iostream>
#include <vector>
using namespace std;

void fcfsScheduling(vector<int>& processes, int n, vector<int>& burst_time) {
    vector<int> waiting_time(n), turnaround_time(n);
    waiting_time[0] = 0;
    turnaround_time[0] = burst_time[0];

    for (int i = 1; i < n; i++) {
        waiting_time[i] = burst_time[i - 1] + waiting_time[i - 1];
        turnaround_time[i] = burst_time[i] + waiting_time[i];
    }

    cout << "Process\tBurst Time\tWaiting Time\tTurnaround Time\n";
    for (int i = 0; i < n; i++) {
        cout << processes[i] << "\t" << burst_time[i] << "\t\t" << waiting_time[i] << "\t\t" << turnaround_time[i] << endl;
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
    vector<int> processes = {1, 2, 3};
    vector<int> burst_time = {5, 2, 8};
    int n = processes.size();
    
    fcfsScheduling(processes, n, burst_time);
    
    return 0;
}
