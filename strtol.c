#include <errno.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

long strtol (const char *nPtr, char **endPtr, int base)
{
  errno = 0; /* if no error will occur, errno will not change */
  long number = 0; // WHEN FINISHED, DELETE '= 0' !!!!!!!!!!
  const char *actualPosition;
  enum signs {POSITIVE, NEGATIVE}; /* available signs */
  int sign;

  if (endPtr == NULL){ /* !!!MANDATORY PART!!! if user of the function gives us the endPtr pointer with a NULL address */
    free(endPtr);
    endPtr = malloc(sizeof(char **));
    *endPtr = (char *) nPtr; /* there could be anything instead of '(char *) nPtr' like '0' */
  }

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


  /* detection what is the base */
  if (base == 0){
    const char *positionBeforeBaseDetection;
    positionBeforeBaseDetection = actualPosition;

    if (!isdigit(*actualPosition))
      return 0; /* string is not a number */
    else if (*actualPosition == '0')
    {
      actualPosition++;
      if (*actualPosition == 'o' || *actualPosition == 'O'){ /* we assume that octal system is written in '0o...' or '0O...' way */
        actualPosition++;
        if (*actualPosition >= '0' || *actualPosition <= '7')
          base = 8;
        else{
          *endPtr = (char *) ++positionBeforeBaseDetection;
          return 0;
        }
      }
      else if (*actualPosition == 'x' || *actualPosition == 'X'){ /* we assume that hexadecimal system is written in '0x...' or '0X...' way */
        actualPosition++;
        if (isdigit(*actualPosition) || ((*actualPosition >= 'A') && (*actualPosition <= 'F')))
          base = 16;
        else
          base = 10;
      }
      else
        base = 10;
    }else /* this condition contains: actualPosition is a digit and that digit is not 0 */
      base = 10;

    if (base == 10)
      actualPosition = positionBeforeBaseDetection;
    else if (base == 8 || base == 16)
      actualPosition = positionBeforeBaseDetection + 2;

  }






  /////TO WORK PROPERLY, IT NEEDS TO CHECK IF EACH INPUT IS PROPER TO THE BASE
  if (base == 10){
    while (isdigit(*actualPosition) && *actualPosition != '\0')
      actualPosition++;
    *endPtr = (char *) actualPosition;
    //printf("\t\t\tendPtr:%s\n", (char *) *endPtr); /////////////////TEST
  }else if (base == 8){
    if (*actualPosition == '0'){
      actualPosition++;
      if (*actualPosition == 'o' || *actualPosition == 'O')
        actualPosition++;
    }
    while (*actualPosition >= '0' && *actualPosition <= '7')
      actualPosition++;
    *endPtr = (char *) actualPosition;
  }else if (base == 16){
    if (*actualPosition == '0'){
      actualPosition++;
      if (*actualPosition == 'x' || *actualPosition == 'X')
        actualPosition++;
    }
    while (isdigit(*actualPosition) || (*actualPosition >= 'A' && *actualPosition <= 'F'))
      actualPosition++;
    *endPtr = (char *) actualPosition;
  }


        ////END POINTER SETTER:    *endPtr = (char *) actualPosition;


  return number;
}
