all:
	make run1
	make run2

compile1:
	g++ src/Pregunta1/main.cpp -o main1 -Wall 
compile2:
	g++ src/Pregunta2/main.cpp -o main2 -Wall 

run1: compile1
	./main1 < input/Pregunta1/input.txt
run2: compile2
	./main2 < input/Pregunta2/input2.txt

check1: compile1
	valgrind --leak-check=full --show-leak-kinds=all ./main1 < input/Pregunta1/input.txt
check2: compile2
	valgrind --leak-check=full --show-leak-kinds=all ./main2 < input/Pregunta2/input.txt