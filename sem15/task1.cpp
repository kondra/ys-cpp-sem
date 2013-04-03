#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <string>

class TRule {
public:
  template<typename T>
  static TRule * Create() {
    return new T;
  }
  virtual void Do() const = 0;
  virtual ~TRule() {}
};

enum RuleId {
  ID_RULE_ONE = 1,
  ID_RULE_TWO = 2,
  ID_RULE_THREE = 3,
};

typedef TRule * (*TCreator)();
typedef std::map<RuleId, TCreator> TRegistry;

TRegistry& GetRegistry() {
  static TRegistry registry;
  return registry;
}

class RuleOne: public TRule {
public:
  virtual void Do() const {
    std::cout << "rule one\n";
  }
  static bool isRegistered;
};

bool RuleOne::isRegistered = GetRegistry().insert(std::make_pair(ID_RULE_ONE, TRule::Create<RuleOne>)).second;

class RuleTwo: public TRule {
public:
  virtual void Do() const {
    std::cout << "rule two\n";
  }
  static bool isRegistered;
};

bool RuleTwo::isRegistered = GetRegistry().insert(std::make_pair(ID_RULE_TWO, TRule::Create<RuleTwo>)).second;

class RuleThree: public TRule {
public:
  virtual void Do() const {
    std::cout << "rule three\n";
  }
  static bool isRegistered;
};

bool RuleThree::isRegistered = GetRegistry().insert(std::make_pair(ID_RULE_THREE, TRule::Create<RuleThree>)).second;

TRule * CreateObject(int id) {
  TRegistry& registry = GetRegistry();
  auto iter = registry.find((RuleId)id);
  if (iter != registry.end()) {
    return (iter->second)();
  } else {
    return 0;
  }
}

std::vector<TRule*> Load(const std::string& filename) {
  std::vector<TRule*> rules;
  std::ifstream in(filename);
  int id;
  while (in >> id) {
    rules.push_back(CreateObject((RuleId)id));
  }
  in.close();
  return rules;
}

void Apply(const std::vector<TRule*>& rules) {
  for (TRule* rule: rules) {
    rule->Do();
  }
}

int main() {
  std::vector<TRule*> rules;
  rules = Load("config");
  Apply(rules);
  for (TRule* rule: rules) {
    delete rule;
  }
  return 0;
}
