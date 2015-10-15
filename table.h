#ifndef TABLE_H_
#define TABLE_H_

#include <string>
#include <vector>

class Table {
private:
  std::string str;
  std::vector<char> cs;
  void setchar(char c);
  void editstr(std::string &str, char c, int n);
public:
  void init(std::string str_);
  void print(void);
};

#endif // TABLE_H_
