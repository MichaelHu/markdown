all: clean doyacc dolex markdown.out

doyacc:
	bison -d -t --locations -omarkdown.y.c markdown.y

dolex:
	flex -omarkdown.lex.c markdown.lex

markdown.out: main.o input.o markdown.y.o markdown.lex.o htmltags.o tagstack.o tagstackcheck.o blocknode.o blocknodestack.o strbuf.o
	gcc $^ -o $@ -g

..c.o:
	gcc -c $< -g

clean:
	rm -rf *.o 

