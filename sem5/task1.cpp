#include <iostream>
#include <vector>
#include <list>
#include <map>

int main() {
  {
    std::cout << "vector\n";
    std::vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    std::vector<int>::iterator it = v.begin() + 1;
    std::cout << *it << '\n';
    v.erase(it);
    std::cout << *it << '\n';
    v.resize(10);
    std::cout << *it << '\n';
  }

  {
    std::cout << "list\n";
    std::list<int> l;
    l.push_back(1);
    l.push_back(2);
    l.push_back(3);
    std::list<int>::iterator it = l.begin(),it2;
    ++it;
    it2 = it;
    ++it2;
    std::cout << *it2 << '\n';
    l.erase(it2);
    std::cout << *it2 << '\n';
    std::cout << l.size() << '\n';
  }

  {
    std::cout << "map\n";
    std::map<int, int> m;
    m[1] = 2;
    m[3] = 4;
    m[4] = 5;
    std::map<int, int>::iterator it, it2;
    it2 = m.begin();
    std::cout << it2->second << '\n';
    it = it2;
    --it;
    m.erase(it);
    std::cout << it2->second << '\n';
  }

  return 0;
}
