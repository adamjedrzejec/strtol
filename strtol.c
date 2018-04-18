/* dummy implementation of strtol */

#include <errno.h>

long strtol (const char *nPtr, char **endPtr, int base)
{
  errno = 0;
  if (!((base >= 2 && base <= 32) || base != 0))
  {
    errno = EINVAL;
    return 0;
  }
  
  return 0;
}
