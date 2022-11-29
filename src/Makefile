tezt:
	gcc -Wextra -Wall -Werror s21_decimal.c -lm
	cppcheck s21_decimal.c
	./a.out

tezt_risky:
	gcc s21_decimal.c -lm
	cppcheck s21_decimal.c
	./a.out

make gitaboba:
	git add s21_decimal.c s21_decimal.h Makefile
	git commit -m "sharkmer: decimal aboba update"
	git push origin aboba