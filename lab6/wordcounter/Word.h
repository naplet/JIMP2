

#ifndef JIMP_EXERCISES_WORD_H
#define JIMP_EXERCISES_WORD_H
#include <iostream>
#include <memory>
#include <set>
#include <string>
namespace datastructures{
    class Word {
    public:
        Word();

        ~Word();

        explicit Word(std::string new_word);

        std::string GetWord() const;

    private:
        std::string word;

    };
    std::ostream& operator<<(std::ostream &output, Word word);
    bool operator<(const Word &first, const Word &second);
    bool operator==(const Word &first, const Word &second);
}
#endif //JIMP_EXERCISES_WORD_H
