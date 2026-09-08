// eat_ghost returns a boolean value if Pac-Man is able to eat the ghost.
// The function should return true only if Pac-Man has a power pellet active
// and is touching a ghost.
bool can_eat_ghost(const bool &power_pellet_active, 
                   const bool &touching_ghost) {
  // TODO: Please implement the can_eat_ghost function
  return power_pellet_active and touching_ghost;
}

// score returns a boolean value if Pac-Man scored.
// The function should return true if Pac-Man is touching a power pellet or a
// dot.
bool scored(const bool &touching_power_pellet, 
            const bool &touching_dot) {
    // TODO: Please implement the scored function
    return touching_dot or touching_power_pellet;
}

// lost returns a boolean value if Pac-Man loses.
// The function should return true if Pac-Man is touching a ghost and
// does not have a power pellet active.
bool lost(const bool &power_pellet_active, 
          const bool &touching_ghost) {
    // TODO: Please implement the lost function
    return not power_pellet_active and touching_ghost;
}

// won returns a boolean value if Pac-Man wins.
// The function should return true if Pac-Man
// has eaten all of the dots and has not lost
bool won(const bool &has_eaten_all_dots, 
         const bool &power_pellet_active,
         const bool &touching_ghost) {
    // TODO: Please implement the won function
    return has_eaten_all_dots and not lost(power_pellet_active, touching_ghost);
}
