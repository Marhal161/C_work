#include <iostream>

using namespace std;

struct Book { // создали структуру Book с 2-м€ переменными типа int
    int pages;
    int chapters;
};

int main() {
    setlocale(0, "");
    //ќбъ€вл€ем переменные minPages, minChapters и заполн€ем их значени€ми 
    int minPages, minChapters;
    cout << "¬ведите минимальное количество страниц: ";
    cin >> minPages;
    cout << "¬ведите минимальное количество глав: ";
    cin >> minChapters;

    int count = 0; //создали временную переменную в которую будет записыватьс€ количество книг
    Book book; 
    while (true) { //«десь мы вводим с клавиотуры количество книг пока не вернутс€ значение false или же проще говор€ пока пользователь не введет -1
        cout << "¬ведите количество страниц книги (или -1 дл€ выхода): ";
        cin >> book.pages;
        if (book.pages == -1) break;
        cout << "¬ведите количество глав книги: ";
        cin >> book.chapters;
        if (book.pages > minPages && book.chapters > minChapters) count++;
    }

    cout << " оличество книг, удовлетвор€ющих условию: " << count << endl;
    return 0;
}