#ifndef PHONEBOOK_CLASS_HPP
# define PHONEBOOK_CLASS_HPP

# include <string>
# include <iostream>

class PhoneBook {
    std::string firstName;
    std::string lastName;
    std::string nickName;
    std::string login;
    std::string postalAddress;
    std::string emailAddress;
    std::string phoneNumber;
    std::string birthDate;
    std::string favouriteMeal;
    std::string underwearColour;
    std::string darkestSecret;

public:
    PhoneBook();
    ~PhoneBook();
    void addContact();

    std::string getFirstName();
    std::string getLastName();
    std::string getNickName();
    std::string getLogin();
    std::string getPostalAddress();
    std::string getEmailAddress();
    std::string getPhoneNumber();
    std::string getBirthDate();
    std::string getFavouriteMeal();
    std::string getUnderwearColour();
    std::string getDarkestSecret();
};

#endif