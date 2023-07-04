all: 
	g++ -o main main.cpp pessoa.cpp funcionario.cpp asg.cpp vendedor.cpp gerente.cpp empresa.cpp
	./main
clean:
	rm -f main 