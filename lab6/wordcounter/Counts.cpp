

#include "Counts.h"
namespace datastructures {
    Counts::Counts() {
        this->counts = 0;
    }

    Counts::~Counts() {
        delete &this->Count;
    }

    Counts::Counts(int new_count) {
        this->Count = new_count;
    }

    int Counts::GetCounts() const {
        return this->Count;
    }

    Counts &Counts::operator++() {
        this->Count++;
        return *this;
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
    void Counts::SetCounts(int new_value) {
        this->counts=new_value;
    }
}