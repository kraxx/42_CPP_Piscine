#include "header.hpp"

void greet() {
    std::cout << "Hello baby ;)\nWould you like to "
    LOVE"ADD"HATE", "
    LOVE"SEARCH"HATE", or "
    LOVE"EXIT"HATE << std::endl;    
}

void salute() {
    std::cout << "\nCheers darling "LOVE"<3"HATE << std::endl;
}

void printListing(int n, PhoneBook phonebook[]) {
    std::string firstName, lastName, nickName;
    std::cout << "     Index|First Name| Last Name|  Nickname" << std::endl;
    std::cout << "----------|----------|----------|----------\n";
    for (int i = 0; i < n; i++) {
        firstName = phonebook[i].getFirstName();
        lastName = phonebook[i].getLastName();
        nickName = phonebook[i].getNickName();
        if (firstName.size() > 10) {
            firstName.replace(9, firstName.size() - 9, ".");
        }
        if (lastName.size() > 10) {
            lastName.replace(9, lastName.size() - 9, ".");
        }
        if (nickName.size() > 10) {
            nickName.replace(9, nickName.size() - 9, ".");
        }
        std::cout << std::setw(10) << i << "|";
        std::cout << std::setw(10) << firstName << "|";
        std::cout << std::setw(10) << lastName << "|";
        std::cout << std::setw(10) << nickName << std::endl;
    }
}

void printEntry(int i, PhoneBook phonebook) {
    std::cout << LOVE"The dirty deets on entry "HATE << i << ":" << std::endl
    << "First Name: " << phonebook.getFirstName() << std::endl
    << "Last Name: " << phonebook.getLastName() << std::endl
    << "Nickname: " << phonebook.getNickName() << std::endl
    << "Login: " << phonebook.getLogin() << std::endl
    << "Postal Address: " << phonebook.getPostalAddress() << std::endl
    << "E-mail Address: " << phonebook.getEmailAddress() << std::endl
    << "Phone Number: " << phonebook.getPhoneNumber() << std::endl
    << "Birthdate: " << phonebook.getBirthDate() << std::endl
    << "Favourite Meal: " << phonebook.getFavouriteMeal() << std::endl
    << "Underwear Colour: " << phonebook.getUnderwearColour() << std::endl
    << "Deepest, Darkest Secret: " << phonebook.getDarkestSecret() << std::endl;
}

void searchBook(int n, PhoneBook phonebook[]) {
    int i;
    printListing(n, phonebook);
    std::cout << "Who would you like more juice on? Enter index "LOVE"[0-" << n - 1 << "]"HATE" ~~> ";
    std::cin >> i;
    if (std::cin.eof()) {
        std::cerr << "\nPlease do not enter EOF~~" << std::endl;
        return;
    } else if (std::cin.fail() || i >= n) {
        std::cout << "Whoopsie. That's not a valid entry." << std::endl;
    } else {
        printEntry(i, phonebook[i]);
    }
}

int main() {
    int         i = 0;
    PhoneBook   phonebook[MAX_CONTACTS];
    std::string buf;

    greet();
    while (1) {
        std::cout << LOVE"<3 "HATE;
        getline(std::cin, buf);
        if (buf == "EXIT" || std::cin.eof()) {
            break;
        } else if (buf == "ADD") {
            if (i < MAX_CONTACTS) {
                phonebook[i].addContact();
                i++;
            } else {
                std::cout << "Sorry babe, book's full "LOVE"</3"HATE"\n";
            }
        } else if (buf == "SEARCH") {
            if (i > 0) {
                searchBook(i, phonebook);
            } else {
                std::cout << "Book's empty, please fill me with "LOVE"ADD"HATE".\n";
            }
        }
    }
    salute();
    return 0;
}