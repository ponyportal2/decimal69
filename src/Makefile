tezt: clean
	gcc -Wextra -Wall -Werror *.c  -lm -g
	cppcheck *.c *.h
	clang-format --style=Google -i *.c *.h
	python3 cpplint.py --extensions=c *.c *.h
	leaks -quiet -atExit -- ./a.out > test.log
	grep -e "0 total leaked bytes" -e "nodes malloced" -e "leaks Report Version" -v test.log

teztfast: clean
	gcc -Wextra -Wall -Werror *.c  -lm -g
	cppcheck *.c *.h
	clang-format --style=Google -i *.c *.h
	leaks -quiet -atExit -- ./a.out > test.log
	grep -e "0 total leaked bytes" -e "nodes malloced" -e "leaks Report Version" -v test.log

teztnoleak: clean
	gcc -Wextra -Wall -Werror *.c  -lm -g
	cppcheck *.c *.h
	clang-format --style=Google -i *.c *.h
	./a.out

teztlinux: clean
	gcc -Wextra -Wall -Werror *.c  -lm -g
	cppcheck *.c *.h
	clang-format --style=Google -i *.c *.h
	python3 cpplint.py --extensions=c *.c *.h
	valgrind --leak-check=full --track-origins=yes --show-leak-kinds=all -q ./a.out

cpplinth: clean
	python3 ../linters/cpplint.py *.h

style:
	clang-format --style=Google -n *.c *.h

stylef:
	clang-format --style=Google -i *.c *.h

clean:
	rm -f test *.gc* test.info log.xml test.log leak.log *.out
	rm -f -rf report *.out.dSYM

	# leaks -quiet -atExit -- ./a.out > test.log
	# grep -e "0 total leaked bytes" -e "nodes malloced" -e "leaks Report Version" -v test.log