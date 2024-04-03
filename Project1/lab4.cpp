#include <iostream>

using namespace std;

struct Book { // ������� ��������� Book � 2-�� ����������� ���� int
    int pages;
    int chapters;
};

int main() {
    setlocale(0, "");
    //��������� ���������� minPages, minChapters � ��������� �� ���������� 
    int minPages, minChapters;
    cout << "������� ����������� ���������� �������: ";
    cin >> minPages;
    cout << "������� ����������� ���������� ����: ";
    cin >> minChapters;

    int count = 0; //������� ��������� ���������� � ������� ����� ������������ ���������� ����
    Book book; 
    while (true) { //����� �� ������ � ���������� ���������� ���� ���� �� �������� �������� false ��� �� ����� ������ ���� ������������ �� ������ -1
        cout << "������� ���������� ������� ����� (��� -1 ��� ������): ";
        cin >> book.pages;
        if (book.pages == -1) break;
        cout << "������� ���������� ���� �����: ";
        cin >> book.chapters;
        if (book.pages > minPages && book.chapters > minChapters) count++;
    }

    cout << "���������� ����, ��������������� �������: " << count << endl;
    return 0;
}