#include <iostream>
#include <set> 
#include <vector> 
#include <string> 
#include <boost/algorithm/string.hpp>


int main(int argc, char** argv) {
  std::set<int> s;
  s.insert(1);
  s.insert(20);
  s.insert(15);
  s.insert(100);

  for (auto i = s.begin(); i != s.end(); i++) {
    std::cout << *i << ' ';
  }
  std::cout << std::endl;

  
  std::vector<std::string> strs;
  boost::split(strs, "string to split", boost::is_any_of(" "));
  for (auto i = strs.begin(); i != strs.end(); i++) {
    std::cout << *i << ';';
  }

  std::cout << std::endl;
}
