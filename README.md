# Game Development Challenge 🕹
Repositório criado para minha aplicação na FMQ. 
"Run to FABAMAQ" é um Mini Game desenvolvido em C++ utilizando a biblioteca SDL. Foi criada uma Engine própria e do zero.
O objetivo do jogo é ajudar o personagem "Guilherme" a chegar no seu futuro trabalho na "FABAMAQ". Porém, faça com que o personagem não contraia a COVID-19 no caminho. 
Conto com a sua ajuda! 👨‍💻 #BuildEngineFromScratch

![](ezgif.com-video-to-gif.gif)

# Pré-requisitos

💻 SO:
  - Linux (Ubuntu);

📚 Biblioteca SDL

⚙ Compilador C++

# Compilador g++

1. Instalar o compilador g++ no seu Ubuntu:
```console
foo@bar:~$ sudo apt install g++
```
  
2. Checar se o mesmo foi instalado corretamente:
```console
foo@bar:~$ g++ --version
```

# Biblioteca SDL
Simple DirectMedia Layer (SDL) é uma biblioteca multimídia livre e de código aberto, multiplataforma, escrito em C que representa uma interface simples para gráficos, som, e dispositivos de entrada de várias plataformas. 

1. Instalar a Biblioteca SDL:
```console
foo@bar:~$ sudo apt-get install libsdl2-2.0
```
2. Instalar Extensões:

- SDL2_image
```console
foo@bar:~$ sudo apt-get install libsdl2-image-dev
```

- SDL2_ttf
```console
foo@bar:~$ sudo apt install libsdl-ttf2.0-0
```

# Compilar
1. Acessar o diretório "Source" pelo Terminal

2. Compilar todos arquivos .cpp e seus cabeçalhos, conforme abaixo:

```console
foo@bar:~$ g++ AssetManager.cpp Collision.cpp ECS.cpp Game.cpp main.cpp Map.cpp TextureManager.cpp Vector2D.cpp `sdl2-config --cflags --libs` -w -lSDL2 -lSDL2_image -lSDL2_ttf -o run
```
3. Rodar o Binário:
```console
foo@bar:~$ ./run
```
# Instruções
Keyboard Command | Functionality
------------ | -------------
"Space Bar" | Pause/Resume
"i" | Insert Credits
"o" | Remove Credits
"awsd" | move
"arrows" | move


# Agradecimentos
Ao Tiago Gomes e todo time da FMQ que me possibilitaram essa oportunidade. 
