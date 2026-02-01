/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakotu <hakotu@student.42istanbul.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 15:45:12 by hakotu            #+#    #+#             */
/*   Updated: 2025/07/06 13:50:08 by hakotu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

bool Contact::set_first_name()
{
    std::cout << "Enter First Name:" << std::endl;
    std::getline(std::cin, FirstName);
    if (std::cin.eof())
        return false;
    for (size_t i = 0; i < FirstName.length(); ++i)
    {
        if (!isalpha(FirstName[i]))
        {
            std::cout << "First Name must contain only letters!" << std::endl;
            FirstName.clear();
            return true;
        }
    }
    return true;
}

bool Contact::set_last_name()
{
    std::cout << "Enter Last Name:" << std::endl;
    std::getline(std::cin, LastName);
    if (std::cin.eof())
        return false;
    for (size_t i = 0; i < LastName.length(); ++i)
    {
        if (!isalpha(LastName[i]))
        {
            std::cout << "Last Name must contain only letters!" << std::endl;
            LastName.clear();
            return true;
        }
    }
    return true;
}

bool Contact::set_nick_name()
{
    std::cout << "Enter Nick Name:" << std::endl;
    std::getline(std::cin, NickName);
    if (std::cin.eof())
        return false;
    return true;
}

bool Contact::set_phone_number()
{
    std::cout << "Enter Phone Number:" << std::endl;
    std::getline(std::cin, PhoneNumber);
    if (std::cin.eof())
        return false;
    for (size_t i = 0; i < PhoneNumber.length(); ++i)
    {
        if (!isdigit(PhoneNumber[i]))
        {
            std::cout << "Phone number must contain only digits!" << std::endl;
            PhoneNumber.clear();
            return true;
        }
    }
    if (PhoneNumber.empty())
        return true;
    return true;
}

bool Contact::set_darkest_secret()
{
    std::cout << "Enter Darkest Secret:" << std::endl;
    std::getline(std::cin, DarkestSecret);
    if (std::cin.eof())
        return false;
    return true;
}

std::string Contact::get_first_name()
{
    return FirstName;
}

std::string Contact::get_last_name()
{
    return LastName;
}

std::string Contact::get_nick_name()
{
    return NickName;
}

std::string Contact::get_phone_number()
{
    return PhoneNumber;
}

std::string Contact::get_darkest_secret()
{
    return DarkestSecret;
}
