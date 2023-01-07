/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 12:42:11 by pmitsuko          #+#    #+#             */
/*   Updated: 2023/01/07 16:38:40 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
# include <iostream>
#include <ctime>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit)
{
	this->_accountIndex = Account::_nbAccounts;
	this->_amount = initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	Account::_nbAccounts++;
	this->_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount
		<< ";created" << std::endl;
	return ;
}

Account::~Account()
{
	this->_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount
		<< ";closed" << std::endl;
	return ;
}

void	Account::displayAccountsInfos( void )
{
	std::cout << "accounts:" << std::endl;
	return ;
}

void	Account::displayStatus( void ) const
{
	std::cout << "status:" << std::endl;
	return ;
}

void	Account::_displayTimestamp( void )
{
	time_t raw_time;
	tm * time_info;
	char date_string[100];

	time(&raw_time);
	time_info = localtime(&raw_time);
	strftime(date_string, 50, "%Y%m%d_%H%M%S", time_info);
	std::cout << "[" << date_string << "] ";
	return ;
}
