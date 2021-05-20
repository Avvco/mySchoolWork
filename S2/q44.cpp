#include <iostream>
#include <algorithm>

using namespace std;
template <class T>
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

    int add(const int x) {  // TODO should be T here ?
      cout << "zzz" << x <<endl;
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
        std::cout<<element[j]<<" ";
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
  	T element[100];
  	int count;
};

int main() {
  Set<double> a, b, c, d;
  std::cout<<a.add(1)<<std::endl;
  std::cout<<a.add(2)<<std::endl;
  std::cout<<a.add(3)<<std::endl;
  std::cout<<a.add(4)<<std::endl;
  std::cout<<b.add(3)<<std::endl;
  std::cout<<b.add(4)<<std::endl;
  std::cout<<b.add(5)<<std::endl;
  std::cout<<b.add(6)<<std::endl;
  c = a - b;
  c.display();
  std::cout<<std::endl;
  d = a + b;
  d.display();
  std::cout<<std::endl;
  return 0;
}
