# Documentação da classe
class template

---

### stk::Stack
```c++
template <class T> class Stack; // modelo genérico
```

_class_ __Stack__

Classe da estrutura de dados (Pilha)

__Versão:__
  - 0.0.1

__Autor:__ Lucas Fontes buzuti

---

## Construtor
`stk::Stack<Type>(int e)`

Cria uma pilha a partir de um tamanho determinado pelo usuário.

## Métodos

|      |                                Descrição                                  |
|------|---------------------------------------------------------------------------|
| void | [`push(Type e)`](#__push__) - Empilha o próximo elemento para a próxima posição vazia. |
| Type | [`pop()`](#__pop__) - Remove o elemento do topo.                                      |
| bool | [`empty()`](#__empty__) - Verifica se a pilha está vazia.                               |
| bool | [`full()`](#__full__) - Verifica se a pilha está cheia.                                |
| Type | [`top()`](#__top__) - Informa o elemento do topo da pilha.                            |

---

## Detalhe do Construtor

### `Stack<Type>`

`stk::Stack<Type>::Stack(int size)`

- Cria uma pilha a partir de um tamanho determinado pelo usuário.
- __Parâmetros:__
  - int size - Tamanho da pilha.

```c++
#include <iostream>
#include "stack.h" // classe Stack

using namespace std;

#define SIZE 6

int main(int argc, char *argv[])
{
  stk::Stack<int> stack(SIZE); // inicialização da classe Stack

  return 0;
}
```

## Detalhe do Destrutor

### `~Stack<Type>`
`stk::Stack<Type>::~Stack()`

- Destrói a pilha criada.

## Detalhe dos Métodos

#### __push__
`stk::Stack<Type>::push(Type e)`
- Empilha o próximo elemento para a próxima posição vazia.
- __Parâmetros:__
  - Type e - Elemento a ser empilhado.

#### __pop__
`stk::Stack<Type>::pop()`
- Remove o elemento do topo.
- __Retorno:__
  - O elemento que foi removido.

#### __empty__
`stk::Stack<Type>::empty()`
- Verifica se a pilha está vazia.
- __Retorno:__
  - Retorna `true` no caso em que a pilha está vazia, ou `false` para a condição oposta.

#### __full__
`stk::Stack<Type>::full()`
- Verifica se a pilha está cheia.
- __Retorno:__
  - Retorna `true` no caso em que a pilha está cheia, ou `false` para a condição oposta.

#### __top__
`stk::Stack<Type>::top()`
- Informa o elemento do topo da pilha.
- __Retorno:__
  - O elemento que se encontra no topo da pilha.

---

## Tratamento de Erro

### stk::StackException

Os métodos `push`, `pop` e `top` necessitam de tratamento de erros. Para fazer esses tratamentos pode-se utilizar a classe `stk::StackException`.

```c++
#include <iostream>
#include "stack.h" // classe Stack

using namespace std;

#define SIZE 6

int main(int argc, char *argv[])
{
  stk::Stack<int> stack(SIZE); // inicialização da classe Stack

  try
  {
    stack.pop();
  }catch(stk::StackException e) // classe para o tratamento de erro
  {
    cerr << "Error: " << e.what() << endl;
  }

  return 0;
}
```

---

## UML

![UML](img/UML.png)
