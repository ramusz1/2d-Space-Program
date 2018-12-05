#include <set>

#include "glm/glm.hpp"

// class made for fun
class SetOfPairsView
{
public:
    using iterator_category = std::input_iterator_tag;
    using value_type = double;
    using difference_type = std::set< std::pair<double, int> >::iterator::difference_type;
    using pointer = double*;
    using reference = double&;

    void operator++();
    double operator*();
    bool operator!=(const SetOfPairsView& r);

    SetOfPairsView(std::set< std::pair<double, int> >::iterator inputIterator);

private:
    std::set< std::pair<double, int> >::iterator baseIterator;
};

class Accumulator
{
public:
    using value_type=double;

    double getValue();
    void push_back(double);
private:
    double value = 0;
};