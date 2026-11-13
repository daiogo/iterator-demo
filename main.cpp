#include "Classes.h"

int main()
{
    // Create iterable object and populate data structure
    Farm f;
    f.get_sheep()->push_back(Sheep("Shirley"));
    f.get_sheep()->push_back(Sheep("Sheila"));
    f.get_cows()->push_back(Cow("Mimosa"));
    f.get_tractors()->push_back(Tractor("John Deere"));
    f.get_tractors()->push_back(Tractor("New Holland"));
    f.get_tractors()->push_back(Tractor("Massey Ferguson"));

    /*
    for(int i = 0; i < f.get_tractors()->size(); i++)
    {
        f.get_tractors()->at(i).make_sound();
    }
    */

    FarmAsset it = f.get_iterator();
    while (it.has_next())
    {
        // Use current object
        it.current()->make_sound();

        // Move the pointer to the next object
        it.next();
    }

    return 42;
}
