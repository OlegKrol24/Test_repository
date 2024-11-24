#include <iostream>
#include <ctime>
#include <iomanip>

using namespace std;

int main()
{
    srand(time(0));

    const int N = 5, M = 12;
    int A[N][M], i, j, sum_profit_month, max_profit_month, index_for_department;
    int Profit[N];
    string Department[N] = {"Multimodal", "Marine", "Railroad", "Automobile", "Air"};
    string Month[M + 1] = {"January", "February", "March", "April", "May", "June", "July", 
                            "August", "September", "October", "November", "December", "Department"};

    for (i = 0; i < 157; i++) cout << "-";
    cout << endl;


    for (i = 0; i < N; i++)
        for (j = 0; j < M; j++) A[i][j] = rand() % 221 - 50;
    
    for (i = 0; i <= M; i++) cout << "|" << setw(10) << Month[i] << "|";
    cout << endl;

    for (i = 0; i < 157; i++) cout << "-";
    cout << endl;

    for (i = 0; i < N; i++)
    {
        for (j = 0; j < M; j++) cout << "|" << setw(10) << A[i][j] << "|";
        cout << "|" << setw(10) << Department[i] << "|";
        cout << endl;
        for (j = 0; j < 157; j++) cout << "-";
        cout << endl;
    }

    cout << endl;

    for (i = 0; i < M; i++)
    {
        for (j = 0; j < N; j++) sum_profit_month += A[j][i];

        cout << "Total profit of all departments is " << Month[i] << " = " << sum_profit_month << endl;

        sum_profit_month = 0;        
    }

    cout << endl;

    for (i = 0; i < M; i++)
    {
        max_profit_month = A[0][i];
        index_for_department = 0;

        for (j = 1; j < N; j++)
            if (A[j][i] > max_profit_month)
            {
                max_profit_month = A[j][i];
                index_for_department = j;
            }

        cout << "The largest profit in " << Month[i] << " was made by " << Department[index_for_department] << " which = " << max_profit_month << endl;        
    }

    return 0;
}