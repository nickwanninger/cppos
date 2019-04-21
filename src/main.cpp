#include <multiboot.h>

class printer {
  int ind = 0;
  char *base = (char *)0xb8000;
 public:
  int print(const char *str) {
    int i = 0;
    for (i = 0; str[i] != '\0'; i++) {
      base[ind * 2] = str[i];
      ind++;
    }
    return i;
  }
};

extern "C" int kmain(void) {
  printer p;
  p.print("hello world");
  p.print(" this is a test");
  return 0;
}


extern "C" void kstrap(void) {
  kmain();
  /* This function should never return */
  while (1) __asm__ __volatile("hlt");
}


