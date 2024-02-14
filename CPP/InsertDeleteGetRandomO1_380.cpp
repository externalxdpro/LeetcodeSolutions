#include <algorithm>
#include <unordered_map>
#include <utility>
#include <vector>

class RandomizedSet {
  public:
    RandomizedSet() {}

    bool insert(int val) {
        if (indexes.contains(val)) {
            return false;
        }

        elems.push_back(val);
        indexes[val] = elems.size() - 1;
        return true;
    }

    bool remove(int val) {
        if (!indexes.contains(val)) {
            return false;
        }

        indexes[elems.back()] = indexes[val];
        std::swap(elems[indexes[val]], elems.back());
        indexes.erase(val);
        elems.pop_back();
        return true;
    }

    int getRandom() { return elems[std::rand() % elems.size()]; }

  private:
    std::unordered_map<int, int> indexes;
    std::vector<int>             elems;
};
