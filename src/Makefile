tezt:
	gcc -g -Wextra -Wall -Werror *.c -lm
	cppcheck *.c
	python3 ../linters/cpplint.py --extensions=c *.c
	valgrind --leak-check=full --track-origins=yes --show-leak-kinds=all -q ./a.out

teztmac: clean
	gcc -Wextra -Wall -Werror *.c  -lm
	cppcheck *.c
	python3 ../linters/cpplint.py --extensions=c *.c
	leaks -quiet -atExit -- ./a.out > test.log
	grep -e "0 total leaked bytes" -e "nodes malloced" -e "leaks Report Version" -v test.log

tezt_risky:
	gcc *.c -lm
	cppcheck *.c
	python3 ../linters/cpplint.py --extensions=c *.c
	valgrind --leak-check=yes -q ./a.out

make gitaboba:
	git add s21_decimal.c s21_decimal.h Makefile
	git commit -m "sharkmer: decimal aboba update"
	git push origin aboba

clean:
	rm -f test *.gc* test.info log.xml test.log leak.log
	rm -f -rf report
