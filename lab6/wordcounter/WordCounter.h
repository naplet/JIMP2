

#ifndef JIMP_EXERCISES_WORDCOUNTER_H
#define JIMP_EXERCISES_WORDCOUNTER_H


#include <iostream>
#include <string>
#include <memory>
#include <set>
#include <initializer_list>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <fstream>
#include "Word.h"
#include "Counts.h"
namespace datastructures{
    class WordCounter {
    public:
        WordCounter() = default;
        WordCounter(const std::initializer_list<Word> &argument);
        WordCounter(string path_to_file);

        int operator[](const string &key);
        friend std::ostream &operator<<(std::ostream &os, WordCounter &wordCounter);
        int TotalWords() const;
        int DistinctWords() const;
        std::set<Word> Words() const;

    private:
        std::vector<std::pair<Word,Counts>> words_list_;

    };
    std::ostream &operator<<(std::ostream &os, WordCounter &wordCounter);
}

#endif //JIMP_EXERCISES_WORDCOUNTER_H
