end=./cpps/

all: 
	g++ -o main main.cpp ${end}pessoa.cpp ${end}funcionario.cpp ${end}asg.cpp ${end}vendedor.cpp ${end}gerente.cpp ${end}empresa.cpp
	./main
clean:
	rm -f main 