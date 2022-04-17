#include <iostream>

#include "visitor.hpp"
#include "database.hpp"

#include "antlr4-runtime.h"
#include "Python3Lexer.h"
#include "Python3Parser.h"

int main(int argc, char** argv) {
	Visitor visitor;
	for (int i = 1; i < argc; ++i) {
		std::ifstream stream(argv[i]);
		if (stream.bad()) {
			std::cout << "can't open file `" << argv[i] << "`\n";
		}
		antlr4::ANTLRInputStream input(stream);
		Python3Lexer lexer(&input);
		antlr4::CommonTokenStream tokens(&lexer);
		Python3Parser parser(&tokens);
		auto* tree = parser.file_input();
		visitor.set_filename(argv[i]);
		visitor.visitFile_input(tree);
	}
	for (const auto& object : visitor.get_data()) {
		std::cout
			<< object.source_file << "\t"
			<< (object.type == ObjectData::Function ? "function" : "class   ") << "\t"
			<< object.object_name << "\t"
			<< object.indent_begin << "\t"
			<< object.indent_end << "\n"
			;
	}
	write_to_database("output.xml", visitor.get_data());
}