#include <iostream>

#include "antlr4-runtime.h"
#include "Python3Lexer.h"
#include "Python3Parser.h"
#include "Python3BaseVisitor.h"

class MyVisitor : public Python3BaseVisitor {
public:
	antlrcpp::Any visitFuncdef(Python3Parser::FuncdefContext* ctx) override {
		std::cout << "Function: " << ctx->NAME()->getText() << " from line " << ctx->getStart()->getLine() << " to line " << ctx->getStop()->getLine() << '\n';
		return nullptr;
	}

	antlrcpp::Any visitClassdef(Python3Parser::ClassdefContext *ctx) override {
		std::cout << "Class: " << ctx->NAME()->getText() << " from line " << ctx->getStart()->getLine() << " to line " << ctx->getStop()->getLine() << '\n';
		return nullptr;
	}
};

int main(int argc, char** argv) {
	std::cout << "\nPython3 parser\n\tfiles:\n";
	for (int i = 1; i < argc; ++i) {
		std::cout << "\t\t" << argv[i] << "\n";
	}
	std::cout << '\n';

	for (int i = 1; i < argc; ++i) {
		std::cout << "\n===================\n";
		std::cout << argv[i] << '\n';

		std::ifstream stream(argv[i]);
		if (stream.bad()) {
			std::cout << "can't open file `" << argv[i] << "`\n";
		}

		antlr4::ANTLRInputStream input(stream);

		Python3Lexer lexer(&input);
		antlr4::CommonTokenStream tokens(&lexer);

		Python3Parser parser(&tokens);
		auto* tree = parser.file_input();
		MyVisitor visitor;
		visitor.visitFile_input(tree);
	}
}