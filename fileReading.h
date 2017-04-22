#ifndef OPENING_H_INCLUDED
#define OPENING_H_INCLUDED

#include <vector>
#include <string>
#include <iostream>
#include <fstream>

#include "graph.h"
#include "road.h"
#include "crossing.h"

using Map = Graph<Crossing, Road>;

Map readMap(const std::string& filename);

#endif // OPENING_H_INCLUDED
