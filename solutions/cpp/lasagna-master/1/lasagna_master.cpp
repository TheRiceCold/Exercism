#include "lasagna_master.h"

namespace lasagna_master {

// TODO: add your solution here
  int preparationTime(
    const std::vector<std::string>& layers, 
    int minutes_per_layer) {
    int minutes = minutes_per_layer == 0 ? 2 : minutes_per_layer;  
    return layers.size() * minutes;
  }

  amount quantities(const std::vector<std::string>& list) {
    int noodle_counter{0};
    int sauce_counter{0};
    for (const auto& i : list) {
      if (i == "noodles") ++noodle_counter;
      if (i == "sauce") ++sauce_counter;  
    }
    amount result;
    result.noodles = noodle_counter * 50;
    result.sauce = sauce_counter * 0.2;
    return result;
  }

  void addSecretIngredient(
    std::vector<std::string>& myList, 
    const std::vector<std::string>& friendsList) {
    myList[myList.size()-1] = friendsList.back();
  }

  std::vector<double> scaleRecipe(
    const std::vector<double>& quantities, int portions) {
    std::vector<double> needed_amount;
    for (const auto& q : quantities)
      needed_amount.emplace_back((q * portions) / 2);
    return needed_amount;  
  }  

  void addSecretIngredient(
    std::vector<std::string>& myList, 
    std::string secretIngredient) {
    myList[myList.size()-1] = secretIngredient;
  }
}  // namespace lasagna_master
