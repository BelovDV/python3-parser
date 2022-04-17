#include <iostream>

#include "visitor.hpp"
#include "database.hpp"

#include "antlr4-runtime.h"
#include "Python3Lexer.h"

int main(int argc, char** argv) {
	if (argc < 3) return 0;
	Visitor visitor;
	for (int i = 2; i < argc; ++i) {
		std::ifstream stream(argv[i]);
		if (stream.bad()) {
			std::cout << "can't open file `" << argv[i] << "`\n";
			continue;
		}
		antlr4::ANTLRInputStream input(stream);
		Python3Lexer lexer(&input);
		antlr4::CommonTokenStream tokens(&lexer);
		Python3Parser parser(&tokens);
		auto* tree = parser.file_input();
		visitor.set_filename(argv[i]);
		visitor.visitFile_input(tree);
	}
	write_to_database(argv[1], visitor.get_data());
}