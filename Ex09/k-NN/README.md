### Documentação da classe
Para acessar a documentação da classe ~~[link aqui](https://github.com/buzutilucas/scientific-programming/tree/master/Ex09/k-NN/Doc)~~

### Como Compilar
__Linux e ~~MacOS~~__

> :warning:  Utilizou-se o compilador _G++_ e _C++11_.

Para compilar e executar o programa teste, abra o terminal e execute os comandos abaixo.
```shell
# Sem programação paralela
g++ -o main main.cpp knn.cpp knn.h -std=c++11 -lstdc++ -lm
./main

# Com programação paralela
export OMP_NUM_THREADS=4 # Quantidade de processos em paralelo
g++ -o main main.cpp knn.cpp knn.h -std=c++11 -lstdc++ -lm -fopenmp
./main
```

~~__Windows:__ Executar o programa teste já compilado: `main`.~~
