#include "neslib.h"

//general purpose vars
static unsigned char i,j;
static unsigned char spr;
static unsigned char touch;

#define LOGOS_MAX 48

//logo parameters
static unsigned char logo_x[LOGOS_MAX];
static unsigned char logo_y[LOGOS_MAX];
static unsigned char logo_dx[LOGOS_MAX];
static unsigned char logo_dy[LOGOS_MAX];

//palette for logos
const unsigned char palSprites[16]={
  0x0f,0x37,0x17,0x27,
  0x0f,0x39,0x19,0x29,
  0x0f,0x35,0x15,0x25,
  0x0f,0x31,0x11,0x21,
};


void put_str(unsigned int adr,const char *str) {
  vram_adr(adr);

  while(1) {
    if(!*str) break;
    //-0x20 because ASCII code 0x20 is placed in tile 0 of the CHR
    vram_put((*str++)-0x20);
  }
}


void main(void) {
  static unsigned char m,t,x,y,lives,died;

  touch=0;//collision flag

  //set palette for sprites
  pal_spr(palSprites);

  // set background color
  pal_col(0, 0x1f);
  pal_col(1, 0x20); // set text color

  put_str(NTADR_A(6,6),"ATHEGA CODE BASE 2015");
  put_str(NTADR_A(6,9),"PRESS A FOR +10 LIVES");

  music_play(0);

  //enable rendering
  ppu_on_all();

  // start with 10 lives;
  lives=10;

  x=128;
  y=120;

  //initialize logo parameters
  for(i=0;i<LOGOS_MAX;++i) {
    //starting coordinates
    logo_x[i]=rand8();
    logo_y[i]=rand8();

    //direction bits
    j=rand8();

    //horizontal speed -3..-3, excluding 0
    spr=1+(rand8()%1);
    logo_dx[i]=j&1?-spr:spr;

    //vertical speed
    spr=1+(rand8()%1);
    logo_dy[i]=j&2?-spr:spr;
  }

  pal_bg_bright(2);

  //the main loop
  while(1) {
    //wait for next TV frame
    ppu_wait_frame();

    t=pad_poll(0);

    if(t&PAD_LEFT)  if(x>8)   x-=2;
    if(t&PAD_RIGHT) if(x<248) x+=2;
    if(t&PAD_UP)    if(y>8)   y-=2;
    if(t&PAD_DOWN)  if(y<230) y+=2;

    if(t&PAD_A){
      music_play(0);
      sfx_play(0,0);
      lives+=10;
    }

    // reset sprite
    spr=0;

    if(lives > 0) {
      // player
      spr=oam_spr(x-8,y-8,0xA0,1,spr);
      spr=oam_spr(x,y-8,0xA1,0,spr);
      spr=oam_spr(x-8,y,0xA8,1,spr);
      spr=oam_spr(x,y,0xA9,0,spr);

      died = FALSE;

      for(i=0;i<LOGOS_MAX;++i) {
        //set a sprite for current logo
        spr=oam_spr(logo_x[i],logo_y[i],0x40,i&3,spr);
        //0x40 is tile number, i&3 is palette

        //move the logo
        logo_x[i]+=logo_dx[i];
        logo_y[i]+=logo_dy[i];

        //bounce the logo off the edges
        if(logo_x[i]>=(256-8)) logo_dx[i]=-logo_dx[i];
        if(logo_y[i]>=(240-8)) logo_dy[i]=-logo_dy[i];

        if((logo_x[i] < x+10) && (logo_x[i] > x-10)) {
          if((logo_y[i] < y+10) && (logo_y[i] > y-10)) {
            sfx_play(1,3);

            logo_x[i]=rand8();
            logo_y[i]=rand8();

            died = TRUE;
          }
        }
      }

      if(died) {
        --lives;
      }
    } else {
      oam_clear();
      music_stop();
    }
  }
}
