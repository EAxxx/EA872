FLAGS=-lncurses -std=c++11

all: model

model: model_mainloop.cpp oo_model.cpp oo_model.hpp
	g++ -omodel model_mainloop.cpp oo_model.cpp $(FLAGS)
