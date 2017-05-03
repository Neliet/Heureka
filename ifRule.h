#ifndef IFRULE_H_INCLUDED
#define IFRULE_H_INCLUDED

#include "clause.h"
struct IfRule {
    Clause head;
    Clause tail;
};

#endif // IFRULE_H_INCLUDED
