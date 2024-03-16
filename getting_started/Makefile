compiler: lex.yy.c parser.tab.o translating.cpp main.cc inter
		g++ -g -w -ocompiler parser.tab.o lex.yy.c translating.cpp main.cc -std=c++14
parser.tab.o: parser.tab.cc
		g++ -g -w -c parser.tab.cc -std=c++14
parser.tab.cc: parser.yy
		bison parser.yy
lex.yy.c: lexer.flex parser.tab.cc
		flex lexer.flex
tree: 
		 dot -Tpdf tree.dot -otree.pdf
tree2:
	   dot -Tdot tree.dot -otreeDOT
clean:
		rm -f parser.tab.* lex.yy.c* compiler stack.hh position.hh location.hh tree.dot tree.pdf
		rm -R compiler.dSYM
inter: interpretator.cpp
		g++ -g -w -o interpretator interpretator.cpp