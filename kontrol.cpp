#include <iostream>
#include <string>

using namespace std;

struct Book {
    string title;
    string author;
    int year;
    int copies;
};

void sortBooks(Book* books, int numBooks) {
    for (int i = 0; i < numBooks - 1; i++) {
        for (int j = 0; j < numBooks - i - 1; j++) {
            if (books[j].title > books[j + 1].title) {
                Book temp = books[j];
                books[j] = books[j + 1];
                books[j + 1] = temp;
            }
        }
    }
}

int main() {
    int numBooks;
    cout << "Введите количество книг в библиотеке: ";
    cin >> numBooks;

    Book* books = new Book[numBooks];

    for (int i = 0; i < numBooks; i++) {
        cout << "Введите название книги " << i + 1 << ": ";
        cin >> books[i].title;
        cout << "Введите автора книги " << i + 1 << ": ";
        cin >> books[i].author;
        cout << "Введите год издания книги " << i + 1 << ": ";
        cin >> books[i].year;
        cout << "Введите количество копий книги " << i + 1 << ": ";
        cin >> books[i].copies;
    }

    sortBooks(books, numBooks);

    cout << "Отсортированный список книг:" << endl;
    for (int i = 0; i < numBooks; i++) {
        cout << i + 1 << " " << books[i].title << " - Автор: " << books[i].author << ", год издания: " << books[i].year << ", количество копий: " << books[i].copies << endl;
    }

    delete[] books;

    return 0;
}

