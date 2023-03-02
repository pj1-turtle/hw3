#ifndef EVENT_H
#define EVENT_H
#include "wire.h"

struct Event
{
    uint64_t time;
    Wire* wire;
    char state;
};

typedef struct EventLess {
		bool operator()(Event* l, Event* r) const {
			return l->time < r->time;
	}

        //write the operator() required to make this a functor that compares Events by time
} EventLess;
	
#endif
