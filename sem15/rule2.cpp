#include "base.h"

#include <iostream>

class RuleTwo: public TRule {
public:
  virtual void Do() const {
    std::cout << "rule two\n";
  }
  static bool isRegistered;
};

bool RuleTwo::isRegistered = GetRegistry().insert(std::make_pair("rule2", TRule::Create<RuleTwo>)).second;
