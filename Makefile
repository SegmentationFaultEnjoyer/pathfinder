NAME = pathfinder

SRCS = src/*.c

LIB = libmx/libmx.a

CFLAGS = -std=c11 -Wall -Wextra -Werror -Wpedantic 

all: install clean

install:
	@make -C libmx/
	@clang $(CFLAGS) $(SRCS) $(LIB) -o $(NAME)

uninstall:
	@rm -rf $(NAME)

clean:
	@rm -rf $(LIB)	

reinstall:
	@make uninstall
	@make
