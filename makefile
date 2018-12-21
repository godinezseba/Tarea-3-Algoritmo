all:
	make run1
	make run2
run1:
	g++ src/Pregunta1/main.cpp -o main1 -Wall 
	./main1 < input/Pregunta1/input.txt
run2:
	g++ src/Pregunta2/main.cpp -o main2 -Wall 
	./main2 < input/Pregunta2/input.txt
vald:
	valgrind ./main < input/input.txt
check:
	valgrind --leak-check=full --show-leak-kinds=all src/main < input/input.txt