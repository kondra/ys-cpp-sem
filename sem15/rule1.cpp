#include "base.h"

#include <iostream>

class RuleOne: public TRule {
public:
  virtual void Do() const {
    std::cout << "rule one\n";
  }
  static bool isRegistered;
};

bool RuleOne::isRegistered = GetRegistry().insert(std::make_pair("rule1", TRule::Create<RuleOne>)).second;
