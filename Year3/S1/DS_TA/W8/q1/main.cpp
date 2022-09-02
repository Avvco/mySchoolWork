/**
 * Pair
 * 
 * @Description:
 * Please finish the struct "Pair".
 * You can add any function or variable if you want.
 * You must use your own data structure or you will get up to 0 points.
 * 
 * @Input Description
 * NONE
 * 
 * @Output Description
 * NONE
 */

#include <iostream>
#include <string>
using namespace std;

/**
 * @brief Struct for Pair
 * 
 * @tparam K data type for key or first
 * @tparam V data type for value or second
 */
template<class K,class V>
struct Pair {
    /**
     * @brief Construct a new Pair object
     */
    Pair() {}

    /**
     * @brief Construct a new Pair object
     * 
     * @param key 
     * @param value 
     */
    Pair(K key, V value) {}

    /**
     * @brief Copy construct a new Pair object
     * 
     * @param other 
     */
    Pair(const Pair& other) {}

    friend ostream& operator<<(ostream& os, const Pair& p) {
      os << p.first << " " << p.second;
      return os;
    }
    K first;
    V second;
};

int main() {
  Pair<string, string> p1("Hello", "World");
  cout << p1 << endl; // excepted output: Hello World

  Pair<string, string> p2(p1);
  cout << p2 << endl; // excepted output: Hello World

  Pair<double, int> p3(123.1, 'A');
  cout << p3 << endl; // excepted output: 123.1 65

  Pair<int, double> p4;
  p4.first = 'z';
  p4.second = 12.3;
  cout << p4 << endl; // excepted output: 122 12.3
}