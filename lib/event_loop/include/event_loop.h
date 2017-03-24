#ifndef XENON_EVENT_LOOP_EVENT_LOOP_H
#define XENON_EVENT_LOOP_EVENT_LOOP_H

#include "ts_queue/ts_queue.h"
#include "ts_map/ts_map.h"

typedef struct event {
    int type;
} event_t;

#define EXIT_EVENT_TYPE 0
extern event_t EXIT_EVT;

typedef void (* evt_handler_t)(event_t *);

typedef struct event_loop {
    ts_map_t handlers, deleters;
    ts_queue_t event_queue;
} event_loop_t;

void event_loop_init(event_loop_t *el);
void event_loop_destroy(event_loop_t *el);

void run_event_loop(event_loop_t *el);

void send_event(event_loop_t *el, event_t *evt);

#endif /* XENON_EVENT_LOOP_EVENT_LOOP_H */
