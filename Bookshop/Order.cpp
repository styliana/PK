#include "Order.h"
#include <iostream>

Order::Order(const std::string& book_titles, int quantity) : book_titles(book_titles), quantity(quantity) {}

Order::Order() : quantity(0) {} // Implementacja domy�lnego konstruktora

Order& Order::operator+=(const Book& book) {
    books.push_back(book);
    return *this;
}

void Order::add_order() {
    std::string answer;
    std::cout << "Czy chcesz doda� ksi��k� do zam�wienia? (yes/no): " << std::endl;
    std::cin >> answer;
    while (answer == "yes" || answer == "YES") {
        // Pytanie u�ytkownika o numer ksi��ki
        int bookIndex;
        std::cout << "Podaj numer indeksu ksi��ki, kt�r� chcesz doda� do zam�wienia: ";
        std::cin >> bookIndex;
        if (bookIndex >= 1 && bookIndex <= 3) {
            *this += books[bookIndex - 1]; // U�ywamy operatora += dla bie��cego obiektu Order
        }
        else {
            std::cout << "Nieprawid�owy numer indeksu. Wybierz ponownie." << std::endl;
        }
        std::cout << "Czy chcesz doda� kolejn� ksi��k� do zam�wienia? (yes/no): ";
        std::cin >> answer;
    }
}

void Order::getOrder() const {
    std::cout << "Ksi��ki w zam�wieniu:" << std::endl;
    for (const auto& book : books) {
        std::cout << "\t" << book.title << std::endl; 
    }
}

int Order::calculate_total_price() const {
    int total_price = 0;
    for (const auto& book : books) {
        total_price += book.price;
    }
    if (total_price < 100) {
        std::cout << "Dodalismy 20$ za dostaw�, poniewa� twoje zam�wienie nie przekroczy�o 100$." << std::endl;
        return total_price+20;
    }
    else {
        return total_price;
    }

}
