#include <iostream>
#include <unordered_map>
#include <string>
#include <map>
#include <vector>
#include <set>

void print_map(std::pair<std::string, int> map) {
    std::cout << map.first << " - " << map.second << std::endl;
}
bool test(const std::pair<std::string, int> map) {
    return map.second < 1;
}
void printvector(int i) {
    std::cout << i << ' ';
}
bool compare(const int& a) {
    return a < 0;
}
bool sort(int a, int b){
    return a > b;
}

int main() {
    std::unordered_multimap <std::string , int> days ({ {"Mon", 1}, {"Tue", 2}, {"Tue1", 2}, {"Wed", 3}, {"Thr", -4},
                                                        {"Thr1", -5}, {"Fr", 6}, {"Fr1", 7}, {"Sat", -8}, {"Sun", 9}, {"Sun1", -10} });
    std::cout << "Primordial map" << std::endl;
    std::for_each(days.begin(), days.end(), print_map);
    std::cout << std::endl;
      // part 1
//erase all 2's and 3's
for (auto i = days.begin(); i != days.end();) {
if ( (i->second == 3) || (i->second == 2) )
i = days.erase(i);
else i++;
}
std::cout << "Map without 2's and 3's" << std::endl;
std::for_each(days.begin(), days.end(), print_map);
std::cout << std::endl;
//insert 3 new values with key 1
days.insert(std::make_pair<std::string, int>("Mon2", 1));
days.insert(std::make_pair<std::string, int>("Mon3", 1));
days.insert(std::make_pair<std::string, int>("Mon4", 1));
std::cout << "Map with 3 new elements with the key 1" << std::endl;
std::for_each(days.begin(), days.end(), print_map);
std::cout << std::endl;
//copy to new map
std::map <std::string, int> ddays;
for (auto i : days) {
ddays.insert(std::make_pair(i.first, i.second));
}
std::cout << "A copy of the map" << std::endl;
std::for_each(ddays.begin(), ddays.end(), print_map);
std::cout << std::endl;
  // part 2
// count keys that are lower then 1
int amount = std::count_if(ddays.begin(), ddays.end(), test);
std::cout << "Number of keys that are lower than 1: " << amount << std::endl;
// transform map to vec
std::vector <int> vec;
    std::cout << std::endl;
    std::transform(ddays.begin(), ddays.end(), std::back_inserter(vec), [](const std::pair<std::string , int> i) {return i.second; });
   std::cout << "Vector of keys' values" << std::endl;
   std::for_each(vec.begin(), vec.end(), printvector);
   std::cout << std::endl;
     // part 3
   // find element 1
   auto index = std::find(vec.begin(), vec.end(), 1);
   if (index == vec.end())
   std::cout << "Index 1 was not found" << std::endl;
   else
   std::cout << "Index 1 was first met at " << index - vec.begin()+1 << " position" << std::endl;
   // replace negatives with -5
    std::replace_if(vec.begin(), vec.end(), compare, -5);
    std::cout << "Negative elements were switched with -5" << std::endl;
    std::for_each(vec.begin(), vec.end(), printvector);
    std::cout << std::endl;
    // sort from the biggest to the least
    std::sort(vec.begin(), vec.end(), sort);
    std::cout << "Vector sorted from the biggest to the least" << std::endl;
    std::for_each(vec.begin(), vec.end(), printvector);
    std::cout << std::endl;
    // set
    std::set<int> arr;
    for (int i : vec)
        arr.insert(i);
    std::cout << "Vector converted to set" << std::endl;
    std::for_each(arr.begin(), arr.end(), printvector);
    std::cout << std::endl;
    return 0;
}