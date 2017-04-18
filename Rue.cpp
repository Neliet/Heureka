#include <vector>
#include <istream>
#include <string>

#include "Rue.h"

//Constructeur
Crossing::Corssing(int x, int y)
{
    m_x = x;
    m_y = y;
}

std::vector<Crossing> Crossing::getSucessor()
{
    return m_sucessor;
}

std::vector<int,int> Crossing::getState()
{
    return [x y];
}

void Crossing::setSucessor(Crossing next, std::string street)
{
    m_sucessor.append(next);
}




