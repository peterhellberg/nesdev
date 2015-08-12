all: compile

../../roms/hello.nes: compile

compile:
	$(call compile,hello,nrom_128_horz)

run: ../../roms/hello.nes
	nestopia ../../roms/hello.nes

clean:
	rm -f *.o hello.s ../../roms/hello.nes

compile = \
	ca65 crt0.s; cc65 -Oi $(1).c --add-source; ca65 $(1).s;            \
	ld65 -C $(2).cfg -o ../../roms/$(1).nes crt0.o $(1).o runtime.lib; \
	rm -f *.o $(1).s                                                   \
