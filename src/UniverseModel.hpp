#pragma once

#include "models/Drawable.hpp"

class UniverseModel{
private:
    vector<Drawable> worldObjects;

public:
    UniverseModel();
    const vector<Drawable>& getWorldObjects() const;
    static vector<Drawable> test();    
};