#include <iostream>
#include <string>
using namespace std;

int main(){
    string sentence[101];
    int index = 0;
    int maxchar = 0;

    while (getline(cin, sentence[index])) {
        if (maxchar < sentence[index].length()){ // find out the max length of strings
            maxchar = sentence[index].length();
        }
        index++;
    }

    for (int i = 0; i < maxchar; i++){
        for (int j = index-1; j >= 0; j--){
            if (sentence[j].length() > i){
                cout << sentence[j][i];
            } else {
                cout << " ";
            }
        }
        cout << endl;
    }
    return 0;
}