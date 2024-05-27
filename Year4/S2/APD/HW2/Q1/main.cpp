#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct CharacterBag {
    int NumOfChars;
    char Characters[128]; // Assuming maximum 128 characters per bag
};

int main() {
    const int NUM_BAGS = 32;  // 32 bags
    vector<CharacterBag> CBags(NUM_BAGS);

    // Get number of characters for each bag
    for (int i = 0; i < NUM_BAGS; i++) {
        cout << "Enter number of characters for bag " << i + 1 << ": ";
        cin >> CBags[i].NumOfChars;

        // Input validation: Ensure characters don't exceed 128
        CBags[i].NumOfChars = min(CBags[i].NumOfChars, 128); 
    }

    // Get characters for each bag
    for (int i = 0; i < NUM_BAGS; i++) {
        cout << "Enter characters for bag " << i + 1 << ": ";
        cin.ignore(); // Clear leftover newline from previous input

        // Read the specified number of characters or a maximum of 128
        for (int j = 0; j < CBags[i].NumOfChars; j++) {
            CBags[i].Characters[j] = cin.get(); // Read a single character
        }
    }

    // Output characters in each bag
    cout << "\nCharacters in each bag:\n";
    for (int i = 0; i < NUM_BAGS; i++) {
        cout << "Bag " << i + 1 << ": ";
        for (int j = 0; j < CBags[i].NumOfChars; j++) {
            cout << CBags[i].Characters[j];
        }
        cout << endl;
    }

    return 0;
}
