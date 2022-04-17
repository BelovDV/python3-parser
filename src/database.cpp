#include "database.hpp"

#include <fstream>

void write_to_database(
	const std::string file_output, const std::vector<ObjectData>& data)
{
	std::ofstream out(file_output);
	out << "Filename;Type;Name;Line begin;Line end\n";
	for (const auto& object : data) {
		out
			<< object.source_file << ";"
			<< (object.type == ObjectData::Function ? "function" : "class") << ";"
			<< object.object_name << ";"
			<< object.indent_begin << ";"
			<< object.indent_end << "\n"
			;
	}
}