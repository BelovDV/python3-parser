#pragma once

#include "Python3BaseVisitor.h"

#include "data.hpp"

#include <vector>

class Visitor : public Python3BaseVisitor {
public:
	antlrcpp::Any visitFuncdef(Python3Parser::FuncdefContext* ctx) override;
	antlrcpp::Any visitClassdef(Python3Parser::ClassdefContext* ctx) override;

	const std::vector<ObjectData>& get_data() const {
		return data_;
	}

	void set_filename(std::string&& filename) {
		filename_ = std::move(filename);
	}

private:
	std::vector<ObjectData> data_;
	std::string filename_;
};