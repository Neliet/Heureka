#ifndef FILEREADING3_H_INCLUDED
#define FILEREADING3_H_INCLUDED

#include <vector>
#include <string>
#include <iostream>
#include <fstream>

#include "graph.h"
#include "clause.h"
#include "kb.h"

using Map = Graph<Clause, KB>;

Map readMap3(const std::string& filename);

#endif // FILEREADING3_H_INCLUDED
