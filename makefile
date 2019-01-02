CC=g++

jumble: jumble.cpp
	$(CC) -std=c++11 jumble.cpp -o jumble

clean:
	rm jumble
