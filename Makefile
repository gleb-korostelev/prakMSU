NAME = prak.a

FLAGS = -Wall -Wextra -Werror $(HDDIRS)

HDDIRS = -I prak/praklib.h inclucde/koollib/koolplot.h

SRCS = ./functions.cpp ./quick_sort.cpp ./Lagrange.cpp

OBJ = $(SRCS:.cpp=.o)

.PHONY: all clean fclean re

%o: %cpp
	g++ $(FLAGS) -c $< -o $(<:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)
	g++ main.cpp -I/usr/include/python3.8 -lpython3.8 prak.a

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)
	@rm -f a.out

re: fclean all