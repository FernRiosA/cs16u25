all: sentence stats

sentence: sentence.cpp
	g++ -std=c++11 -Wall -Werror=vla sentence.cpp -o sentence 

stats: stats.cpp
	g++ -std=c++11 -Wall -Werror=vla stats.cpp -o stats

clean:
	rm sentence stats

