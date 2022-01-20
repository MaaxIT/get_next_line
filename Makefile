BUFF_SIZE=23

all:
	gcc -Wall -Wextra -Werror -D BUFFER_SIZE=$(BUFF_SIZE) *.c && ./a.out

test:
	make --directory=gnlTester/ m