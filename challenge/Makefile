generator: main.o board.o logic.o

	gcc -o $@ $^
.c.o:
	gcc -c $<

clean:
	rm -rf *.o generator truth_table truth_table_minimized
