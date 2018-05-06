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
        else
          return 0;
      }
      else if (*actualPosition == 'x' || *actualPosition == 'X'){ /* we assume that hexadecimal system is written in '0x...' or '0X...' way */
        actualPosition++;
        if (isdigit(*actualPosition) || ((*actualPosition >= 'A') && (*actualPosition <= 'F')))
          base = 16;
        else
          return 0;
      }
      else
        base = 10;
    }else /* this condition contains: actualPosition is a digit and that digit is not 0 */
      base = 10;

    actualPosition = positionBeforeBaseDetection;

  }



  if (base == 10){
    printf("base equals 10\n");
  }else if (base == 8){
    printf("base equals 8\n");
  }else if (base == 16){
    printf("base equals 16\n");
  }



        /////////  *endPtr = (char *) actualPosition;








  return number;
}
