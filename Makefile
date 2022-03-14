bin: main.c
	gcc $< -o $@ -lpthread

.PHONY: run clean
run:
	./bin
clean:
	rm bin