#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

int main() {

    srand(time(nullptr)); // ����������� �������
    
    float C[5][6]; // ������� ��������� ������ C

    // ��������� ������ �������� ��� ���� ��� �� ���������� ������
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 6; j++) {
            C[i][j] = 0.1 * (rand() % 40 - 20);
        }
    }

    // ������� ������ ��� �����������
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 6; j++) {
            cout << C[i][j] << " ";
        }
        cout << endl;
    }

    float D[5] = {}; // ������� ������ D

    // ��������� ������� C[i][5] > 0 � ��������� ������ D
    for (int i = 0; i < 5; i++) {
        if (C[i][5] > 0) {
            for (int j = 0; j < 6; j++) {
                D[i] += C[i][j];
            }
        }
        else {
            D[i] = 0;
        }
    }

    // ����� ������� D
    for (int i = 0; i < 5; i++) {
        cout << "D[" << i << "] = " << D[i] << endl;
    }

    return 0;
}