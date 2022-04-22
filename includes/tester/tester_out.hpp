/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester_out.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 16:01:10 by atrouill          #+#    #+#             */
/*   Updated: 2022/04/21 12:26:59 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTER_OUT_HPP
# define TESTER_OUT_HPP

#include <iostream>

/* FOREGROUND */
#define BBOLD "\x1B[1m"
#define RST  "\x1B[0m"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"
#define KCYN  "\x1B[36m"
#define KWHT  "\x1B[37m"

#define FRED(x) KRED x RST
#define FGRN(x) KGRN x RST
#define FYEL(x) KYEL x RST
#define FBLU(x) KBLU x RST
#define FMAG(x) KMAG x RST
#define FCYN(x) KCYN x RST
#define FWHT(x) KWHT x RST

#define BOLD(x) "\x1B[1m" x RST
#define UNDL(x) "\x1B[4m" x RST
#define DIM(x)    "\033[2m" x RST

// "\033[{FORMAT_ATTRIBUTE};{BACKGROUND};{FOREGROUND}m{TEXT}\033[{RESET_FORMATE_ATTRIBUTE}m"
#define FG1(x)        "\033[4;30;33m" x RST
#define FG2(x)        "\033[4;32;40m" x RST
#define HEADER(x)    "\033[1;107;35m" x RST


#define out(x) std::cout << x << std::endl;
// The class

template <typename T, typename U>
void display(ft::map<T, U> &my_map, std::map<T, U> &r_map)
{
    std::cout << BOLD("-> output : ") << std::endl;
    std::cout << FG1("Mine :") << std::endl;
    typename ft::map<T, U>::iterator it1;
    for (it1 = my_map.begin(); it1 != my_map.end(); it1++)
        std::cout << *it1 << " ";
    std::cout << std::endl;

    std::cout << FG2("Real :") << std::endl;
    typename std::map<T, U>::iterator it;
    for (it = r_map.begin(); it != r_map.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;
    std::cout << DIM("Real size : ") << r_map.size() << DIM(" VS my size : ") << my_map.size() << std::endl;
}

/*
**  OVERLOAD <<
**    @brief overloading pair so it is seen as key/value
*/
template <typename T, typename U>
std::ostream& operator<<(std::ostream& os, ft::pair<T, U>& pair)
{
    if (&pair != NULL)
    {
        os << "[" << pair.first << "]=\"" << pair.second << "\"";
    }
    return os;
}

template <typename T, typename U>
std::ostream& operator<<(std::ostream& os, const ft::pair<T, U>& pair)
{
    if (&pair != NULL)
    {
        os << "[" << pair.first << "]=\"" << pair.second << "\"";
    }
    return os;
}

// A ENLEVER TEST POUR AFFICHER STD PAREIL 
template <typename T, typename U>
std::ostream& operator<<(std::ostream& os, const std::pair<T, U>& pair)
{
    if (&pair != NULL)
    {
        os << "[" << pair.first << "]=\"" << pair.second << "\"";
    }
    return os;
}
struct my_out
{
	my_out(std::ostream& out1, std::ostream& out2) : out1_(out1), out2_(out2) {}

	std::ostream& out1_;
	std::ostream& out2_;

};

// operator<<() function for most data types.
template <typename T>
my_out& operator<<(my_out& mo, T const& t)
{
	mo.out1_ << t;
	mo.out2_ << t;
	return mo;
}

my_out& operator<<(my_out& mo, std::ostream&(*f)(std::ostream&));

#endif
