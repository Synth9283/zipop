target := zipop
flags := -std=c99

all: $(target)

$(target): main.c
	gcc $< $(flags) -o $@

clean:
	rm -fv $(target)

install:
	sudo install zipop /usr/bin/zipop

uninstall:
	sudo rm -fv /usr/bin/zipop

