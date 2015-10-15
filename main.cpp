#include <iostream>

#include "calc.h"
#include "table.h"

int main() {

  std::string str;
  Calc s;
  Table t;

  
  std::cout << "> ";
  while( std::getline(std::cin, str) ) {
    if( str == "exit" ) break;
    t.init(str);
    t.print();
    std::cout << "> ";
  }
  
  return 0;
}
