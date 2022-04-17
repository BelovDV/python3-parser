#include "visitor.hpp"

#include <iostream>

antlrcpp::Any Visitor::visitFuncdef(Python3Parser::FuncdefContext* ctx) {
	data_.emplace_back(
		filename_,
		ObjectData::Function,
		ctx->NAME()->getText(),
		ctx->getStart()->getLine(),
		ctx->getStop()->getLine() + 1
	);
	return nullptr;
}

antlrcpp::Any Visitor::visitClassdef(Python3Parser::ClassdefContext* ctx) {
	data_.emplace_back(
		filename_,
		ObjectData::Class,
		ctx->NAME()->getText(),
		ctx->getStart()->getLine(),
		ctx->getStop()->getLine() + 1
	);
	return nullptr;
}
