//#include <iostream>
//#include <string>
//
//using namespace std;
//
//struct WORKER { // ������� ��������� WORKER � ������� ���������� 2 ���������� ���� string � 1 ���������� ���� int
//    string name;
//    string position;
//    int year;
//};
//
//int main() {
//    setlocale(0, "");//���������� ������� ����
//
//    WORKER workers[] = { // ������� ������ workers � �������� � ���������� ��������� ��������
//        {"Ivanov I.I.", "Manager", 2010}, {"Petrov P.P.", "Programmer", 2015},
//        {"Sidorov S.S.", "Accountant", 2018}, {"Vasiliev V.V.", "Designer", 2020},
//    };
//
//    const int SIZE = sizeof(workers) / sizeof(workers[0]); //�������� ��������� SIZE ��� ����������� �������� ���������
//    int years; // �������� ���������� years
//
//    cout << "������� ���������� ��� ����� ��� ������: ";
//    cin >> years; 
//
//    cout << "��������� �� ������ ����� " << years << " ���:" << endl;
//    for (int i = 0; i < SIZE; i++) {
//        if ((2024 - workers[i].year) > years) { //� ������� ������ ��� ���������� ������� � ������� ��������� ���� �� �������� ��� ��� �������
//            cout << workers[i].name << endl;
//        }
//        else {
//            cout << "������ ������� ��������� ��� =(" << endl;
//            break;
//        }
//    }
//
//    return 0; 
//}