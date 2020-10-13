#include <stdio.h>
#include <assert.h>


int main(int argc, char const * argv[]) {
    char buffer[3];
    int alice = 0, bob = 0;

    for (size_t i = 0; i < 5; i++) {
        // Get 2 characters in one line.
        fgets(buffer, 3, stdin);

        // Utilizes getchar() to flush newline from input buffer.
        getchar();

        //while(getchar() != '\0' || getchar() != '\n');

        // A easy exception handling.
        assert((buffer[0] == 'P' || buffer[0] == 'S' || buffer[0] == 'R'));
        assert((buffer[1] == 'P' || buffer[1] == 'S' || buffer[1] == 'R'));

        // Compare all conditions. If conditions weren't happend, it means a draw.
        if ((buffer[0] == 'P' && buffer[1] == 'R') || (buffer[0] == 'S' && buffer[1] == 'P') || (buffer[0] == 'R' && buffer[1] == 'S')) {
            alice += 1;
        }
        if ((buffer[1] == 'P' && buffer[0] == 'R') || (buffer[1] == 'S' && buffer[0] == 'P') || (buffer[1] == 'R' && buffer[0] == 'S')) {
            bob += 1;
        }
    }

    // Print the result.
    if (alice > bob) {
        printf("Alice \n");
    }
    else if (bob > alice) {
        printf("Bob \n");
    }
    else {
        printf("Draw \n");
    }

    return 0;
}
