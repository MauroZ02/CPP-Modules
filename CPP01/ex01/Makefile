# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mzangaro <mzangaro@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/08/19 01:13:12 by mzangaro          #+#    #+#              #
#    Updated: 2026/08/19 01:32:44 by mzangaro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = zombiehorde

CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = Zombie.cpp zombieHorde.cpp main.cpp

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

%.o:%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re