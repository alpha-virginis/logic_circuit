#include "logic_expression_parser.h"

LogicExpression LogicExpressionParser_::operator () (std::string str_) {
  str = str_;
  i = 0;
  return expr();
}

LogitExpresson LogicExpressionParser_::S() {
  if( 
