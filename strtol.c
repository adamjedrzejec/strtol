#include <errno.h>
#include <stdio.h>
#include <ctype.h>

long strtol (const char *nPtr, char **endPtr, int base)
{
  errno = 0; /* if no error will occur, errno will not change */
  long number = 0; // WHEN FINISHED, DELETE '= 0' !!!!!!!!!!
  const char *actualPosition;
  enum signs {POSITIVE, NEGATIVE}; /* available signs */
  int sign;

  actualPosition = nPtr;

  /* Invalid argument */
  if (!((base >= 2 && base <= 36) || base == 0)){
    errno = EINVAL;
    return 0;
  }

  /* omits every blank character like space, tabulation, newline character etc. */
  while (isspace(*actualPosition))
    actualPosition++;

  /* sign checker */
  if (*actualPosition == '+'){
    sign = POSITIVE;
    actualPosition++;
  }else if (*actualPosition == '-'){
    sign = NEGATIVE;
    actualPosition++;
  }else
    sign = POSITIVE; /* if first non-blank character is not '+' nor '-', then we assume the number as a positive value, even though string may not be a number */

  if (base == 10){
    printf("base equals 10\n");
  }else if (base == 16){
    printf("base equals 16\n");
  }


  return number;
}
