##
## EPITECH PROJECT, 2023
## makefile
## File description:
## aa
##

SRC =	src/main.c	\
		src/converter.c	\
		src/handling_palindrome.c	\
		src/option_handler.c	\
		src/tools.c	\

TESTSRC =	tests/tester.c	\
			src/converter.c	\
			src/handling_palindrome.c	\
			src/option_handler.c	\
			src/tools.c	\

OBJ =	$(SRC:.c=.o)

CFLAGS =	-I ./include

CFLAGS =	-W -Wall -Wextra -g3

NAME =	palindrome

TESTNAME =	unit_tests

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) $(CFLAGS)
	@rm -rf $(OBJ)

re:	fclean all

clean:
	rm -f $(OBJ)
	rm -f *.gcda
	rm -f *.gcno

fclean: clean
	rm -f $(NAME)
	rm -f $(TESTNAME)

unit_tests:
	gcc -o $(TESTNAME) $(TESTSRC) --coverage -lcriterion

tests_run: unit_tests
	./unit_tests
