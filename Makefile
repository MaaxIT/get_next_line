BUFF_SIZE=23

all:
	gcc -Wall -Wextra -Werror -D BUFFER_SIZE=$(BUFF_SIZE) *.c && ./a.out

test:
	if cd gnlTester; then git pull; else git clone https://github.com/Tripouille/gnlTester gnlTester; fi
	make --directory=gnlTester/ m