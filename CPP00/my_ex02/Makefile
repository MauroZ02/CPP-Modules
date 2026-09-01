# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mzangaro <mzangaro@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/08/15 14:58:50 by mzangaro          #+#    #+#              #
#    Updated: 2026/08/17 02:31:51 by mzangaro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME     = account

CXX      = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRC      = Account.cpp tests.cpp

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