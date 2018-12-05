#include <set>

#include "glm/glm.hpp"

#include "MergingTools.hpp"
#include <iostream>

SetOfPairsView::SetOfPairsView(std::set< std::pair<double, int> >::iterator inputIterator):
    baseIterator(inputIterator)
{}

void SetOfPairsView::operator++()
{
    baseIterator++;
}

double SetOfPairsView::operator*()
{
    return baseIterator->first;
}

bool SetOfPairsView::operator!=(const SetOfPairsView& r){
    return this->baseIterator != r.baseIterator;
}


double Accumulator::getValue(){
    return value;
}

void Accumulator::push_back(double x){
    value += x;
}