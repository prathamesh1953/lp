#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    cout << "*** Shortest Job First Scheduling (Preemptive) ***" << endl;
    cout << "Enter no of process:";
    int n;
    cin >> n;

    int process[n];
    int arrivalTime[n];
    int burstTime[n];
    int completionTime[n];
    int TAT[n];
    int waitingTime[n];
    int visit[n];
    int remBurstTime[n];
    int temp, start = 0, total = 0;
    float avgwt = 0, avgTAT = 0;

    for (int i = 0; i < n; i++) {
        cout << " " << endl;
        process[i] = (i + 1);
        cout << "Enter Arrival Time for processor " << (i + 1) << ":";
        cin >> arrivalTime[i];
        cout << "Enter Burst Time for processor " << (i + 1) << ": ";
        cin >> burstTime[i];
        remBurstTime[i] = burstTime[i];
        visit[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (arrivalTime[i] < arrivalTime[j]) {
                temp = process[j];
                process[j] = process[i];
                process[i] = temp;
                temp = arrivalTime[j];
                arrivalTime[j] = arrivalTime[i];
                arrivalTime[i] = temp;
                temp = remBurstTime[j];
                remBurstTime[j] = remBurstTime[i];
                remBurstTime[i] = temp;
                temp = burstTime[j];
                burstTime[j] = burstTime[i];
                burstTime[i] = temp;
            }
        }
    }

    while (true) {
        int min = 99, c = n;
        if (total == n) {
            break;
        }
        for (int i = 0; i < n; i++) {
            if ((arrivalTime[i] <= start) && (visit[i] == 0) && (burstTime[i] < min)) {
                min = burstTime[i];
                c = i;
            }
        }

        if (c == n)
            start++;
        else {
            burstTime[c]--;
            start++;
            if (burstTime[c] == 0) {
                completionTime[c] = start;
                visit[c] = 1;
                total++;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        TAT[i] = completionTime[i] - arrivalTime[i];
        waitingTime[i] = TAT[i] - remBurstTime[i];
        avgwt += waitingTime[i];
        avgTAT += TAT[i];
    }

    cout << "*** Shortest Job First Scheduling (Preemptive) ***" << endl;
    cout << "Processor\tArrival time\tBrust time\tCompletion Time\t\tTurn around time\tWaiting time" << endl;
    cout << "----------------------------------------------------------------------------------------------------------" << endl;

    for (int i = 0; i < n; i++) {
        cout << "P" << process[i] << "\t\t" << arrivalTime[i] << "ms\t\t" << remBurstTime[i] << "ms\t\t"
             << completionTime[i] << "ms\t\t\t" << TAT[i] << "ms\t\t\t" << waitingTime[i] << "ms" << endl;
    }

    avgTAT /= n;
    avgwt /= n;

    cout << "\nAverage turn around time is " << avgTAT << "ms" << endl;
    cout << "Average waiting time is " << avgwt << "ms" << endl;

    return 0;
}
