all: clean run

run:
	g++ -c *.cpp -I/opt/sfml2/include -std=c++17
	g++ *.o -o app -L/opt/sfml2/lib -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

clean:
	rm -f *.o app

cleanup:
	rm -f *.o
