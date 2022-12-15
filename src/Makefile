teztmac: clean
	gcc -Wextra -Wall -Werror *.c  -lm
	cppcheck *.c *.h
	clang-format --style=Google -i *.c *.h
	./a.out

tezt: clean
	gcc -Wextra -Wall -Werror *.c  -lm
	cppcheck *.c *.h
	clang-format --style=Google -i *.c *.h
	valgrind --leak-check=full --track-origins=yes --show-leak-kinds=all -q ./a.out

cpplinth: clean
	python3 ../linters/cpplint.py *.h

tezt_risky: clean
	gcc *.c -lm
	cppcheck *.c
	python3 ../linters/cpplint.py --extensions=c *.c
	valgrind --leak-check=yes -q ./a.out

clean:
	rm -f test *.gc* test.info log.xml test.log leak.log *.out
	rm -f -rf report *.out.dSYM

	# leaks -quiet -atExit -- ./a.out > test.log
	# grep -e "0 total leaked bytes" -e "nodes malloced" -e "leaks Report Version" -v test.log