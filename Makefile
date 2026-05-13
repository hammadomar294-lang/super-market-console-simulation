app:
	g++ -std=c++17 \
	main.cpp \
	classes/Program/*.cpp \
	classes/store/*.cpp \
	classes/interface/*.cpp \
	classes/domain/*.cpp \
	classes/domain/user/*.cpp \
	classes/persistence/*.cpp \
	classes/BST_analytics/*.cpp \
	classes/helper/*.cpp \
	-o main
run:
	./main