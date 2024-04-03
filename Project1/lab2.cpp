#include <iostream>

using namespace std;

int main() {

    //ќбь€вление 2-ух двумерных массивов. Ёлементы массивов введены с клавиатуры.
    float S[5][5] = {
        {1.5, -2.3, 3.7, -4.1, 5.2},
        {-6.4, 7.9, -8.6, 9.3, -1.1},
        {2.6, -3.8, 4.0, -5.2, -6.1},
        {-7.2, 8.4, -9.6, 1.8, -2.4},
        {3.9, -4.5, 5.1, -6.3, -7.0}
    };

    float X[5][5] = {
        {1.2, -2.9, 3.3, -4.7, 5.5},
        {-6.1, 7.0, -8.2, 9.4, -1.5},
        {2.3, -3.4, 4.8, -5.6, 6.2},
        {-7.5, 8.1, -9.2, 1.5, -2.6},
        {3.8, -4.2, 5.6, -6.1, 7.3}
    };

    //—оздали 2 переменные 
    int A = 0;
    int B = 0;

    int totalPosS = 0; 
    int totalPosX = 0; 
    int totalNegS = 0;
    int totalNegX = 0;


    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (S[i][j] > 0) {
                totalPosS++;
            }
            else {
                totalNegS++;
            }

            if (X[i][j] > 0) {
                totalPosX++;
            }
            else {
                totalNegX++;
            }
        }
    }

    if (totalPosS > totalNegS) {
        A = 1;
    }

    if (totalPosX > totalNegX) {
        B = 1;
    }

    cout << "A: " << A << endl;
    cout << "B: " << B << endl;

    return 0;
}