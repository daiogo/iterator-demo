#include "Classes.h"

int main()
{
    Farm f;
    FarmAsset it = f.get_iterator();

    /*
    for(int i = 0; i < f.get_tractors()->size(); i++)
    {
        f.get_tractors()->at(i).make_sound();
    }
    */

    while (it.has_next())
    {
        // Use current object
        it.current()->make_sound();

        // Move the pointer to the next object
        it.next();
    }

    return 42;
}
