/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakotu <hakotu@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 17:40:19 by hakotu            #+#    #+#             */
/*   Updated: 2025/12/26 17:41:40 by hakotu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>
#include <string>
class Brain
{
private:
    std::string ideas[100];
public:
    Brain();
    Brain(const Brain &copy);
    Brain& operator=(const Brain &c);
    ~Brain();
    void setIdea(int index, const std::string& idea);
    std::string getIdea(int index) const;
};
#endif  