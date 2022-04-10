#include <bits/stdc++.h>

using namespace std ;

class Item
{
    public :
        Item() : marketPrice(0), itemName(""), itemPreference(0) {}
        void setIP(int ip) { itemPreference = ip ; }
        void setMP(int mp) { marketPrice = mp ; }
        void setIN(string in) { itemName = in ; }
        int getIP() { return itemPreference ; }
        int getMP() { return marketPrice ; }
        string getIN() { return itemName ; }
        string toString() {
          return to_string(itemPreference) + " " + itemName + " " + to_string(marketPrice);
        }
    private :
        int marketPrice ;
        string itemName ;
        int itemPreference ;
} ;

int main(int argc, char const **argv)
{
    int n ; // number
    int mp ; // market price
    int bc ; // budget cap
    int ip ; // item preference

    string in ; // item name
    cin >> n >> bc ;

    int c[bc + 1] = {0};
    map<int, vector<Item>> map;

    Item it[n] = {} ;
    for(int i = 0 ; i < n ; i++)
    {
        cin >> ip >> in >> mp ;
        it[i].setIP(ip) ;
        it[i].setMP(mp) ;
        it[i].setIN(in) ;
    }
    for (auto item : it) {
      for (int i = bc; i - item.getMP() >= 0 ; i--) {
        if(c[i] < c[i - item.getMP()] + item.getIP()) {
          c[i] = c[i - item.getMP()] + item.getIP();
          map[i].push_back(item);
        }
      }
    }

    for (int i = bc ; i < bc + 1 ; i++) {
      cout<<c[i] << " ";
      vector<Item>::iterator it_i;
      for(it_i=map[i].begin(); it_i!=map[i].end(); ++it_i) {
        cout << it_i -> getIN() << " ";
      }
      cout<<endl;
    }

    return 0 ;
}
