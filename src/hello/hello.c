#include "neslib.h"

void put_str(unsigned int adr, const char *str) {
  vram_adr(adr);

  while(1) {
    if(!*str) break;

    // -0x20 because ASCII code 0x20 is placed in tile 0 of the CHR
    vram_put((*str++)-0x20);
  }
}

void main(void) {
  // set background color to green
  pal_col(0, 0x29);

  // set foreground color to a darker green
  pal_col(1, 0x19);

  // print the string
  put_str(NTADR_A(9,10), "HELLO, WORLD!");

  // enable rendering
  ppu_on_all();

  // enter infinite loop
  while(1) {
    // wait for next TV frame
    ppu_wait_frame();
  }
}
