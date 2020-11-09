#ifndef CONFIG_PERRYW_FC660C_H
#define CONFIG_PERRYW_FC660C_H

#include "../../config.h"

// Set up tapdance functionality
#define TAPPING_TOGGLE 1
// TAPPING_TERM is set in config.h this defaults to 200

// This makes it possible to do rolling combos (zx) with keys that convert to other keys on hold (z becomes ctrl when
// you hold it, and when this option isn't enabled, z rapidly followed by x actually sends Ctrl-x. That's bad.)
#define IGNORE_MOD_TAP_INTERRUPT

#endif
