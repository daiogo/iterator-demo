#include <iostream>
#include "Classes.h"

// ==================== Base types ====================
Animal::Animal()
{

}

Cow::Cow(std::string n)
{
    name = n;
    vocalization = "Mooo!";
}

Sheep::Sheep(std::string n)
{
    name = n;
    vocalization = "Baaah!";
}

Tractor::Tractor(std::string b)
{
    brand = b;
}

std::string Animal::get_name()
{
    return name;
}

void Animal::make_sound()
{
    std::cout << name << " makes " << vocalization << std::endl;
}

void Tractor::make_sound()
{
    std::cout << brand << " makes Vrummmm!" << std::endl;
}

// ==================== Farm ====================
Farm::Farm()
{

}

FarmAsset Farm::get_iterator()
{
    return FarmAsset(this);
}

std::vector<Cow>* Farm::get_cows()
{
    return &cows;
}

std::vector<Sheep>* Farm::get_sheep()
{
    return &sheep;
}

std::vector<Tractor>* Farm::get_tractors()
{
    return &tractors;
}


// ==================== FarmAsset ====================
FarmAsset::FarmAsset()
{

}

FarmAsset::FarmAsset(Farm* f)
{
    farm_ptr = f;
    cow_idx = 0;
    sheep_idx = 0;
    tractor_idx = 0;
}

void FarmAsset::make_sound()
{

}

bool FarmAsset::has_next()
{
    bool is_done = true;

    if (cow_idx < farm_ptr->get_cows()->size() ||
        sheep_idx < farm_ptr->get_sheep()->size() ||
        tractor_idx < farm_ptr->get_tractors()->size())
    {
        is_done = true;
    }
    else
    {
        cow_idx = 0;
        sheep_idx = 0;
        tractor_idx = 0;
        is_done = false;
    }

    return is_done;
}

void FarmAsset::next()
{
    if (cow_idx < farm_ptr->get_cows()->size())
    {
        cow_idx++;
    }
    else if (sheep_idx < farm_ptr->get_sheep()->size())
    {
        sheep_idx++;
    }
    else if (tractor_idx < farm_ptr->get_tractors()->size())
    {
        tractor_idx++;
    }
}

FarmAsset* FarmAsset::current()
{
    FarmAsset *current_ptr;

    if (cow_idx < farm_ptr->get_cows()->size())
    {
        current_ptr = &farm_ptr->get_cows()->at(cow_idx);
    }
    else if (sheep_idx < farm_ptr->get_sheep()->size())
    {
        current_ptr = &farm_ptr->get_sheep()->at(sheep_idx);
    }
    else if (tractor_idx < farm_ptr->get_tractors()->size())
    {
        current_ptr = &farm_ptr->get_tractors()->at(tractor_idx);
    }

    return current_ptr;
}


