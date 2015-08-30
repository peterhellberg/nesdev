all: compile

run: ../../roms/syntax_error.nes
	nes ../../roms/syntax_error.nes

compile:
	$(call compile,syntax_error,nrom_128_horz)

../../roms/syntax_error.nes: compile

clean:
	rm -f *.o hello.s ../../roms/syntax_error.nes

compile = \
	ca65 crt0.s; cc65 -Oi $(1).c --add-source; ca65 $(1).s;            \
	ld65 -C $(2).cfg -o ../../roms/$(1).nes crt0.o $(1).o runtime.lib; \
	rm -f *.o $(1).s                                                   \
