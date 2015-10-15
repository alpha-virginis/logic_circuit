#include "calc.h"

// return == -1 : fail
// return != -1 : success ( return computation except for S() )

// S <- ' '
int Calc::S(void) {
  if( str[i] != ' ' ) {
    return -1;
  }
  i += 1;
  return 0;
}

// num <- S* ('0' / '1')
int Calc::num(void) {
  while( S() != -1 ) ;
  if( str[i] == '0' or str[i] == '1' ) {
    i += 1;
    return str[i - 1] - '0';
  }
  return -1;
}

// value <- S* num / ('(' S* expr S* ')')
int Calc::value(void) {
  int res;
  while( S() != -1 ) ;
  if( (res = num()) >= 0 ) {
    return res;
  }
  else {
    int j = i;    
    if( str[i] != '(' ) return -1;
    i += 1;
    while( S() != -1 ) ;
    if( (res = expr()) < 0 ) {
      i = j;
      return -1;
    }
    while( S() != -1 ) ;
    if( str[i] != ')' ) {
      i = j;
      return -1;
    }
    i += 1;
    return res;
  }
  return -1;
}

// value2 <- S* ('~' / '!')? value
int Calc::value2(void) {
  int res;
  while( S() != -1 ) ;
  if( str[i] == '~' or str[i] == '!' ) {
    int j = i;
    i += 1;
    while( S() != -1 ) ;
    if( (res = value()) < 0 ) {
      i = j;
      return -1;
    }
    return 1 - res;
  }
  return value();
}

// term <- S* value2 (S* '*'? S* value2)*
int Calc::term(void) {
  int res = 1, temp;
  while( S() != -1 ) ;
  if( (temp = value2()) < 0 ) return -1;
  while( S() != -1 ) ;
  res = std::min(res, temp);
  for(;;) {
    int j = i;
    while( S() != -1 ) ;
    if( str[i] == '*' ) {
      i += 1;
      if( S() != -1 ) i += 1;
    }
    if( (temp = value2()) < 0 ) {
      i = j;
      return res;
    }
    res = std::min(res, temp);
  }
  return -1;
}

// add <- S* term (S* '+' S* term)*
int Calc::add(void) {
  int res = 0, temp;
  while( S() != -1 ) ;
  if( (temp = term()) < 0 ) return -1;
  res = std::max(res, temp);
  for(;;) {      
    int j = i;
    while( S() != -1 ) ;
    if( str[i] != '+' ) {
      i = j;
      return res;
    }
    i += 1;
    while( S() != -1 ) ;
    if( (temp = term()) < 0 ) {
      i = j;
      return res;
    }
    res = std::max(res, temp);
  }
  return -1;
}

// expr <- S* add
int Calc::expr(void) {
  int res;
  while( S() != -1 ) ;
  if( (res = add()) < 0 ) return -1;
  while( S() != -1 ) ;
  return res;
}                  

int Calc::calc(std::string str_) {
  str = str_;
  i = 0;
  return expr();
}
