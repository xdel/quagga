/*
 * bgp_rpki.h
 *
 *  Created on: 15.02.2013
 *      Author: Michael Mester
 */

#ifndef BGP_RPKI_H_
#define BGP_RPKI_H_
//#include "rtrlib/rtrlib.h"
#include <stdbool.h>
#include "prefix.h"
#include "bgpd/bgp_attr.h"
#include "bgpd/bgpd.h"
/**********************************/
/** Declaration of debug makros  **/
/**********************************/
#define debug 1
#define RPKI_DEBUG(...) \
  if(debug){zlog_debug("RPKI: "__VA_ARGS__);}
#define TO_STRING(s) str(s)
#define str(s) #s

/**********************************/
/** Declaration of constants     **/
/**********************************/
#define CMD_POLLING_PERIOD_RANGE "<0-3600>"
#define CMD_TIMEOUT_RANGE "<1-4294967295>"
#define POLLING_PERIOD_DEFAULT 1000
#define TIMEOUT_DEFAULT 1000
#define RPKI_VALID      1
#define RPKI_UNKNOWN    2
#define RPKI_INVALID    3
/**********************************/
/** Declaration of variables     **/
/**********************************/
struct list* cache_group_list;
unsigned int polling_period;
unsigned int timeout;

/**********************************/
/** Declaration of functions     **/
/**********************************/
void rpki_start(void);
void rpki_test(void);
void rpki_init(void);
void rpki_finish(void);
//static void update_cb(struct pfx_table* p, const pfx_record rec, const bool added);
int validate_prefix(struct peer *peer, struct prefix *p, struct attr *attr);
bool validation_policy_check(int validation_result);

#endif /* BGP_RPKI_H_ */