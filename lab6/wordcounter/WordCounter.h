

#ifndef JIMP_EXERCISES_WORDCOUNTER_H
#define JIMP_EXERCISES_WORDCOUNTER_H


#include <iostream>
#include <string>
#include <memory>
#include <set>
#include <initializer_list>
#include <vector>
#include <unordered_map>
#include "Word.h"
#include "Counts.h"
namespace datastructures {

    class WordCounter {
    public:
        WordCounter();
        ~WordCounter();
        WordCounter(const std::initializer_list<Word> &new_words);
        int DistinctWords();
        int TotalWords();
        std::set<Word> Words();
        Counts& operator[](std::string id);

    private:
        std::vector<Word> words;
        std::unordered_map<std::string, Counts> map;
        int total_words_counter;
        int distinct_words_counter;
        Counts null_counter;
    };

    bool operator==(const std::vector<Word> &first, const std::vector<Word> &second);
}

#endif //JIMP_EXERCISES_WORDCOUNTER_H
