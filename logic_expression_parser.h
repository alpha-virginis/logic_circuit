#ifndef LOGIC_EXPRESSION_H_
#define LOGIC_EXPRESSION_H_

#include "logic_expression.h"

template<typename Func>
class LogicExpressionParser_ {
  std::string str;
  int i;
  Func func;
public:
  void setFunc(Func func_) {
    furc = func_;
  }
  LogicExpression operator () (std::string str_);

};

LogicExpressionParser_ LogicExpressionParser;

#endif // LOGIC_EXPRESSION_H_

// LogicExpression Func(char c) tteuinowokaesu

// S <- ' '
// var <- S* ('0' / '1' / ['A'...'Z'] / ['a'...'z'])
// ope_not <- S* (('!' / '~') S*)? (var / ('(' *S expr S* ')')
// ope_and <- S* ope_not (S* ('*' S*)? ope_not)*
// ope_or <- S* ope_and (S* '+' S* ope_and)*
// expr <- S* ope_or

