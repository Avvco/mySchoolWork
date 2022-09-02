/**
 * Map
 * 
 * @Description:
 * Please use your "Red_Black_Tree" and "Pair" to finish the class "Map" to fulfill the request.
 * It is suggested to inherit from your "Red_Black_Tree".
 * You can add or modify any function or variable if you want.
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
 * A TreeNode class of binarySearchTree class
 */
template<class T>
class TreeNode {
  public: 

  private:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;
};

/**
 * A binarySearchTree abstract class for BinarySearchTree class
 */
template<class T>
class binarySearchTree {
  public:
    /**
     * Preorder traversal of the tree
     */
    virtual void preorder() = 0;

    /**
     * Inorder traversal of the tree
     */
    virtual void inorder() = 0;

    /**
     * Postorder traversal of the tree
     */
    virtual void postorder() = 0;

    /**
     * Levelorder traversal of the tree
     */
    virtual void levelorder() = 0;

    /**
     * Insert data into the tree if the value is not present
     * @param data data to insert
     * @return true if insert successfully, false if the value is already present
     */
    virtual bool insert(T data) = 0;

    /**
     * Set the value of the root
     * @param data to set to root
     */
    virtual void setRoot(T data) = 0;

    /**
     * Search the tree for the given value
     * @param target target to find
     * @return true if found, false if not found
     */
    virtual bool serach(T target) = 0;

    /**
     * Deserialize the string to a tree with levelorder traversal
     * @param tree to be deserialized
     */
    virtual void deSerialize(string tree) = 0;

    /**
     * Serialize the tree to a string with levelorder traversal
     * @return the serialized string
     */
    virtual string serialize() = 0;
  protected:
    TreeNode<T> *root;
};

template<class T>
class BinarySearchTree : public binarySearchTree<T> {
    public:
    void preorder()  {}
    void inorder() {}
    void postorder() {}
    void levelorder() {}
    bool insert(T data) {}
    void setRoot(T data) {}
    bool serach(T target) {};
    void deSerialize(string tree) {}
    string serialize() {}
};

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

template <class T>
class Red_Black_Tree : public BinarySearchTree<T> {

};

/**
 * @brief Class for Map
 * 
 * @tparam K data type for key of the map
 * @tparam V data type for value of the map
 */
template <class K, class V>
class Map : public Red_Black_Tree<Pair<K, V>> {
  public: 

    // alias the type
    typedef Pair<K, V> MapType;

    /**
     * @brief Traverse the tree with inorder traversal
     */
    class Iterator{
      public:
        // Implement the function you need.
        Iterator() {}

        // Overload the operators
        MapType* operator->() const {}
        MapType& operator*() const {}

        Iterator& operator++() {}
        Iterator operator++(int) {}
					
      private:
        TreeNode<MapType> *current;
    };  

  /**
   * @brief Overload the operator []
   */
  V& operator[](const K& k) {}

  /** 
   * @return Iterator pointing to the first element in the map
   */
  Iterator begin() {}

  /**
   * @return Iterator pointing to one past the last element in the map
   */
  Iterator end() {}

  // comparison operators on iterator
  friend bool operator==(const Iterator& _iter1, const Iterator& _iter2) {}
  friend bool operator!=(const Iterator& _iter1, const Iterator& _iter2) {}

  // Implement the function you need.
};

int main() {
  Map<string, int> map;
  // Inserting data to Map
  Pair<string, int> p1("earth", 1);
  Pair<string, int> p2("moon", 2);
  Pair<string, int> p3(p2);

  // insert the pair into the map only if key not exist.
  map.insert(p1);
  map.insert(p2);
  map.insert(p3);

  // Will replace the value of already added key.
  map["sun"] = 3;
  map["earth"] = 4;

  // Iterate through all elements in Map
  Map<string, int>::Iterator it = map.begin();
  while(it != map.end()) {
    cout<<it->first<<" :: "<<(*it).second<<endl;
    it++;
  }
  // Check if insertion is successful or not
  if(map.insert(p1) == false) {
    cout<<"Element with key 'earth' not inserted because already existed"<<endl;
  }
  return 0;
}