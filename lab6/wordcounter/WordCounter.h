

#ifndef JIMP_EXERCISES_WORDCOUNTER_H
#define JIMP_EXERCISES_WORDCOUNTER_H


#include <iostream>
#include <string>
#include <memory>
#include <set>
#include <initializer_list>
#include <vector>
#include <unordered_map>

namespace datastructures {
    class Word {
    public:
        Word();

        ~Word();

        explicit Word(std::string new_word);

        std::string GetWord() const;





    private:
        std::string word;
    };


    class Counts {
    public:
        Counts();

        ~Counts();

        Counts(int new_count);

        int GetCounts() const;

        void SetCounts(int new_value);

        Counts &operator++();


    private:
        int Count;
    };

    class WordCounter {
    public:
        WordCounter();

        ~WordCounter();

        WordCounter(const std::initializer_list<datastructures::Word> &new_words);

        int DistinctWords();

        int TotalWords();

        std::set<datastructures::Word> Words();

        Counts &operator[](std::string id);



    private:
        std::vector<datastructures::Word> words;
        std::unordered_map<std::string, Counts> map;
        int total_words_counter;
        int distinct_words_counter;
        Counts null_counter;
    };
    bool operator==(const std::set<datastructures::Word> &first, const std::vector<datastructures::Word> &second);
    bool operator==(const Counts &first, const Counts &second);
    bool operator==(const Counts &first, int second);
    bool operator==(int second, const Counts &first);
    std::ostream& operator<<(std::ostream &output, Word word);
    bool operator<(const Word &first, const Word &second);
    bool operator==(const Word &first, const Word &second);
    bool operator==(const std::set<Word> &first, const std::vector<Word> &second);
}

#endif //JIMP_EXERCISES_WORDCOUNTER_H
