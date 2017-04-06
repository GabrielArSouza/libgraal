# libgraal

-> O objetivo deste projeto é criar uma biblioteca c++ com vários algoritmos
estudados no ano de 2017.


Para estas instruções funcionarem, começe da pasta raiz, que contém App e graal:

    .
    ├── App
    │   ├── README.md
    │   ├── build
    │   │   └── dg
    │   ├── include
    │   │   └── graal.h
    │   ├── lib
    │   │   └── libgraal.a
    │   └── src
    │       └── drive_graal.cpp
    ├── graal
    │   ├── build
    │   │   ├── graal.o
    │   │   └── libgraal.a
    │   ├── include
    │   │   └── graal.h
    │   └── src
    │       └── graal.cpp
    └── howto_build_lib.md

# Para compilar as funções `graal` em uma biblioteca

1.  Gere primeiramente o código objeto das funções:

    `$ cd graal`

    `$ g++ -Wall -std=c++11 -c -I include/ src/graal.cpp -o build/graal.o`

    Este comando gera um arquivo `graal.o` na pasta `build`.

2. Agora gere a biblioteca estática a partir do codigo objeto.

    `$ ar rvs build/libgraal.a build/graal.o`

    se não der certo utilize o comando abaixo
`$ ar cr lib/libgraal.a bin/graal.o`

    Este comando gera o arquivo `libgraal.a`, que será distribuído para o
    _"cliente"_ juntamente com o cabeçalho `graal.h`.

# Para gerar a aplicação principal

1. Primeiramente copie a biblioteca recém criada `libgraal.a` para a pasta `lib` da aplicação.

    `$ cd ../App`

    `$ cp ../graal/build/libgraal.a lib/`

2. Copie agora o cabeçalho que descreve as funções `graal`.

    `$ cp ../graal/include/graal.h include/`

3. Compilando o programa principal.

    `$ g++ -Wall -std=c++11 src/drive_graal.cpp -I include -L lib -l graal -o build/drive_graal`

    Este comando compila e liga o código objeto da aplicação com a biblioteca
    desenvolvida por outro programador.

    O argumento `-I` indica em qual caminho procurar por cabeçalhos (além do `PATH`).
    O argumento `-L` indica em qual caminho procurar por bibliotecas (alen do `PATH`).
    O argumento `-l <biblioteca>` indica qual biblioteca deve ser *ligada* ao programa.
