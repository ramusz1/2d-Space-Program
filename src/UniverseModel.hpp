#pragma once

#include <memory>

#include "models/Drawable.hpp"

using namespace std;

class UniverseModel{
private:
    vector< unique_ptr<Drawable> > worldObjects;

public:
    UniverseModel();
    const vector<unique_ptr<Drawable> >& getWorldObjects() const;
};