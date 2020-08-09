#include <iostream>
#include <algorithm>
#include <string>
#define endl '\n'

using namespace std;

int testCase;

void swap(char& a, char& b) {
	char temp = a;
	a = b;
	b = temp;
}

string getNextWord(string word){
	int lastIdx = word.length() - 1;
	
	for(int compLen = 1; compLen <= lastIdx; ++compLen){
		for(int i = lastIdx; i > lastIdx - compLen; --i){
			if (word[i] > word[lastIdx - compLen]) {
				swap(word[i], word[lastIdx - compLen]);
				sort(word.begin() + lastIdx - compLen + 1, word.end());
				return word;
			}
		}
	}
	return word;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> testCase;
	string word;

	while (testCase--) {
		cin >> word;
		cout << getNextWord(word) << endl;
	}
}