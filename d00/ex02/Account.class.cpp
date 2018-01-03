#include <iostream>
#include "Account.class.hpp"

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account( void ) {};

Account::Account( int initial_deposit ) {
    _accountIndex = _nbAccounts;
    _amount = initial_deposit;
    _nbDeposits = 0;
    _nbWithdrawals = 0;

    _totalAmount += initial_deposit;
    _nbAccounts += 1;

    _displayTimestamp();
    std::cout
    << "index:" << _accountIndex
    << ";amount:" << _amount
    << ";created"
    << std::endl;
};

Account::~Account( void ) {
    _displayTimestamp();
    std::cout
    << "index:" << _accountIndex
    << ";amount:" << _amount
    << ";closed"
    << std::endl;
};

int  Account::getNbAccounts( void ) {
    return _nbAccounts;
};

int  Account::getTotalAmount( void ) {
    return _totalAmount;
};

int  Account::getNbDeposits( void ) {
    return _totalNbDeposits;
};

int  Account::getNbWithdrawals( void ) {
    return _totalNbWithdrawals;
};

void Account::displayAccountsInfos( void ) {
    _displayTimestamp();
    std::cout
    << "accounts:" <<_nbAccounts
    << ";total:" << _totalAmount
    << ";deposits:" << _totalNbDeposits
    << ";withdrawals:" << _totalNbWithdrawals
    << std::endl;
};


void    Account::makeDeposit( int deposit ) {
    _amount += deposit;
    _nbDeposits += 1;

    _totalAmount += deposit;
    _totalNbDeposits += 1;

    _displayTimestamp();
    std::cout
    << "index:" << _accountIndex
    << ";p_amount:" << _amount - deposit
    << ";deposit:" << deposit
    << ";amount:" << _amount
    << ";nb_deposits:" << _nbDeposits
    << std::endl;
};

bool    Account::makeWithdrawal( int withdrawal ) {
    if (withdrawal <= _amount) {
        _amount -= withdrawal;
        _nbWithdrawals += 1;

        _totalAmount -= withdrawal;
        _totalNbWithdrawals += 1;

        _displayTimestamp();
        std::cout
        << "index:" << _accountIndex
        << ";p_amount:" << _amount + withdrawal
        << ";withdrawal:" << withdrawal
        << ";amount:" << _amount
        << ";nb_withdrawals:" << _nbWithdrawals
        << std::endl;

        return true;
    } else {
        _displayTimestamp();
        std::cout
        << "index:" << _accountIndex
        << ";p_amount:" << _amount
        << ";withdrawal:refused"
        << std::endl;

        return false;
    }
};

int     Account::checkAmount( void ) const {
    return _amount;
};

void    Account::displayStatus( void ) const {
    _displayTimestamp();
    std::cout
    << "index:" << _accountIndex
    << ";amount:" << _amount
    << ";deposits:" << _nbDeposits
    << ";withdrawals:" << _nbWithdrawals
    << std::endl;
};

void Account::_displayTimestamp( void ) {

    // To better match the provided log
    std::cout << "[20150406_153629] ";

    // Actual timestamp, to a certain degree
    /*
    time_t t = time(0);
    struct tm *now = localtime( &t );
    std::cout << '[' << (now->tm_year + 1897)
    << std::setw(2) << std::setfill('0') << (now->tm_mon + 1)
    << std::setw(2) << std::setfill('0') << now->tm_mday
    << '_'
    << std::setw(2) << std::setfill('0') << now->tm_hour
    << std::setw(2) << std::setfill('0') << now->tm_min
    << std::setw(2) << std::setfill('0') << now->tm_sec << "] ";
    */
};
