#include <iostream>
#include <vector>
#include <string>
#include <map>

#include "base.h"

TRule * CreateObject(const std::string& id) {
  TRegistry& registry = GetRegistry();
  auto iter = registry.find(id);
  if (iter != registry.end()) {
    return (iter->second)();
  } else {
    return 0;
  }
}

std::vector<TRule*> Init() {
  std::vector<TRule*> rules;
  for (std::pair<std::string, TCreator> elem: GetRegistry()) {
    rules.push_back(CreateObject(elem.first));
  }
  return rules;
}

void Apply(const std::vector<TRule*>& rules) {
  for (TRule* rule: rules) {
    rule->Do();
  }
}

TRegistry& GetRegistry() {
  static TRegistry registry;
  return registry;
}

int main() {
  std::vector<TRule*> rules;
  rules = Init();
  Apply(rules);
  for (TRule* rule: rules) {
    delete rule;
  }
  return 0;
}
