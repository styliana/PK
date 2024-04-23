#include <iostream>
#include <string>
#include "Book.h"
#include "Order.h"
#include <clocale>
#include <iomanip>

using namespace std;

int main() {
    //Polish znaki
    setlocale(LC_ALL, "");

    // Inicjalizacja ksi��ek
    Book books[3] = {
        Book("ABC", 45),
        Book("DEF", 10),
        Book("GHI", 22)
    };

    // Tworzenie zam�wienia
    Order order;

    // Wy�wietlanie dost�pnych ksi��ek z numerami indeks�w
    std::cout << "-----------------------" << std::endl;
    std::cout << "Nr   Tytu�      Cena" << std::endl;
    for (int i = 0; i < 3; ++i) {
        std::cout << i + 1 << ".   " << std::setw(10) << std::left << books[i].title << " " << std::setw(2) << books[i].price << " $" << std::endl;
    }
    std::cout << "-----------------------" << std::endl;

    string answer;
    cout << "Czy chcesz doda� ksi��k� do zam�wienia? (yes/no): " << endl;
    cin >> answer;
    while (answer == "yes" || answer == "YES") {

        // Pytanie u�ytkownika o numer ksi��ki
        int bookIndex;
        cout << "Podaj numer ksiazki, ktora chcesz dodac do zamowienia: ";
        cin >> bookIndex;

        // Dodanie odpowiedniej ksi��ki do zam�wienia na podstawie numeru indeksu
        if (bookIndex >= 1 && bookIndex <= 3) {
            order += books[bookIndex - 1];
        }
        else {
            cout << "Nieprawidlowy numer indeksu. Wybierz ponownie." << endl;
        }

        cout << "Czy chcesz doda� ksi��k� do zam�wienia? (yes/no): " << endl;
        cin >> answer;
    }

    std::cout << "-----------------------" << std::endl;
    // Wy�wietlanie zam�wienia po zako�czeniu sk�adania
    order.getOrder();
    std::cout << "-----------------------" << std::endl;
    // Wy�wietlanie ca�kowitego kosztu zam�wienia
    cout << "Ca�kowity koszt zam�wienia: " << order.calculate_total_price() << " $" << endl;

    return 0;
}

/* output

-----------------------
Nr   Tytu�      Cena
1.   ABC        45 $
2.   DEF        10 $
3.   GHI        22 $
-----------------------
Czy chcesz doda� ksi��k� do zam�wienia? (yes/no):
yes
Podaj numer ksiazki, ktora chcesz dodac do zamowienia: 1
Czy chcesz doda� ksi��k� do zam�wienia? (yes/no):
yes
Podaj numer ksiazki, ktora chcesz dodac do zamowienia: 3
Czy chcesz doda� ksi��k� do zam�wienia? (yes/no):
yes
Podaj numer ksiazki, ktora chcesz dodac do zamowienia: 2
Czy chcesz doda� ksi��k� do zam�wienia? (yes/no):
no
-----------------------
Ksi��ki w zam�wieniu:
        ABC
        GHI
        DEF
-----------------------
Dodalismy 20$ za dostaw�, poniewa� twoje zam�wienie nie przekroczy�o 100$.
Ca�kowity koszt zam�wienia: 97 $



A:\jipp2\Bookshop\x64\Debug\Bookshop.exe (proces 2436) zako�czono z kodem 0.
Naci�nij dowolny klawisz, aby zamkn�� to okno...
*/