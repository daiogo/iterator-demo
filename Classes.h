#pragma once

#include <string>
#include <vector>
#include "MyIterator.h"

class Farm;

class FarmAsset : public MyIterator {
protected:
    Farm *farm_ptr;
    int cow_idx;
    int sheep_idx;
    int tractor_idx;

public:
    FarmAsset();
    FarmAsset(Farm* f);
    virtual void make_sound();

    // Iterator functions
    bool has_next();
    void next();
    FarmAsset* current();
};

class Animal : public FarmAsset {
protected:
    std::string name;
    std::string vocalization;

public:
    Animal();
    std::string get_name();
    void make_sound();
};

class Cow : public Animal {
private:

public:
    Cow();
    Cow(std::string n);
};

class Sheep : public Animal {
private:

public:
    Sheep();
    Sheep(std::string n);
};

class Tractor : public FarmAsset {
private:
    std::string brand;

public:
    Tractor();
    Tractor(std::string b);
    std::string get_brand;
    void make_sound();

};

class Farm : public MyIterableDataStructure {
private:
    std::vector<Cow> cows;
    std::vector<Sheep> sheep;
    std::vector<Tractor> tractors;

public:
    Farm();
    FarmAsset get_iterator();
    std::vector<Cow>* get_cows();
    std::vector<Sheep>* get_sheep();
    std::vector<Tractor>* get_tractors();
};


