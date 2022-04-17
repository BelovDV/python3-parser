#pragma once

#include "Python3BaseVisitor.h"

#include "data.hpp"

#include <vector>

class Visitor : public Python3BaseVisitor {
public:
	Visitor(std::string&& filename) : filename_(std::move(filename)) {}

	antlrcpp::Any visitFuncdef(Python3Parser::FuncdefContext* ctx) override;
	antlrcpp::Any visitClassdef(Python3Parser::ClassdefContext* ctx) override;

	const std::vector<ObjectData>& get_data() const {
		return data_;
	}

private:
	std::vector<ObjectData> data_;
	std::string filename_;
};