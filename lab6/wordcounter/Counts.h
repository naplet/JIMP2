
#ifndef JIMP_EXERCISES_COUNTS_H
#define JIMP_EXERCISES_COUNTS_H
namespace datastructures {

    class Counts {
    public:
        Counts();
        Counts(int new_count);
        ~Counts();
        int GetCounts() const;
        void SetCounts(int new_value);
        Counts& operator++();

    private:
        int counts;
    };

    bool operator==(const Counts &first, const Counts &second);
    bool operator==(const Counts &first, int second);
    bool operator==(int second, const Counts &first);

}
#endif //JIMP_EXERCISES_COUNTS_H
