# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mzangaro <mzangaro@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/08/12 14:34:58 by mzangaro          #+#    #+#              #
#    Updated: 2026/08/17 02:52:35 by mzangaro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME     = megaphone

CXX      = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRC      = megaphone.cpp

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