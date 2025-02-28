#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

int main() {
    char sentence[256];
    printf("Enter a sentence: ");
    scanf_s("%[^\n]", sentence, (unsigned)_countof(sentence));

    std::vector<std::string> words;
    char* context = nullptr;
    char* token = strtok_s(sentence, " ", &context);
    while (token != nullptr) {
        words.push_back(token);
        token = strtok_s(nullptr, " ", &context);
    }

    std::sort(words.begin(), words.end(), [](const std::string& a, const std::string& b) {
        if (a.length() == b.length()) {
            return a < b;
        }
        return a.length() > b.length();
        });

    for (const auto& word : words) {
        printf("%s\n", word.c_str());
    }

	system("pause");

    return 0;
}
