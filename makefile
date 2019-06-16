cosmic: classGame.o classExplorer.o classSpace.o classDarkMatter.o classBlackHole.o classAsteroidField.o classPlanet.o classRelic.o testInput.o mainGame.o
	g++ -std=c++11 classGame.o classExplorer.o classSpace.o classDarkMatter.o classBlackHole.o classAsteroidField.o classPlanet.o classRelic.o testInput.o mainGame.o -o cosmic

classGame.o: classGame.cpp classGame.hpp
	g++ -c -std=c++11 classGame.cpp

classExplorer.o: classExplorer.cpp classExplorer.hpp
	g++ -c -std=c++11 classExplorer.cpp

classSpace.o: classSpace.cpp classSpace.hpp
	g++ -c -std=c++11 classSpace.cpp

classDarkMatter.o: classDarkMatter.cpp classDarkMatter.hpp
	g++ -c -std=c++11 classDarkMatter.cpp

classBlackHole.o: classBlackHole.cpp classBlackHole.hpp
	g++ -c -std=c++11 classBlackHole.cpp

classAsteroidField.o: classAsteroidField.cpp classAsteroidField.hpp
	g++ -c -std=c++11 classAsteroidField.cpp

classPlanet.o: classPlanet.cpp classPlanet.hpp
	g++ -c -std=c++11 classPlanet.cpp

classRelic.o: classRelic.cpp classRelic.hpp
	g++ -c -std=c++11 classRelic.cpp

testInput.o: testInput.cpp testInput.hpp
	g++ -c -std=c++11 testInput.cpp

mainGame.o: mainGame.cpp
	g++ -c -std=c++11 mainGame.cpp

clean:
	rm *.o cosmic 
