#include "header.hpp"
#include "PhoneBook.class.hpp"

PhoneBook::PhoneBook() {};
PhoneBook::~PhoneBook() {};

std::string PhoneBook::getFirstName() {
    return this->firstName;
}

std::string PhoneBook::getLastName() {
    return this->lastName;
}

std::string PhoneBook::getNickName() {
    return this->nickName;
}

std::string PhoneBook::getLogin() {
    return this->login;
}

std::string PhoneBook::getPostalAddress() {
    return this->postalAddress;
}

std::string PhoneBook::getEmailAddress() {
    return this->emailAddress;
}

std::string PhoneBook::getPhoneNumber() {
    return this->phoneNumber;
}

std::string PhoneBook::getBirthDate() {
    return this->birthDate;
}

std::string PhoneBook::getFavouriteMeal() {
    return this->favouriteMeal;
}

std::string PhoneBook::getUnderwearColour() {
    return this->underwearColour;
}

std::string PhoneBook::getDarkestSecret() {
    return this->darkestSecret;
}

void PhoneBook::addContact() {
    std::cout << "Alright darling, may I have your...\n"LOVE"First Name"HATE": ";
    getline(std::cin, this->firstName);
    std::cout << LOVE"Last Name"HATE": ";
    getline(std::cin, this->lastName);
    std::cout << LOVE"Nickname"HATE": ";
    getline(std::cin, this->nickName);
    std::cout << LOVE"Login"HATE": ";
    getline(std::cin, this->login);
    std::cout << LOVE"Postal Address"HATE": ";
    getline(std::cin, this->postalAddress);
    std::cout << LOVE"E-mail Address"HATE": ";
    getline(std::cin, this->emailAddress);
    std::cout << LOVE"Phone Number"HATE": ";
    getline(std::cin, this->phoneNumber);
    std::cout << LOVE"Birthdate"HATE": ";
    getline(std::cin, this->birthDate);
    std::cout << LOVE"Favourite Meal"HATE": ";
    getline(std::cin, this->favouriteMeal);
    std::cout << LOVE"Underwear Colour"HATE": ";
    getline(std::cin, this->underwearColour);
    std::cout << LOVE"Deepest, "BOLD"DARKEST"DIM" Secret ;) "HATE;
    getline(std::cin, this->darkestSecret);
    if (std::cin.eof()) {
        std::cerr << "\nUnexpected EOF during entry, terminating program :(" << std::endl;
        return;
    }
    std::cout << "The lovely "LOVE << this->getFirstName() << " " << this->getLastName() << HATE"'s contact information has been saved into the book "LOVE"<3"HATE << std::endl;
};
