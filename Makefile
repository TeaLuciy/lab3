lab3: lab3.c
	gcc -g2 lab3.c -lm -o lab3

lab4: lab4.c
	gcc -g2 lab4.c -lm -o lab4
	
lab5: lab5.c
	gcc -g2 lab5.c -lm -o lab5

rk: rk.c
	gcc -m64 -g2 rk.c -lm -o rk