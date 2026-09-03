#pragma once

#include <string>
#include <memory>

namespace troy {

  struct artifact {
    // constructors needed (until C++20)
    artifact(std::string name) : name(name) {}
    std::string name;
  };

  struct power {
    // constructors needed (until C++20)
    power(std::string effect) : effect(effect) {}
    std::string effect;
  };

  struct human {
    std::unique_ptr<artifact> possession;
    std::shared_ptr<power> own_power;
    std::shared_ptr<power> influenced_by;
  };

  void give_new_artifact(human& man, std::string name);
  void exchange_artifacts(
    std::unique_ptr<artifact>& p1, 
    std::unique_ptr<artifact>& p2);
  void manifest_power(human& man, std::string effect);
  void use_power(human& man1, human& man2);
  int power_intensity(const human& man);
}  // namespace troy
