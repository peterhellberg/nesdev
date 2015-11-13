all: compile

run: ../../roms/athega.nes
	nes ../../roms/athega.nes

compile:
	$(call compile,athega,nrom_128_horz)

../../roms/athega.nes: compile

clean:
	rm -f *.o athega.s ../../roms/athega.nes

compile = \
	ca65 crt0.s; cc65 -Oi $(1).c --add-source; ca65 $(1).s;            \
	ld65 -C $(2).cfg -o ../../roms/$(1).nes crt0.o $(1).o runtime.lib; \
	rm -f *.o $(1).s                                                   \
