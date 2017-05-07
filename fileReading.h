#ifndef FILEREADING_H_INCLUDED
#define FILEREADING_H_INCLUDED

#include <vector>
#include <string>
#include <iostream>
#include <fstream>

#include "graph.h"
#include "road.h"
#include "crossing.h"
#include "clause.h"
#include "ifRule.h"

using Map = Graph<Crossing, Road>;
Map readMap(const std::string& filename);

using KnowledgeBase = Graph<Clause, IfRule>;
KnowledgeBase readKnowledgeBase(const std::string& filename);

#endif // FILEREADING_H_INCLUDED
