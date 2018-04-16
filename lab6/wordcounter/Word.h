

#ifndef JIMP_EXERCISES_WORD_H
#define JIMP_EXERCISES_WORD_H
#include <iostream>
#include <memory>
#include <set>
#include <string>
using std::string;
namespace datastructures{
    class Word {
    public:
        // constructors:
        Word();
        Word(string str);

        string GetWord() const;

        bool operator==(const Word &other) const;
        bool operator<(const Word &other) const;
        bool operator>(const Word &other) const;;
        operator string() const;

    private:
        std::string word;
    };
}
#endif //JIMP_EXERCISES_WORD_H
