# nesdev

I’m just playing around, not meant to be useful for anyone but me :)

## Getting started

Install [cc65](http://cc65.github.io/cc65/) (a freeware C compiler for 6502 based systems)

```bash
brew install cc65
```

Add Vim syntax highlighting for the ca65 assembler using [Vundle](https://github.com/VundleVim/Vundle.vim)

```vim
Plugin 'maxbane/vim-asm_ca65'

" ASM ca65
au BufRead,BufNewFile *.s set filetype=asm_ca65
```

### Emulators (running under OS X)

- [Nestopia](http://0ldsk00l.ca/nestopia/)
- [FCEUX](http://www.fceux.com/)

I’ve also been using a few different NES emulators written in Go:

 - [nes](https://github.com/fogleman/nes) (my favorite so far)
 - [nintengo](https://github.com/nwidger/nintengo)

## Read the [Programming NES games in C](http://shiru.untergrund.net/articles/programming_nes_games_in_c.htm) article

and then

## Watch the [NES C Programming Examples video](https://www.youtube.com/watch?v=jvgz5sY5xUw)

[![NES C Programming Examples](http://assets.c7.se/skitch/NES_C_Programming_Examples-20150812-214421.png)](https://www.youtube.com/watch?v=jvgz5sY5xUw)

## Makefile for the [CC65 NES examples](https://shiru.untergrund.net/files/src/cc65_nes_examples.zip)

```make
compile = \
	ca65 crt0.s;                                           \
	cc65 -Oi $(1).c --add-source;                          \
	ca65 $(1).s;                                           \
	ld65 -C $(2).cfg -o $(1).nes crt0.o $(1).o runtime.lib \

all: 1 2 3 4 5 6 7 8 9

1:
	$(call compile,example1,nrom_128_horz)

2:
	$(call compile,example2,nrom_128_horz)

3:
	$(call compile,example3,nrom_128_horz)

4:
	$(call compile,example4,nrom_128_horz)

5:
	$(call compile,example5,nrom_128_horz)

6:
	$(call compile,example6,nrom_128_horz)

7:
	$(call compile,example7,nrom_128_horz)

8:
	$(call compile,example8,nrom_128_horz)

9:
	$(call compile,example9,nrom_128_horz)

clean:
	rm *.o *.nes
```

With this makefile you should be able to compile all of the examples under OS X.

### [PPU Palettes](http://wiki.nesdev.com/w/index.php/PPU_palettes)

![2C03 and 2C05](http://assets.c7.se/skitch/PPU_palettes-20150812-233132.png)

## Links

 - [Hardware Info](http://nesdev.com/#Hardwar))
 - [NES CHR Editor](http://www.ninjasftw.com:8080/squirrel/nes_chr/) a (Mac OS X) sprite editor for Nintendo Entertainment System games.
