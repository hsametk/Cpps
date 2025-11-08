/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakotu <hakotu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 17:50:43 by hakotu            #+#    #+#             */
/*   Updated: 2025/07/03 15:52:11 by hakotu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>
#include <iostream>

class Contact
{
private:
    std::string FirstName;
    std::string LastName;
    std::string NickName;
    std::string PhoneNumber; 
    std::string DarkestSecret;
    
public:
    bool set_first_name();
    bool set_last_name();
    bool set_nick_name();
    bool set_phone_number();
    bool set_darkest_secret();

    std::string get_first_name();
    std::string get_last_name();
    std::string get_nick_name();
    std::string get_phone_number();
    std::string get_darkest_secret();
};

#endif