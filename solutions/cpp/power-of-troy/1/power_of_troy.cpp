#include "power_of_troy.h"

namespace troy {
  void give_new_artifact(human& man, std::string name) {
    man.possession = std::make_unique<artifact>(artifact{name});
  }
    
  void exchange_artifacts(
    std::unique_ptr<artifact>& p1, 
    std::unique_ptr<artifact>& p2) {
    p1.swap(p2);       
  }

  void manifest_power(human& man, std::string effect) {
    man.own_power = std::make_shared<power>(power{effect});;
  }

  void use_power(human& caster, human& target) {
    target.influenced_by = caster.own_power;        
  }

  int power_intensity(const human& man) {
    if (!man.own_power) return 0;  
    return man.own_power.use_count();
  }  
}  // namespace troy
