comp: car.o track.o player.o competition.o race.o season.o randomizer.o userInterface.o chopper.o utility.o

game: car.o track.o player.o competition.o race.o season.o randomizer.o userInterface.o chopper.o utility.o main.o initreader.o
	g++ -g -Wall -o game main.o car.o track.o player.o competition.o race.o season.o randomizer.o userInterface.o chopper.o utility.o initreader.o

main.o:
	g++ -g -Wall -c main.cc

car.o: car.cc
	g++ -g -Wall -c car.cc

track.o: track.cc
	g++ -g -Wall -c track.cc

player.o: player.cc
	g++ -g -Wall -c player.cc

competition.o: competition.cc
	g++ -g -Wall -c competition.cc

race.o: race.cc
	g++ -g -Wall -c race.cc

season.o: season.cc
	g++ -g -Wall -c season.cc

randomizer.o: randomizer.cc
	g++ -g -Wall -c randomizer.cc

userInterface.o: userInterface.cc
	g++ -g -Wall -c userInterface.cc

chopper.o: chopper.cc
	g++ -g -Wall -c chopper.cc

utility.o:
	g++ -g -Wall -c utility.cc

initreader.o:
	g++ -g -Wall -c initreader.cc
clean:
	rm *.o
