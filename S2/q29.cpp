// http://134.208.3.66/problem/PR-1092Q28

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
      copy(s.element, s.element + count, element);
    }

    int add(const int x) {
      for (int i = 0 ; i < count ; i++) {
        if(element[i] == x) return 0;
      }
      element[count] = x;
      count = count + 1;
      return 1;
    }

    int add(const Set& set) {
      int ret = 0;
      for (int i = 0; i < set.count; ++i)
        ret = ret + add(set.element[i]);
      return ret;
    }

  	void display()
    {
      int j;
      for(j = 0;j < count;j ++)
        cout<<element[j]<<" ";
    }

    Set& operator+(const Set& set) {
    	Set *s = new Set(*this);
    	s -> add(set);
    	return *s;
    }
    Set& operator-(const Set& set) {
    	Set *s = new Set;
    	for (int i = 0; i < count; i++) {
    		for (int j = 0; j < set.count; j++) {
    			if (element[i] == set.element[j]) {
    				s -> element[s -> count] = element[i];
            s -> count = s -> count + 1;
    				break;
    			}
    		}
    	}
    	return *s;
    }

  private:
  	int element[100];
  	int count;
};
