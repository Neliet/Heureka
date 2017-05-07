#ifndef FILEREADING_H_INCLUDED
#define FILEREADING_H_INCLUDED

#include <vector>
#include <string>
#include <iostream>
#include <fstream>

#include "map.h"
#include "knowledgeBase.h"

Map readMap(const std::string& filename);

KnowledgeBase readKnowledgeBase(const std::string& filename);

#endif // FILEREADING_H_INCLUDED
