#include "header.hpp"
#include "PhoneBook.class.hpp"

PhoneBook::PhoneBook() {};
PhoneBook::~PhoneBook() {};

std::string PhoneBook::getFirstName() {
    return _firstName;
}

std::string PhoneBook::getLastName() {
    return _lastName;
}

std::string PhoneBook::getNickName() {
    return _nickName;
}

std::string PhoneBook::getLogin() {
    return _login;
}

std::string PhoneBook::getPostalAddress() {
    return _postalAddress;
}

std::string PhoneBook::getEmailAddress() {
    return _emailAddress;
}

std::string PhoneBook::getPhoneNumber() {
    return _phoneNumber;
}

std::string PhoneBook::getBirthDate() {
    return _birthDate;
}

std::string PhoneBook::getFavouriteMeal() {
    return _favouriteMeal;
}

std::string PhoneBook::getUnderwearColour() {
    return _underwearColour;
}

std::string PhoneBook::getDarkestSecret() {
    return _darkestSecret;
}

void PhoneBook::addContact() {
    std::cout << "Alright darling, may I have your...\n"LOVE"First Name"HATE": ";
    getline(std::cin, _firstName);
    std::cout << LOVE"Last Name"HATE": ";
    getline(std::cin, _lastName);
    std::cout << LOVE"Nickname"HATE": ";
    getline(std::cin, _nickName);
    std::cout << LOVE"Login"HATE": ";
    getline(std::cin, _login);
    std::cout << LOVE"Postal Address"HATE": ";
    getline(std::cin, _postalAddress);
    std::cout << LOVE"E-mail Address"HATE": ";
    getline(std::cin, _emailAddress);
    std::cout << LOVE"Phone Number"HATE": ";
    getline(std::cin, _phoneNumber);
    std::cout << LOVE"Birthdate"HATE": ";
    getline(std::cin, _birthDate);
    std::cout << LOVE"Favourite Meal"HATE": ";
    getline(std::cin, _favouriteMeal);
    std::cout << LOVE"Underwear Colour"HATE": ";
    getline(std::cin, _underwearColour);
    std::cout << LOVE"Deepest, "BOLD"DARKEST"HATE LOVE" Secret ;) "HATE;
    getline(std::cin, _darkestSecret);
    if (std::cin.eof()) {
        std::cerr << "\nUnexpected EOF during entry, terminating program :(" << std::endl;
        return;
    }
    std::cout << "The lovely "LOVE << getFirstName() << " " << getLastName() << HATE"'s contact information has been saved into the book "LOVE"<3"HATE << std::endl;
};
