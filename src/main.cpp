#include <iostream>

#include "antlr4-runtime.h"
#include "Python3Lexer.h"
#include "Python3Parser.h"
#include "Python3BaseVisitor.h"

int main(int argc, char** argv) {
	std::cout << "\nPython3 parser\n\tfiles:\n";
	for (int i = 1; i < argc; ++i) {
		std::cout << "\t\t" << argv[i] << "\n";
	}
	std::cout << '\n';

	for (int i = 1; i < argc; ++i) {
		std::cout << "\n" << argv[i] << "\n\n";

		std::ifstream stream(argv[i]);
		if (stream.bad()) {
			std::cout << "can't open file `" << argv[i] << "`\n";
		}

		antlr4::ANTLRInputStream input(stream);

		Python3Lexer lexer(&input);
		antlr4::CommonTokenStream tokens(&lexer);
		Python3Parser parser(&tokens);

		antlr4::tree::ParseTree* tree = parser.file_input();

		Python3BaseVisitor visitor;


		for (const auto& token : tokens.getTokens()) {
			std::cout << token->toString() << '\n';
		}

		std::cout << tree->toStringTree() << '\n';
	}
}