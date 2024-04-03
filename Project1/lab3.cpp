//#include <iostream>
//#include <string>
//
//using namespace std;
//
//struct WORKER { // Создали структуру WORKER в которой содержится 2 переменные типа string и 1 переменная типа int
//    string name;
//    string position;
//    int year;
//};
//
//int main() {
//    setlocale(0, "");//Подключили русский язык
//
//    WORKER workers[] = { // Создали массив workers и записали в переменные структуры значения
//        {"Ivanov I.I.", "Manager", 2010}, {"Petrov P.P.", "Programmer", 2015},
//        {"Sidorov S.S.", "Accountant", 2018}, {"Vasiliev V.V.", "Designer", 2020},
//    };
//
//    const int SIZE = sizeof(workers) / sizeof(workers[0]); //Объявили константу SIZE для дальнейшего перебора структуры
//    int years; // Объявили переменную years
//
//    cout << "Введите количество лет стажа для поиска: ";
//    cin >> years; 
//
//    cout << "Работники со стажем более " << years << " лет:" << endl;
//    for (int i = 0; i < SIZE; i++) {
//        if ((2024 - workers[i].year) > years) { //В условии задаем год настоящего времени и выводим работника если он попадает под это условие
//            cout << workers[i].name << endl;
//        }
//        else {
//            cout << "Такого старого работника нет =(" << endl;
//            break;
//        }
//    }
//
//    return 0; 
//}