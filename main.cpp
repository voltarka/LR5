#include <iostream>
#include <unordered_map>
#include <string>
#include <map>
#include <vector>
#include <set>
using namespace std;

void print_map(std::pair<int, string> map) {
    std::cout << map.second << " - " << map.first << std::endl;
}
bool test(const std::pair<int, string> map) {
    return map.first < 1;
}
void printvector(int i) {
    std::cout << i << ' ';
}
bool compare(const int& a) {
    return a < 0;
}
bool Sort(int a, int b){
    return a > b;
}


int main() {
    std::unordered_multimap <int, std::string> days ({ {1 ,"Mon"}, {2, "Tue"}, {2, "Tue1"}, {3, "Wed"}, {-4, "Thr"},
                                                        {-5, "Thr1"}, {6, "Fr"}, {7, "Fr1"}, {-8, "Sat"}, {9, "Sun"}, {-10, "Sun1"} });
    std::cout << "Primordial map" << std::endl;
    std::for_each(days.begin(), days.end(), print_map);
    std::cout << std::endl;
      // part 1
//erase all 2's and 3's
for (auto i = days.begin(); i != days.end();) {
if ( (i->first == 3) || (i->first == 2) )
i = days.erase(i);
else i++;
}
std::cout << "Map without 2's and 3's" << std::endl;
std::for_each(days.begin(), days.end(), print_map);
std::cout << std::endl;

//insert 3 new values with key 1
days.insert(std::make_pair<int, string>(1, "Mon2"));
days.insert(std::make_pair<int, string>(1, "Mon3"));
days.insert(std::make_pair<int, string>(1, "Mon4"));
cout << "Map with 3 new elements with the key 1" << std::endl;
for_each(days.begin(), days.end(), print_map);
cout << endl;

//copy to new map
map <int, string> ddays;
for (auto i : days) {
ddays.insert(make_pair(i.first, i.second));
}
cout << "A copy of the map" << endl;
for_each(ddays.begin(), ddays.end(), print_map);
cout << endl;

  // part 2
// count keys that are lower then 1
int amount = count_if(ddays.begin(), ddays.end(), test);
cout << "Number of keys that are lower than 1: " << amount << endl;

// transform map to vec
vector <int> vec;
    cout << std::endl;
    transform(ddays.begin(), ddays.end(), back_inserter(vec), [](const std::pair<int, string> i) {return i.first; });
   cout << "Vector of keys' values" << std::endl;
   for_each(vec.begin(), vec.end(), printvector);
   cout << std::endl;

     // part 3
   // find element 1
   auto index = find(vec.begin(), vec.end(), 1);
   if (index == vec.end())
   cout << "Index 1 was not found" << endl;
   else
   cout << "Index 1 was first met at " << index - vec.begin()+1 << " position" << endl;

   // replace negatives with -5
    replace_if(vec.begin(), vec.end(), compare, -5);
    cout << "Negative elements were switched with -5" << endl;
    for_each(vec.begin(), vec.end(), printvector);
    cout << std::endl;

    // sort from the biggest to the least
    sort(vec.begin(), vec.end(), Sort);
    cout << "Vector sorted from the biggest to the least" << endl;
    for_each(vec.begin(), vec.end(), printvector);
    cout << endl;

    // set
    set<int> arr;
    for (int i : vec)
        arr.insert(i);
    cout << "Vector converted to set" <<endl;
    for_each(arr.begin(), arr.end(), printvector);
    cout << endl;
    return 0;
}
