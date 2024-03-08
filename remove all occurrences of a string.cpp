#include <iostream>
#include <string>
using namespace std;

void removeStringOccurrences(string& paragraph, const string& str) {
    size_t pos = 0;
    while ((pos = paragraph.find(str, pos)) != string::npos) {
        paragraph.erase(pos, str.length());
    }
    // do this another way without using string::npos just do it using simple loops and logi
    // for (int i = 0; i < paragraph.size(); i++) {
    //     if (paragraph.substr(i, str.size()) == str) {
    //         paragraph.erase(i, str.size());
    //     }
    // }
    

}

int main() {
    string paragraph = "This is a sample paragraph with example of some occurrences of the word 'example'.";
    string str = "example";

    removeStringOccurrences(paragraph, str);

    cout << "Modified paragraph: " << paragraph << endl;

    return 0;
}