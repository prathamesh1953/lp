#include <iostream>
using namespace std;

int main() {
    int n, i, qt, count = 0, temp, sq = 0, bt[10], wt[10], tat[10], rem_bt[10];
    float awt = 0, atat = 0;

    cout << "Enter the number of processes (maximum 10) = ";
    cin >> n;

    cout << "Enter the burst time of the processes\n";
    for (i = 0; i < n; i++) {
        cout << "P" << i << " = ";
        cin >> bt[i];
        rem_bt[i] = bt[i];
    }

    cout << "Enter the quantum time: ";
    cin >> qt;

    while (true) {
        for (i = 0, count = 0; i < n; i++) {
            temp = qt;
            if (rem_bt[i] == 0) {
                count++;
                continue;
            }
            if (rem_bt[i] > qt)
                rem_bt[i] = rem_bt[i] - qt;
            else if (rem_bt[i] >= 0) {
                temp = rem_bt[i];
                rem_bt[i] = 0;
            }
            sq = sq + temp;
            tat[i] = sq;
        }
        if (n == count)
            break;
    }

    cout << "--------------------------------------------------------------------------------\n";
    cout << "Process\tBurst Time\tTurnaround Time\tWaiting Time\n";
    cout << "--------------------------------------------------------------------------------\n";
    for (i = 0; i < n; i++) {
        wt[i] = tat[i] - bt[i];
        awt = awt + wt[i];
        atat = atat + tat[i];
        cout << "\n " << (i + 1) << "\t " << bt[i] << "\t\t " << tat[i] << "\t\t " << wt[i] << "\n";
    }

    awt = awt / n;
    atat = atat / n;

    cout << "\nAverage Waiting Time = " << awt << "\n";
    cout << "Average Turnaround Time = " << atat << "\n";

    return 0;
}