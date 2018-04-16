
#include "WordCounter.h"
using namespace datastructures;
Word::Word() {}
Word::~Word() {
    delete &this->word;
}
Word::Word(std::string new_word) {
    this->word=new_word;
}
std::string Word::GetWord() const {
    return this->word;
}

Counts::Counts() {}
Counts::~Counts() {
    delete &this->Count;
}
Counts::Counts(int new_count) {
    this->Count= new_count;
}
int Counts::GetCounts() const {
    return this->Count;
}
Counts& Counts::operator++() {
    this->Count++;
    return *this;
}

WordCounter::WordCounter() {}
WordCounter::~WordCounter(){
    delete &this->distinct_words_counter;
    delete &this->map;
    delete &this->null_counter;
    delete &this->total_words_counter;
    delete &this->words;

}
int WordCounter::TotalWords() {
    return this->total_words_counter;
}
int WordCounter::DistinctWords() {
    return this->distinct_words_counter;
}

Counts& WordCounter::operator[](std::string id){
    auto it = this->map.find(id);

    if(it != this->map.end())
        return it->second;

    return this->null_counter;
}
WordCounter::WordCounter(const std::initializer_list<datastructures::Word> &new_words) {
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
//bool operator==(const std::set<datastructures::Word> &first, const std::vector<datastructures::Word> &second){
    //return (first==second);
//}
std::set<Word> WordCounter::Words() {
    std::set<Word> output;
    for(auto &i : this->words)
        output.emplace(i);
    return output;
}
bool operator==(const Counts &first, const Counts &second) {
    return (first.GetCounts() == second.GetCounts());
}

bool operator==(const Counts &first, int second) {
    return (first.GetCounts() == second);
}

bool operator==(int second, const Counts &first) {
    return (first.GetCounts() == second);
}
std::ostream& operator<<(std::ostream &output, Word word) {
    output<<word.GetWord();

    return output;

}

bool operator<(const Word &first, const Word &second) {
    return (first.GetWord() < second.GetWord());
}

bool operator==(const Word &first, const Word &second) {
    return (first.GetWord() == second.GetWord());
}

bool operator==(const std::set<Word> &first, const std::vector<Word> &second) {
    return (first == second);
}
