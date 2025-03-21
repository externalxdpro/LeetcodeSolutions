// 2115. Find All Possible Recipes from Given Supplies
// Difficulty: Medium

// You have information about n different recipes. You are given a string array
// recipes and a 2D string array ingredients. The ith recipe has the name
// recipes[i], and you can create it if you have all the needed ingredients from
// ingredients[i]. A recipe can also be an ingredient for other recipes, i.e.,
// ingredients[i] may contain a string that is in recipes.

// You are also given a string array supplies containing all the ingredients
// that you initially have, and you have an infinite supply of all of them.

// Return a list of all the recipes that you can create. You may return the
// answer in any order.

// Note that two recipes may contain each other in their ingredients.

// Example 1:

// Input: recipes = ["bread"], ingredients = [["yeast","flour"]], supplies =
// ["yeast","flour","corn"] Output: ["bread"] Explanation: We can create "bread"
// since we have the ingredients "yeast" and "flour".

// Example 2:

// Input: recipes = ["bread","sandwich"], ingredients =
// [["yeast","flour"],["bread","meat"]], supplies = ["yeast","flour","meat"]
// Output: ["bread","sandwich"]
// Explanation:
// We can create "bread" since we have the ingredients "yeast" and "flour".
// We can create "sandwich" since we have the ingredient "meat" and can create
// the ingredient "bread".

// Example 3:

// Input: recipes = ["bread","sandwich","burger"], ingredients =
// [["yeast","flour"],["bread","meat"],["sandwich","meat","bread"]], supplies =
// ["yeast","flour","meat"] Output: ["bread","sandwich","burger"] Explanation:
// We can create "bread" since we have the ingredients "yeast" and "flour".
// We can create "sandwich" since we have the ingredient "meat" and can create
// the ingredient "bread". We can create "burger" since we have the ingredient
// "meat" and can create the ingredients "bread" and "sandwich".

// Constraints:

//     n == recipes.length == ingredients.length
//     1 <= n <= 100
//     1 <= ingredients[i].length, supplies.length <= 100
//     1 <= recipes[i].length, ingredients[i][j].length, supplies[k].length <=
//     10 recipes[i], ingredients[i][j], and supplies[k] consist only of
//     lowercase English letters. All the values of recipes and supplies
//     combined are unique. Each ingredients[i] does not contain any duplicate
//     values.

#include <algorithm>
#include <fmt/ranges.h>
#include <queue>
#include <unordered_set>
#include <vector>

class Solution {
  public:
    std::vector<std::string>
    findAllRecipes(std::vector<std::string>              &recipes,
                   std::vector<std::vector<std::string>> &ingredients,
                   std::vector<std::string>              &supplies) {
        std::unordered_set<std::string> s(supplies.begin(), supplies.end());
        std::queue<int>                 q;
        std::vector<std::string>        result;
        int                             prev = -1;
        for (int i = 0; i < recipes.size(); i++) {
            q.push(i);
        }

        while ((int)s.size() > prev) {
            prev  = s.size();
            int n = q.size();
            while (n--) {
                int i = q.front();
                q.pop();
                bool canCreate = true;

                for (std::string &ingredient : ingredients[i]) {
                    if (!s.contains(ingredient)) {
                        canCreate = false;
                        break;
                    }
                }
                if (canCreate) {
                    s.insert(recipes[i]);
                    result.push_back(recipes[i]);
                } else {
                    q.push(i);
                }
            }
        }

        return result;
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::pair<std::tuple<std::vector<std::string>,
                                     std::vector<std::vector<std::string>>,
                                     std::vector<std::string>>,
                          std::vector<std::string>>>
        tests = {
            {{{"bread"}, {{"yeast", "flour"}}, {"yeast", "flour", "corn"}},
             {"bread"}},
            {{{"bread", "sandwich"},
              {{"yeast", "flour"}, {"bread", "meat"}},
              {"yeast", "flour", "meat"}},
             {"bread", "sandwich"}},
            {{{"bread", "sandwich", "burger"},
              {{"yeast", "flour"},
               {"bread", "meat"},
               {"sandwich", "meat", "bread"}},
              {"yeast", "flour", "meat"}},
             {"bread", "sandwich", "burger"}},
        };

    Solution solution;
    for (auto &[test, ans] : tests) {
        auto result = solution.findAllRecipes(
            std::get<0>(test), std::get<1>(test), std::get<2>(test));
        fmt::println("{} {}: {}", result == ans ? "✅" : "❌", test, result);
    }

    return 0;
}
