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
`GradDesc(float (*func)(float),  float val, float learningRate)`

Cria um objeto descida de gradiente.

## Métodos

|       |                                Descrição                                          |
|-------|-----------------------------------------------------------------------------------|
| float   | [`diff()`](#diff) -  Obtem a derivada de uma função dado uma variável inicial.                               |
| void  | [`fit()`](#fit) - Executa o algoritmo descida de gradiente. |

---

## Detalhe do Construtor

### `GradDesc`

`GradDesc::GradDesc(float (*func)(float),  float val, float learningRate)`
- Cria um objeto descida de gradiente
- __Parâmetros:__
  - float (\*func)(float) - endereço de função (polinomio que será aplicado o algoritmo).
  - float val - variável inicial.
  - float learningRate - taxa de aprendizado.

```c++
#include <iostream>
#include <cmath>
#include "graddesc.h" //classe GradDesc

using namespace std;

float f(float x) {return pow(x,2);}

int main(int argc, char *argv[]) {

  GradDesc grad(&f, 2., 0.1);
  grad.fit();

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

#### __fit__
`GradDesc::fit()`
- Executa o algoritmo descida de gradiente.

---
