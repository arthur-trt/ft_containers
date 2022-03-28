/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_define.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 15:26:08 by atrouill          #+#    #+#             */
/*   Updated: 2022/03/28 10:45:41 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_DEFINE_HPP
# define TEST_DEFINE_HPP

# if DEBUG
	# include <iostream>
	# define debug(x)	do { std::cerr << __FILE__ << ":" << __PRETTY_FUNCTION__ << "(" << __LINE__ << "):" << x << std::endl; } while(0)
# else
	# define debug(x)	/* x */
# endif


# define RST			"\x1B[0m"

# define FRED(x)		"\x1B[31m" x RST
# define FGRN(x) 		"\x1B[32m" x RST
# define FYEL(x) 		"\x1B[33m" x RST
# define FBLU(x) 		"\x1B[34m" x RST
# define FMAG(x) 		"\x1B[35m" x RST
# define FCYN(x) 		"\x1B[36m" x RST
# define FWHT(x) 		"\x1B[37m" x RST

# define BOLD(x)		"\x1B[1m" x RST
# define UNDL(x)		"\x1B[4m" x RST
# define DIM(x)			"\033[2m" x RST

# define FG1(x)			"\033[4;30;33m" x RST
# define FG2(x)			"\033[4;32;40m" x RST
# define HEADER(x)		"\033[1;107;35m" x RST

# define CONTAINER_TEST(x)		FG2(BOLD(FCYN("/* ********************************** */")))					\
							<<	str_center(36,x)															\
							<<	FG2(BOLD(FCYN("/* ********************************** */")))					\
							<<	std::endl;

# define CATEGORY_TEST(x)		BOLD(FMAG("/======================================/"))		<< std::endl	\
							<<	BOLD(FMAG("/=")) << str_center(36, x) << BOLD(FMAG("=/"))	<< std::endl	\
							<<	BOLD(FMAG("/======================================/"))		<< std::endl;

# define TEST(x)				FGRN("~~~~~~~~~~~~~~~~~~~~")				<< std::endl					\
							<<	FGRN("~") << str_center(18, x) << FGRN("~")	<< std::endl					\
							<<	FGRN("~~~~~~~~~~~~~~~~~~~~") 				<< std::endl;

# define L_TEST(x)				FGRN("~") << str_center(18, x) << FGRN("~")	<< std::endl;

# define WAIT_USER				getwchar();

#endif
