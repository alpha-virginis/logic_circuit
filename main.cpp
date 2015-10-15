#include <bits/stdc++.h>

#include "calc.h"

#include "table.h"

/*
class table {
public:
  std::string str;
  std::vector<char> cs;
  void init(std::string str_) {
    str = str_;
    cs.clear();
    for(int i = 0; i < (int)str.size(); ++i) {
      if( not ( str[i] == '(' or str[i] == ')' or str[i] == '+' or str[i] == '*' ) ) {
        setchar(str[i]);
      }
    }
    return;
  }
  void setchar(char c) {
    if( 'A' <= c and c <= 'Z' ) {
      for(int i = 0; i < (int)cs.size(); ++i) {
        if( c == cs[i] ) return;
      }
      cs.push_back(c);
      std::sort(cs.begin(), cs.end());
    }
  }
  void print(void) {
    for(int i = 0; i < (int)cs.size(); ++i) {
      std::cout << cs[i] << "  ";
    }
    std::cout << str << std::endl;
    for(int i = 0; i < (1 << cs.size()); ++i) {
      std::string print_str = str;
      for(int j = 0; j < (int)cs.size(); ++j) {
        std::cout << (i >> (cs.size() - j - 1) & 0x01) << "  ";
        editstr(print_str, cs[j], (i >> (cs.size() - j - 1) & 0x01));
      }
      Calc s;
      std::cout << s.calc(print_str) << std::endl;
    }
  }
  void editstr(std::string &str_, char c, int n) {
    for(int i = 0; i < (int)str_.size(); ++i) {
      if( str_[i] == c ) {
        str_[i] = n + '0';
      }
    }
    return;
  }
};  
*/
  

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
  

  /*
    std::cout << "> ";
    while( std::getline(std::cin, str) ) {
    std::cout << s.calc(str) << std::endl;
    std::cout << "> ";
    }
  */
  
  return 0;
}
