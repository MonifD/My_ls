CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: my_ls

my_ls: main.o functions.o flags_pars.o flag_l.o flag_r.o flag_t.o flag_-R.o flag_-L.o color.o
	$(CC) $(CFLAGS) -o my_ls main.o functions.o flags_pars.o flag_l.o flag_r.o flag_t.o flag_-R.o flag_-L.o color.o

main.o: main.c functions.h
	$(CC) $(CFLAGS) -c main.c

functions.o: functions.c functions.h
	$(CC) $(CFLAGS) -c functions.c

flags_pars.o: flags_pars.c functions.h
	$(CC) $(CFLAGS) -c flags_pars.c
	
flag_l.o: flag_l.c functions.h
	$(CC) $(CFLAGS) -c flag_l.c

flag_r.o: flag_r.c functions.h
	$(CC) $(CFLAGS) -c flag_r.c

flag_t.o: flag_t.c functions.h
	$(CC) $(CFLAGS) -c flag_t.c
	
flag_-R.o: flag_-R.c functions.h
	$(CC) $(CFLAGS) -c flag_-R.c
	
flag_-L.o: flag_-L.c functions.h
	$(CC) $(CFLAGS) -c flag_-L.c
	
color.o: color.c functions.h
	$(CC) $(CFLAGS) -c color.c

clean:
	rm -f *.o my_ls
