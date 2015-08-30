#include "neslib.h"

//general purpose vars
static unsigned char i,j;
static unsigned char spr;

//total number of invaders on the screen
//since there are 64 HW sprites, it is absolute max
#define INVADERS_MAX	64

//invader parameters
static unsigned char invader_x[INVADERS_MAX];
static unsigned char invader_y[INVADERS_MAX];
static unsigned char invader_dx[INVADERS_MAX];
static unsigned char invader_dy[INVADERS_MAX];

//palette for invaders, there are four sets for different invader colors
const unsigned char palSprites[16]={
  0x0f,0x37,0x17,0x27,
  0x0f,0x31,0x11,0x21,
  0x0f,0x35,0x15,0x25,
  0x0f,0x39,0x19,0x29
};

void main(void) {
  //set palette for sprites
  pal_spr(palSprites); 

  // set background color to black
  pal_col(0, 0x0f);

  //enable rendering
  ppu_on_all();

  //initialize invader parameters
  for(i=0;i<INVADERS_MAX;++i) {
    //starting coordinates
    invader_x[i]=rand8();
    invader_y[i]=rand8();

    //direction bits
    j=rand8();

    //horizontal speed -3..-3, excluding 0
    spr=1+(rand8()%3);
    invader_dx[i]=j&1?-spr:spr;

    //vertical speed
    spr=1+(rand8()%3);
    invader_dy[i]=j&2?-spr:spr;
  }

  //the main loop
  while(1) {
    //wait for next TV frame
    ppu_wait_frame();

    spr=0;

    for(i=0;i<INVADERS_MAX;++i) {
      //set a sprite for current invader
      spr=oam_spr(invader_x[i],invader_y[i],0x40,i&3,spr);//0x40 is tile number, i&3 is palette

      //move the invader
      invader_x[i]+=invader_dx[i];
      invader_y[i]+=invader_dy[i];

      //bounce the invader off the edges
      if(invader_x[i]>=(256-8)) invader_dx[i]=-invader_dx[i];
      if(invader_y[i]>=(240-8)) invader_dy[i]=-invader_dy[i];
    }
  }
}
