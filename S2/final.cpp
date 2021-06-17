// Goal: a Friend information system allow you to add, delete and check your friends

#include <iostream>
#include <map>
#include <string>

using namespace std;

class Friend {
  public:
    Friend(string birthday, string phone, string email) {
      this -> birthday = birthday;
      this -> phone = phone;
      this -> email = email;
    }

    string getBirthday() {
      return birthday;
    }
    string getPhone() {
      return phone;
    }
    string getEmail() {
      return email;
    }
    void print() {
        cout << "birthday: " << birthday << endl;
        cout << "phone: " << phone << endl;
        cout << "email: " << email << endl;
    }

  private:
    string birthday;
    string phone;
    string email;
};

string reader(string prompt) {
  cout << prompt << ": ";
  string z;
  cin >> z;
  return z;
}

int main(int argc, char const *argv[]) {

  map<string, Friend> mapFriends;
  map<string, Friend>::iterator iter;

  printf("This is your friends address book\n");
  while(true) {
    printf("Contents: \n");
    printf("0. Leave\n");
    printf("1. Add new friend\n");
    printf("2. List all friends\n");
    printf("3. Delete a friend by name\n");
    int mode;
    cin >> mode;
    cout << endl;

    switch (mode) {
      case 1:{
        string name = reader("name");
        mapFriends.insert(pair<string, Friend>(name, Friend(reader("birthday"), reader("phone"), reader("email"))));
      }
        break;
      case 2:
        if(mapFriends.size() == 0) cout << "---empty---";
        for(iter = mapFriends.begin(); iter != mapFriends.end(); iter++) {
          Friend _friend = iter -> second;
          cout << "name: " << iter -> first << endl;
          _friend.print();
      }
        break;
      case 3: {
        string name = reader("name");
        iter = mapFriends.find(name);
        if(iter == mapFriends.end()) {
          cout << name << " not found, please try again.";
        }else {
          cout << name << " is deleted.";
          mapFriends.erase(iter);
        }
      }
        break;
      default:
        return 0;
    }
    cout << "\n\n\n\n";
  }
}
