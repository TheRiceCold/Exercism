#pragma once

#include <vector>
#include <string>

namespace lasagna_master {

  struct amount {int noodles; double sauce;};

  int preparationTime(
    const std::vector<std::string>& layers, 
    int minutes_per_layer = 2);

  amount quantities(const std::vector<std::string>& list);

  void addSecretIngredient(
    std::vector<std::string>& myList, 
    const std::vector<std::string>& friendsList);

  std::vector<double> scaleRecipe(
    const std::vector<double>& quantities, 
    int portions);

  void addSecretIngredient(
    std::vector<std::string>& myList, 
    std::string secretIngredient);
}  // namespace lasagna_master
