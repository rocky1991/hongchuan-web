CC = g++
EXECS= hello_world

.PHONY:
	clean
ALL: $(EXECS)
	echo "all execs done!"

hello_world: hello_world.cpp
	-$(CC) -o $@ $^
clean:
	rm -f $(EXECS)

