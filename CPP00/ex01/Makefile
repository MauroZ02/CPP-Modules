# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mzangaro <mzangaro@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/08/12 15:07:02 by mzangaro          #+#    #+#              #
#    Updated: 2026/08/17 02:51:50 by mzangaro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME     = phonebook

CXX      = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRC      = Contact.cpp PhoneBook.cpp main.cpp

OBJ      = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
