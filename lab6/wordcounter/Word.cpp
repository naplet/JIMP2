
#include "Word.h"

namespace datastructures{
    Word::Word() {
        word="";
    }

    Word::Word(string str) {
        word=str;
    }

    string Word::GetWord() const {
        return word;
    }

    bool Word::operator<(const Word &other) const {
        return word < other.GetWord();
    }

    bool Word::operator>(const Word &other) const {
        return word > other.GetWord();
    }

    bool Word::operator==(const Word &other) const {
        return word == other.GetWord();
    }

    Word::operator string() const {
        return word;
    }
}
