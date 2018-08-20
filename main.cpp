//program to solve 116 win question
#include <cmath>
#include <iostream>
#include <vector>
#include <iostream>
#include <fstream>

using namespace std; //imports and namepsace statements

#define MAX_GAMES          1000
#define DEFAULT_RSEED   1299709 //defining constants
//#define RAND_MAX
int main() {

  vector <double> probs; //vector to store game probabilities from 538

        ifstream inFS;     // Input file stream
        string fileName;
        cout << "Which database would you like to use?";
        cin >> fileName;
        inFS.open(fileName); //reading in file with game probailities from 538

        if (!inFS.is_open()) {
            cout << "Could not open file " << fileName << endl;
            return 1; //ask the user which database they would like to use for their game probabilities, then use ifstream to open
            //up the file, if it opens move on, otherwise print out an error message and return 1
        }
        int winProb;

        while (!inFS.eof()){
            inFS >> winProb;
            probs.push_back(winProb); //iterate through the game probability file and push the numbers to the win probability vector
        }
    int winc =0;
    int sim = 10000;
    int totalc = 0;
    int probn = 0; //initializing variables


    while (totalc < sim) { //while the total count is less than desired numbers of sims
        winc = 0;
        for (int i = 0; i < probs.size(); ++i) { //iterate over the probs vector
            int random = rand() % 100 + 1;  //generate a random number between 0 and 100
            if (probs.at(i) - random > 0) {
                winc++; //if the difference between the random number and the probability is greater than 0, add one to the win count
            }
        }
        if (winc > 28){
            probn++; //if the win count exceeds 28, add one to the amount of times the red sox break the win record
        }

        totalc++; //add one to the total count


    }

    cout << probn; //return the number of times over 116 wins

    return 0;
}
