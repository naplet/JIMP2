
#include "WordCounter.h"
namespace datastructures {

WordCounter::WordCounter() {
    this->total_words_counter = 0;
    this->distinct_words_counter = 0;
}
WordCounter::~WordCounter() {
    delete &this->distinct_words_counter;
    delete &this->map;
    delete &this->null_counter;
    delete &this->total_words_counter;
    delete &this->words;
}
    WordCounter::WordCounter(const std::initializer_list <Word> &new_words) {
        bool flag;
        this->total_words_counter = 0;
        this->distinct_words_counter = 0;

        for(auto &new_word : new_words) {
            flag = false;

            for(auto &i : this->words)
                if(new_word.GetWord() == i.GetWord()) {
                    flag = true;
                }

            if(flag) {
                this->total_words_counter++;
                auto it = map.find(new_word.GetWord());
                if(it != map.end()) {
                    ++it->second;
                }
            }

            else {
                this->words.push_back(new_word);
                this->total_words_counter++;
                this->distinct_words_counter++;
                map.insert({new_word.GetWord(), 1});
            }
        }
    }
int WordCounter::DistinctWords() {
    return this->distinct_words_counter;
}

int WordCounter::TotalWords() {
    return this->total_words_counter;
}

std::set<Word> WordCounter::Words() {
    std::set<Word> output;
    for(auto &i : this->words)
        output.emplace(i);
    return output;
}

Counts& WordCounter::operator[](std::string id) {
    auto it = this->map.find(id);

    if(it != this->map.end())
        return it->second;

    return this->null_counter;
}

bool operator==(const std::set<Word> &first, const std::vector<Word> &second) {
    return (first == second);
}

}




