contact: main.c contact.c file.c print.c tips.c subpro.c
	gcc -fdiagnostics-color=always $^ -o $@ -O3
.PHONY:
clean:
	rm -rf ./bin