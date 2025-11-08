/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakotu <hakotu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 14:40:02 by hakotu            #+#    #+#             */
/*   Updated: 2025/07/06 15:42:54 by hakotu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"


PhoneBook::PhoneBook() 
{
    this->index = 0;
    this->consts = 0;
}

int PhoneBook::add()
{
    Contact newContact;

    while (true)
    {
        if (!newContact.set_first_name())
        {
            std::cout << "Input stream closed. Exiting." << std::endl;
            return 1;
        }
        if (!newContact.get_first_name().empty())
            break;
    }

    while (true)
    {
        if (!newContact.set_last_name())
        {
            std::cout << "Input stream closed. Exiting." << std::endl;
            return 1;
        }
        if (!newContact.get_last_name().empty())
            break;
    }

    do {
        if (!newContact.set_nick_name())
        {
            std::cout << "Input stream closed. Exiting." << std::endl;
            return 1;
        }
    } while (newContact.get_nick_name().empty());

    do {
        if (!newContact.set_phone_number())
        {
            std::cout << "Input stream closed. Exiting." << std::endl;
            return 1;
        }
    } while (newContact.get_phone_number().empty());
  
    do {
        if (!newContact.set_darkest_secret())
        {
            std::cout << "Input stream closed. Exiting." << std::endl;
            return 1;
        }
    } while (newContact.get_darkest_secret().empty());

    this->ContactArry[this->index] = newContact;
    this->index = (this->index + 1) % 8;
    if (this->consts < 8)
        this->consts++;
    std::cout << "Contact added." << std::endl;
    return 0;
}

std::string set_format(std::string str)
{
    if (str.length() > 10)
        return str.substr(0, 9) + ".";
    else
        return str;
}

int PhoneBook::search()
{
    std::string input;
    int i;
    int idx;
    if (this->consts == 0)
    {
        std::cout << "No contacts to display" << std::endl;
        return 1;
    }
    std::cout << "|-------------------------------------------|" << std::endl;
    std::cout << "|   Index  |First Name| Last Name| Nick Name|" << std::endl;
    std::cout << "|-------------------------------------------|" << std::endl;
    for (int i = 0; i < this->consts; i++)
    {
        std::cout << "|" << std::setw(10) << i
                  << "|" << std::setw(10) << set_format(this->ContactArry[i].get_first_name())
                  << "|" << std::setw(10) << set_format(this->ContactArry[i].get_last_name())
                  << "|" << std::setw(10) << set_format(this->ContactArry[i].get_nick_name())
                  << "|" << std::endl;
    }
    std::cout << "|-------------------------------------------|" << std::endl;
    while (true)
    {
         std::cout << "Enter index of the contact to display (-1 to exit): ";
        std::getline(std::cin, input);
        if (input.empty())
        {
            std::cout << "Input cannot be empty." << std::endl;
            continue;
        }
        if (input == "-1")
            break;
        i = input[0] - '0';
        idx = i;
        if (idx == -1)
            break;
        if (idx >= 0 && idx < this->consts && !this->ContactArry[idx].get_first_name().empty())
        {
            std::cout << "First Name: " << this->ContactArry[idx].get_first_name() << std::endl;
            std::cout << "Last Name: " << this->ContactArry[idx].get_last_name() << std::endl;
            std::cout << "Nick Name: " << this->ContactArry[idx].get_nick_name() << std::endl;
            std::cout << "Phone Number: " << this->ContactArry[idx].get_phone_number() << std::endl;
            std::cout << "Darkest Secret: " << this->ContactArry[idx].get_darkest_secret() << std::endl;
            break;
        }
        else
        {
            std::cout << "Invalid index or empty contact. Please try again." << std::endl;
        }
    }    
    return 0;
    
}

int PhoneBook::exit()
{
    std::cout << "See you later" << std::endl;
    return (0);
}