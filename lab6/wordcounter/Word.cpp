
#include "Word.h"
namespace datastructures {
    Word::Word() {}

    Word::~Word() {
        delete &this->word;
    }

    Word::Word(std::string new_word) {
        this->word = new_word;
    }

    std::string Word::GetWord() const {
        return this->word;
    }

    std::ostream &operator<<(std::ostream &output, Word word) {
        output << word.GetWord();

        return output;

    }

    bool operator<(const Word &first, const Word &second) {
        return (first.GetWord() < second.GetWord());
    }

    bool operator==(const Word &first, const Word &second) {
        return (first.GetWord() == second.GetWord());
    }
}