#include <stdio.h>

int mdc(int x, int y);

int main()
{
  int x, y;
  scanf("%d %d", &x, &y);
  printf("MDC(%d, %d) = %d", x, y, mdc(x, y));
  return 0;
}


/* MDC (X, Y)
 *  -- X, se y == 0
 *  -- MDC (Y, X % Y), se y > 0
 */
int mdc(int x, int y)
{
  int t;
  if (y > x)
  {
    t = x; x = y; y = t;
  }

  if (y == 0)
  {
    return x;
  }
  else
  {
    return mdc(y, x % y);
  }
}