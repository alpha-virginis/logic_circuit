#ifndef CALC_H_
#define CALC_H_

#include <string>

class Calc {
  std::string str;
  int i;
  int S();
  int num();
  int value();
  int value2();
  int term();
  int add();
  int expr();
public:
  int calc(std::string str_);
};

#endif // CALC_H_
