#include "doctor_data.h"

namespace heaven {

  Vessel::Vessel(std::string n, int gen, star_map::System system)
    : name(n), generation(gen), current_system(system) {}

  Vessel Vessel::replicate(std::string name) {
    return Vessel{name, generation+1, current_system};
  }

  void Vessel::make_buster() {busters++;}
  bool Vessel::shoot_buster() {
    if (busters == 0) return false;
    busters--;
    return true;
  }
    
  std::string get_older_bob(Vessel v1, Vessel v2) {
    return v1.generation < v2.generation ? v1.name : v2.name;
  }

  bool in_the_same_system(Vessel v1, Vessel v2) {
    return v1.current_system == v2.current_system;
  }    
}
  