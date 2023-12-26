#include <iostream>
#include <vector>
using namespace std;

int longestSublist(vector<string>& words) {
    if ( words.size() == 0){
        return 0;
    }
    vector<int> letterCount(26, 0);
    vector<int> LetterMax(26, 0);
    char Encounter = words[0][0];

    for (const string& word : words) {
        if (!word.empty()) {
            char firstLetter = tolower(word[0]);
            if (firstLetter == Encounter) {
                letterCount[firstLetter - 'a']++;
            } else {
                if (LetterMax[Encounter - 'a'] < letterCount[Encounter - 'a']) {
                    LetterMax[Encounter - 'a'] = letterCount[Encounter - 'a'];
                }
                letterCount[Encounter - 'a'] = 0;
                letterCount[firstLetter - 'a']++;
                Encounter = firstLetter;
            }
        }
    }
if (LetterMax[Encounter - 'a'] < letterCount[Encounter - 'a']) {
                    LetterMax[Encounter - 'a'] = letterCount[Encounter - 'a'];
            }
    int max = LetterMax[0];
    for (int i = 1; i <= 25; i++) {
        if (max < LetterMax[i]) {
            max = LetterMax[i];
        }
    }

    return max;
}
