# nesdev

I’m just playing around, not meant to be useful for anyone but me :)

## Getting started

Install [cc65](http://cc65.github.io/cc65/) (a freeware C compiler for 6502 based systems)

```bash
brew install cc65
```

Then install [fceux](http://www.fceux.com/) (a NES emulator) from `homebrew/games`.

```bash
brew install homebrew/games/fceux
```

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

 - <http://nesdev.com/#Hardware>
