// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Account.class.cpp                                  :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/07 07:41:48 by ngoguey           #+#    #+#             //
//   Updated: 2015/04/07 08:25:25 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <iostream>
#include <ctime>
#include "Account.class.hpp"

// * STATICS **************************************************************** //
int							Account::_nbAccounts = 0;
int							Account::_totalAmount = 0;
int							Account::_totalNbDeposits = 0;
int							Account::_totalNbWithdrawals = 0;
void						Account::_displayTimestamp(void)
{
	time_t		t = time(NULL);
	char		buf[100];
	size_t		s;
	std::string	buf2;

	s = strftime(buf, 100, "%Y%m%d_%H%I%M", localtime(&t));
	buf2.assign(buf, s);
	std::cout << '[' << buf2 << ']';
	// std::cout << "[20150406_153629]";
	return ;
}
int							Account::getNbAccounts(void)
{
	return (Account::_nbAccounts);
}
int							Account::getTotalAmount(void)
{
	return (Account::_totalAmount);
}
int							Account::getNbDeposits(void)
{
	return (Account::_totalNbDeposits);
}
int							Account::getNbWithdrawals(void)
{
	return (Account::_totalNbWithdrawals);
}
void						Account::displayAccountsInfos(void)
{
	Account::_displayTimestamp();
	std::cout << " accounts:" << Account::getNbAccounts() <<
		";total:" << Account::getTotalAmount() <<
		";deposits:" << Account::getNbDeposits() <<
		";withdrawals:" << Account::getNbWithdrawals() <<
		std::endl;
	return ;
}


// * CONSTRUCTORS *********************************************************** //
Account::Account(int initial_deposit) :
	_accountIndex(Account::_nbAccounts++),
	_amount(initial_deposit),
	_nbDeposits(0),
	_nbWithdrawals(0)
{
	Account::_displayTimestamp();
	std::cout << " index:" << this->_accountIndex <<
		";amount:" << initial_deposit <<
		";created" << std::endl;
	Account::_totalAmount += initial_deposit;	
	return ;
}

// * DESTRUCTORS ************************************************************ //
Account::~Account()
{
	Account::_displayTimestamp();
	std::cout << " index:" << this->_accountIndex <<
		";amount:" << this->_amount <<
		";closed" << std::endl;
	return ;
}

// * OPERATORS ************************************************************** //
// * GETTERS **************************************************************** //
// * SETTERS **************************************************************** //
// * MEMBER FUNCTIONS / METHODS ********************************************* //
void						Account::makeDeposit(int deposit)
{
	Account::_displayTimestamp();
	std::cout << " index:" << this->_accountIndex <<
		";p_amount:" << this->_amount <<
		";deposit:" << deposit;
	this->_nbDeposits++;
	Account::_totalNbDeposits++;
	this->_amount += deposit;
	Account::_totalAmount += deposit;
	std::cout << ";amount:" << this->_amount <<
		";nb_deposits:" << this->_nbDeposits << std::endl;
	return ;
}
bool						Account::makeWithdrawal(int withdrawal)
{
	Account::_displayTimestamp();
	std::cout << " index:" << this->_accountIndex <<
		";p_amount:" << this->_amount <<
		";withdrawal:";
	if (withdrawal > this->_amount)
	{
		std::cout << "refused" << std::endl;
		return (false);
	}
	this->_nbWithdrawals++;
	Account::_totalNbWithdrawals++;
	this->_amount -= withdrawal;
	Account::_totalAmount -= withdrawal;
	std::cout << withdrawal <<
		";amount:" << this->_amount <<
		";nb_withdrawals:" << this->_nbWithdrawals << std::endl;
	return (true);
}
int							Account::checkAmount(void) const
{
	return (this->_amount);
}
void						Account::displayStatus(void) const
{
	Account::_displayTimestamp();
	std::cout << " index:" << this->_accountIndex <<
		";amount:" << this->_amount <<
		";deposits:" << this->_nbDeposits <<
		";withdrawals:" << this->_nbWithdrawals << std::endl;
	return ;
}


// * NESTED_CLASSES ********************************************************* //
