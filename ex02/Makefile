NAME= exec

CC= c++
CFLAGS= -Wall -Wextra -Werror -std=c++98
RM= rm -rf

SRCS= Fixed.cpp main.cpp

OBJS=$(SRCS:.cpp=.o)

all:$(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp Fixed.hpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean:
	$(RM) $(OBJS) $(NAME)

re:
	make fclean
	make all

.PHONY: all clean fclean re
