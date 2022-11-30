tezt:
	gcc -Wextra -Wall -Werror *.c  -lm
	cppcheck *.c
	python3 ../linters/cpplint.py --extensions=c *.c
	valgrind --leak-check=yes -q ./a.out

teztmac:
	gcc -Wextra -Wall -Werror *.c  -lm
	cppcheck *.c
	python3 ../linters/cpplint.py --extensions=c *.c
	./a.out

tezt_stat:
	gcc -Wextra -Wall -Werror *.c -lm
	cppcheck *.c
	python3 ../linters/cpplint.py --extensions=c *.c
	valgrind --tool=exp-sgcheck -q ./a.out

tezt_risky:
	gcc *.c -lm
	cppcheck *.c
	python3 ../linters/cpplint.py --extensions=c *.c
	valgrind --leak-check=yes -q ./a.out

make gitaboba:
	git add s21_decimal.c s21_decimal.h Makefile
	git commit -m "sharkmer: decimal aboba update"
	git push origin aboba