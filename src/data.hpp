#pragma once

#include <string>

struct ObjectData {
	enum Type {
		Function,
		Class
	};
	ObjectData(
		const std::string& filename,
		Type type,
		std::string&& name,
		size_t begin, size_t end
	) :
		source_file(filename),
		type(type),
		object_name(std::move(name)),
		indent_begin(begin),
		indent_end(end)
	{}
	std::string source_file;
	Type type;
	std::string object_name;
	size_t indent_begin, indent_end;
};
