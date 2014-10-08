#include "sunsystem.hpp"

using namespace cg;


void Sunsystem::run()
{
    root->data->resultmatrix = root->data->orbit_rotation * root->data->orbit;
    for(Leaf<Planet> *n : root->childs)
    {
        run(n, root->data->resultmatrix);
    }
    // save finalMatrix
    root->data->resultmatrix *= root->data->rotation *= root->data->scale;
}

void Sunsystem::run(Leaf<Planet> *currentPlanet, QMatrix4x4 &mat)
{
    currentPlanet->data->resultmatrix = mat * currentPlanet->data->orbit_rotation
            * currentPlanet->data->orbit;
    for(Leaf<Planet> *n : currentPlanet->childs)
    {
        run(n, currentPlanet->data->resultmatrix);
    }
    // save finalMatrix
    currentPlanet->data->resultmatrix *= currentPlanet->data->rotation * currentPlanet->data->scale;
}
