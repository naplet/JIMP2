

#include "Counts.h"
namespace datastructures {
    Counts::Counts() {
        counter = 1;
    }

    Counts::Counts(int number) {
        counter = number;
    }

    int Counts::GetCounts() const {
        return counter;
    }

    Counts::operator int() const {
        return counter;
    }

    bool Counts::operator<(const Counts &other) {
        return GetCounts() < other.GetCounts();
    }

    bool Counts::operator==(const Counts &other) {
        return GetCounts() == other.GetCounts();
    }

    bool Counts::operator>(const Counts &other) {
        return GetCounts() > other.GetCounts();
    }

    Counts &Counts::operator++() {
        counter++;
        return *this;
    }

    Counts Counts::operator++(int foo) {
        Counts tmp(counter_);
        ++counter;
        return tmp;
    }
}