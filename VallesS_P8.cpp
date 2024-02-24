//2023F_CSCI221_VB Computer Science II
//Steve Valles Quiroz
//Project 8

#include <vector>
#include <iostream>
#include <string>

template <typename itemT>
class Set {
private:
    std::vector<itemT> items;

public:
    //Add a new item to the set
    void add(itemT item) {
        if (!isMember(item)) {
            items.push_back(item);
        }
    }

    //Remove an item from the set
    void remove(itemT item) {
        for (auto it = items.begin(); it != items.end(); ++it) {// Iterate through the set and erase when pointed item is matched
            if (*it == item) {
                items.erase(it);
                break;
            }
        }
    }

    //Check number of items in the set
    int size() const {
        return items.size();
    }

    //Check if item is on the set
    bool isMember(itemT item) const {
        for (const auto& i : items) {//iterate over items on the set and return true if found or false otherwisee
            if (i == item) {
                return true;
            }
        }
        return false;
    }

    //Return pointer to a dynamically created array containing each item in the set
    itemT* toArray() const {
        itemT* array = new itemT[items.size()];
        for (std::size_t i = 0; i < items.size(); ++i) {//Iterate over array and add to items
            array[i] = items[i];//copy items to array
        }
        return array;
    }
};

int main() {
    Set<int> set_test;//Create a new set

    //Add 5 items to the set
      set_test.add(1);
      set_test.add(2);
      set_test.add(3);
      set_test.add(4);
      set_test.add(5);

    //Check for size of the set
    std::cout << "Size of the set: " << set_test.size() << std::endl;  // Should print 5

    //Check if an item is a member of the set
    std::cout << "Is 3 in the set? " << (set_test.isMember(3) ? "Yes" : "No") << std::endl;  // 3 is currently in the set
    std::cout << "Is 6 in the set? " << (set_test.isMember(6) ? "Yes" : "No") << std::endl;  // 6 is not currently in the set

    //Removing 3rd item from the set
  std::cout << "\nremoving third item from the set..\n\n";
  set_test.remove(3);
  
  //Cout set size
    std::cout << "Size of set after removing 3: " << set_test.size() << std::endl;
    std::cout << "Is 3 in the set? " << (set_test.isMember(3) ? "Yes" : "No") << std::endl;  //3 is currently not in the set anymore

  
    int* array = set_test.toArray();//Point to array of ints.
    std::cout << "Items in the set: ";//Iterate over array and print.
    for (std::size_t i = 0; i < set_test.size(); ++i) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;

    delete[] array;

    return 0;
}





