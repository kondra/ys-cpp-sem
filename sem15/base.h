#ifndef __BASE_H__
#define __BASE_H__

#include <string>
#include <map>

class TRule {
public:
  template<typename T>
  static TRule * Create() {
    return new T;
  }
  virtual void Do() const = 0;
  virtual ~TRule() {}
};

typedef TRule * (*TCreator)();
typedef std::map<std::string, TCreator> TRegistry;

TRegistry& GetRegistry();

#endif
