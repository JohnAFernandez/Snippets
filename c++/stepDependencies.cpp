// Include the required headers for unordered sets and unordered maps
#include <unordered_set>
#include <unordered_map>
#include <vector>

// A function for checking valid "steps"
bool valid_steps(const std::unordered_set<int>& steps, const std::unordered_map<int, std::vector<int>>& dependencies) {

  // Create a set for tracking what steps have been already been accomplished.
  std::unordered_set<int> steps_satisfied;

  // Keep track of how many teps we've been able to do so far.
  size_t last_size;

  // Now loop through steps, looking for new steps that are doable.
  do{
    // Update last_size to what it currently is for checking later.
    last_size = steps_satisfied.size();

    // loop through each step that we're looking for.
    for (const auto& step : steps){

      // If this step has already been added to steps traveled, then we don't need to check dependencies
      if (steps_satisfied.find(step) != steps_satisfied.end())        
        continue;

      // Add a variable to store whether we have missed a dependency
      bool depenencies_found = true;

      // Loop through all the dependencies listed in each step's dependency list
      for (const auto& dependency : dependencies.find(step)->second){

        // Check if the dependency is missing.
        if (steps_satisfied.find(dependency) == steps_satisfied.end()){
          
          // If the dependency has not been found mark it as unfulfiled and break out of this inner loop.
          depenencies_found = false;
          break;
        }
      }

      if (depenencies_found) {
        steps_satisfied.insert(step);
      }
    }

  // check to see if we are unable to satisfy more dependencies or if we have managed to find them all
  } while(last_size != steps_satisfied.size() && steps_satisfied.size() < steps.size());

  // return the result of whether or not we have fulfilled the dependencies of all the provided steps.
  return (steps_satisfied.size() == steps.size());
}
