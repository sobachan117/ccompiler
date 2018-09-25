#include <stdio.h>

int main(void) {
  int n;
  scanf("%d", &n);

  printf("  .global _main\n");
  printf("_main:\n");
  printf("  mov $%d, %%eax\n", n);
  printf("  ret\n");

  return 0;
}
