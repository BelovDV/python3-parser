#include <iostream>

#include "antlr4-runtime.h"
#include "Python3Lexer.h"
#include "Python3Parser.h"
#include "Python3BaseVisitor.h"

int main() {
	std::cout << "hello world!\n";

	std::ifstream stream;
	stream.open("input.scene");
	if (stream.bad()) {
		std::cout << "can't open file\n";
	}

	antlr4::ANTLRInputStream input(stream);

	Python3Lexer lexer(&input);
	antlr4::CommonTokenStream tokens(&lexer);
	Python3Parser parser(&tokens);

	auto* tree = parser.file_input();
	Python3BaseVisitor visitor;
	// antlr4::Scene scene = visitor.visitFile_input(tree).as<Scene>();
	// scene.draw();
}