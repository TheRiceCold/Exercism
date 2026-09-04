#include "speedywagon.h"

namespace speedywagon {

// Enter your code below:
bool connection_check(const pillar_men_sensor* sensor) {return sensor;}

int activity_counter(const pillar_men_sensor sensors[], int capacity) {
  int accumulated_activity{};

  for (int i{0}; i < capacity; ++i)
    accumulated_activity += sensors[i].activity;

  return accumulated_activity;
}

bool alarm_control(const pillar_men_sensor* sensor) {
  return sensor && sensor->activity > 0;
}

bool uv_alarm(pillar_men_sensor* sensor) {
  if (!sensor) return false;

  int uv_index = uv_light_heuristic(&sensor->data);
  return uv_index > sensor->activity;
}

// Please don't change the interface of the uv_light_heuristic function
int uv_light_heuristic(std::vector<int>* data_array) {
    double avg{};
    for (auto element : *data_array)
      avg += element;

    avg /= data_array->size();
    int uv_index{};
    for (auto element : *data_array)
      if (element > avg) ++uv_index;

    return uv_index;
}

}  // namespace speedywagon
