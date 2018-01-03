#ifndef PHONEBOOK_CLASS_HPP
# define PHONEBOOK_CLASS_HPP

# include <string>
# include <iostream>

class PhoneBook {
    std::string _firstName;
    std::string _lastName;
    std::string _nickName;
    std::string _login;
    std::string _postalAddress;
    std::string _emailAddress;
    std::string _phoneNumber;
    std::string _birthDate;
    std::string _favouriteMeal;
    std::string _underwearColour;
    std::string _darkestSecret;

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