// dear emacs, please treat this as -*- C++ -*-

#include "internal.h"

static SEXP __pomp_ptr_userdata;
#define USERDATA  (__pomp_ptr_userdata)

void set_pomp_userdata (SEXP userdata) {
  if (LENGTH(userdata) > 0) {
    USERDATA = userdata;
  } else {
    USERDATA = R_NilValue;
  }
}

const SEXP get_userdata (const char *name) {
  SEXP elt = getListElement(USERDATA,name);
  if (isNull(elt)) err("no user-data element '%s' is found.",name);
  return elt;
}

const int *get_userdata_int (const char *name) {
  SEXP elt = getListElement(USERDATA,name);
  if (isNull(elt)) err("no user-data element '%s' is found.",name);
  if (!isInteger(elt)) err("user-data element '%s' is not an integer.",name);
  return INTEGER(elt);
}

const double *get_userdata_double (const char *name) {
  SEXP elt = getListElement(USERDATA,name);
  if (isNull(elt)) err("no user-data element '%s' is found.",name);
  if (!isReal(elt)) err("user-data element '%s' is not a numeric vector.",name);
  return REAL(elt);
}

// WILL GO AWAY SOON
void unset_pomp_userdata (void) { // #nocov
  USERDATA = R_NilValue;          // #nocov
}
