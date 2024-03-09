#include <iostream>
#include "Library.h"
#include <clocale>

int main() {
    std::setlocale(LC_ALL, "Polish");

    Library library;

    // Dodanie kilku ksi��ek
    library.addBook(Book("Harry Potter", "J.K. Rowling", "123"));
    library.addBook(Book("The Hobbit", "J.R.R. Tolkien", "456"));
    library.addBook(Book("1984", "George Orwell", "789"));

    // Wy�wietlenie dost�pnych ksi��ek
    std::cout << "Dost�pne ksi��ki:" << std::endl;
    library.displayBooks();

    // Utworzenie kilku czytelnik�w
    std::string userName;
    std::cout << "Podaj swoje imi�: ";
    std::cin >> userName;
    Member member(userName);

    // Wypo�yczenie ksi��ek
    std::string isbn;
    std::cout << "Podaj numer ISBN ksi��ki do wypo�yczenia: ";
    std::cin >> isbn;
    library.borrowBook(member, isbn);

    // Wy�wietlenie dost�pnych ksi��ek po wypo�yczeniu
    std::cout << "Dost�pne ksi��ki po wypo�yczeniu:" << std::endl;
    library.displayBooks();

    // Zwrot ksi��ek
    std::cout << "Podaj numer ISBN ksi��ki do zwrotu: ";
    std::cin >> isbn;
    library.returnBook(member, isbn);

    // Wy�wietlenie dost�pnych ksi��ek po zwrocie
    std::cout << "Dost�pne ksi��ki po zwrocie:" << std::endl;
    library.displayBooks();

    // Wy�wietlenie liczby wypo�yczonych ksi��ek
    std::cout << userName << "Liczba wypo�yczonych ksi��ek: " << (-(32 -library.countBorrowedBooks())) << std::endl;

    return 0;
}
