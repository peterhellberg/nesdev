compile = \
	ca65 crt0.s; cc65 -Oi $(1).c --add-source; ca65 $(1).s;      \
	ld65 -C $(2).cfg -o roms/$(1).nes crt0.o $(1).o runtime.lib; \
	rm -f *.o example*.s                                         \

all: 1 2 3 4 5 6 7 8 9 10 11

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

10:
	$(call compile,example10,nrom_128_horz)

11:
	$(call compile,example11,nrom_128_horz)

clean:
	rm -f *.o example*.s
