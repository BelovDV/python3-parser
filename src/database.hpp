#pragma once

#include "data.hpp"

#include <vector>

void write_to_database(
	const std::string file_output, const std::vector<ObjectData>& data);
