SOURCEFILE=main.c
OUTPUTFILE=password
CFLAGS=-ansi -Wall -pedantic-errors -O3

$(OUTPUTFILE): $(SOURCEFILE) Makefile
	cc $(SOURCEFILE) -o $(OUTPUTFILE) $(CFLAGS)

