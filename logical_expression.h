#ifndef LOGICAL_EXPRESSION_H_
#define LOGICAL_EXPRESSION_H_

typedef enum {
  AND, OR, NOT, NONE,
} operator_t;

class LogicalExpression {
public:

  operator_t ope;
  char var;  
  bool state;

  std::vector<LogicalExpression> childs;

  LogicalExpression() {
    childs.clear();
    var = ' ';
    ope = NONE;
  }
  bool isleaf() {
    return childs.empty();
  }
  bool operator bool() {
    return state;
  }
};



#endif // LOGICAL_EXPRESSION_H_
