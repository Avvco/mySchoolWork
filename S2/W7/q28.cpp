// http://134.208.3.66/problem/PR109-2Q28


#include <iostream>
#include <algorithm>

using namespace std;
class Set
{
  public:

    // Constructor
    Set() {
      this -> count = 0;
    }
    // Constructor
    Set(const Set &s) {
      this -> count = s.count;
      copy(s.element, s.element + count, begin(this -> element));
    }

    int add(const int x) {
      for (int i = 0 ; i < count ; i++) {
        if(element[i] == x) return 0;
      }
      count = count + 1;
      element[count] = x;
      return 1;
    }

    int add(const Set& set) {
      int oriCount = count;
      for (int i = 0; i < set.count; i++) {
        bool found = false;
        for (int j = 0 ; j < count ; j++) {
          if(element[j] == set.element[i]) {
            found = true;
            break;
          }
        }
        if(!found) {
          count = count + 1;
          element[count] = set.element[i];
        }
      }
      return count - oriCount;
    }

  	void display()
    {
      int j;
      for(j = 0;j < count;j ++)
        std::cout<<element[j]<<" ";
    }
  private:
  	int element[100];
  	int count;
};
