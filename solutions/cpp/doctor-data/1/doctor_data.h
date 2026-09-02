#pragma once

#include <string>

namespace star_map {
  enum class System {
    Sol, 
    BetaHydri, 
    EpsilonEridani, 
    AlphaCentauri,
    DeltaEridani,
    Omicron2Eridani
  };
}

namespace heaven {
  class Vessel {
  public:
    Vessel(std::string n, int gen)
      : name(n), generation(gen) {}
    
    Vessel(std::string n, int gen, star_map::System system)
      : name(n), generation(gen), current_system(system) {}

    std::string name;
    int generation = 1;
    int busters = 0;
    star_map::System current_system = star_map::System::Sol;

    Vessel replicate(std::string name) {
      return Vessel{name, generation+1, current_system};
    }

    void make_buster();
    bool shoot_buster();
  };

  std::string get_older_bob(Vessel v1, Vessel v2);
  bool in_the_same_system(Vessel v1, Vessel v2);
}