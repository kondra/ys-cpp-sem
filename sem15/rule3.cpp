#include "base.h"

#include <iostream>

class RuleThree: public TRule {
public:
  virtual void Do() const {
    std::cout << "rule three\n";
  }
  static bool isRegistered;
};

bool RuleThree::isRegistered = GetRegistry().insert(std::make_pair("rule3", TRule::Create<RuleThree>)).second;
