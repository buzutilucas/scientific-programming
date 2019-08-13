# Documentação da classe
class

---

### dll::LinkedList
```c++
class GradDesc;
```

_class_ __GradDesc__

Classe do algoritmo Descida de Gradiente

__Versão:__
  - 0.0.1

__Autor:__ Lucas Fontes Buzuti

---

## Construtor
`GradDesc(dll::LinkedList<float> &poly,  float val, float learningRate)`

Cria um objeto descida de gradiente.

## Métodos

|       |                                Descrição                                          |
|-------|-----------------------------------------------------------------------------------|
| float   | [`diff()`](#diff) -  Obtem a derivada de uma função dado uma variável inicial.                               |
| float  | [`func()`](#func) - Obtem o resultado de uma função dado uma variável inicial. |
| void  | [`fit()`](#fit) - Executa o algoritmo descida de gradiente. |

---

## Detalhe do Construtor

### `GradDesc`

`GradDesc::GradDesc(dll::LinkedList<float> &poly,  float val, float learningRate)`
- Cria um objeto descida de gradiente
- __Parâmetros:__
  - dll::LinkedList<float> &poly - endereço do objeto lista (polinomio que será aplicado o algoritmo).
  - float val - variável inicial.
  - float learningRate - taxa de aprendizado.

```c++
#include <iostream>
#include "graddesc.h" //classe GradDesc

using namespace std;

int main(int argc, int *argv[])
{
  /*Definição da função (e.g. [0. 0. 1.] = 0.x^0 + 0.x^1 + 1.x^2)*/
  dll::LinkedList<float> poly;
  poly.insertBack(new dll::Node<float>(0.));
  poly.insertBack(new dll::Node<float>(0.));
  poly.insertBack(new dll::Node<float>(1.));

  GradDesc grad(poly, 2., 0.1); //inicialização da classe GradDesc

  return 0;
}
```

## Detalhe do Destrutor

### `~GradDesc()`
`GradDesc::~GradDesc()`

- Destrói o objeto descida de gradiente.

## Detalhe dos Métodos

#### __diff__
`GradDesc::diff()`
- Obtem a derivada de uma função dado uma variável inicial.
- __Retorno:__
  - A derivada do polinomio.

#### __func__
`GradDesc::func()`
- Obtem o resultado de uma função dado uma variável inicial.
- __Retorno:__
  - O resultado do polinomio.

#### __fit__
`GradDesc::fit()`
- Executa o algoritmo descida de gradiente.

---
