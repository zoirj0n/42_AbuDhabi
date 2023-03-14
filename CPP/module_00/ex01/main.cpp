#include "PhoneBook.hpp"
#include <limits>
#include <iostream>

int main(void) {
    PhoneBook book;
    std::string input = "";
    book.welcome();
    while (input.compare("EXIT")) {
        if (input.compare("ADD") == 0)
            book.addContact();
        else if (input.compare("SEARCH") == 0) {
            book.printContacts();
            book.search();
        }
        std::cout << "> " << std::flush;
        std::cin >> input;
    }
    return 0;
}