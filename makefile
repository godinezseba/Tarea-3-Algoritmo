all:
	make run1
	make run2
run1:
	g++ src/Pregunta 1/main.cpp -o main1 -Wall 
	./main1 
run2:
	g++ src/Pregunta 2/main.cpp -o main2 -Wall 
	./main2 
vald:
	valgrind ./main < input/input.txt
check:
valgrind --leak-check=full --show-leak-kinds=all src/main < input/input.txt