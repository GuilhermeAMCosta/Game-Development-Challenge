# Game Development Challenge 🕹
Repository created for my FMQ application. "Run to FABAMAQ" is a Mini Game developed in C ++ using the SDL library. An own engine was created from scratch. The objective of the game is to help the player "Guilherme" to arrive at his future work at "FABAMAQ". However, make sure that the character does not contract COVID-19 on the way and is not hit by a car. 
I'm counting on your help! 👨‍💻 #BuildEngineFromScratch

![](runToFMQ.gif)

# Prerequisites

💻 OS:
  - Linux (Ubuntu);

📚 SDL Library

⚙ C++ Compiler

# g++ Compiler

1. Install the g ++ compiler on your Ubuntu:
```console
foo@bar:~$ sudo apt install g++
```
  
2. Check if it was installed correctly:
```console
foo@bar:~$ g++ --version
```

# SDL Library
Simple DirectMedia Layer (SDL) is a free, open source, multiplatform multimedia library, written in C that represents a simple interface for graphics, sound, and input devices from various platforms.

1. Install the SDL Library:
```console
foo@bar:~$ sudo apt-get install libsdl2-2.0
```
2. Install Extensions:

- SDL2_image
```console
foo@bar:~$ sudo apt-get install libsdl2-image-dev
```

- SDL2_ttf
```console
foo@bar:~$ sudo apt install libsdl-ttf2.0-0
```

# To Compile
1. Access the "Source" directory from the Terminal

2. Compile all .cpp files and their headers, as follows:

```console
foo@bar:~$ g++ AssetManager.cpp Collision.cpp ECS.cpp Game.cpp main.cpp Map.cpp TextureManager.cpp Vector2D.cpp `sdl2-config --cflags --libs` -w -lSDL2 -lSDL2_image -lSDL2_ttf -o run
```
3. Run the Binary Code:
```console
foo@bar:~$ ./run
```
# Instructions
- When the game starts, you must press START (Space Bar). In addition, you must add at least one CREDIT (Letter "i" on your keyboard).

- You can withdraw a CREDIT at any time (Letter "o" on your keyboard).

- You can PAUSE the game at any time.

- If you are hit by a car or the virus you will lose a CREDIT. If you enter one more CREDIT, or if you still have CREDITS available, the game will continue and the number of moves will be increased.

Keyboard Command | Functionality
------------ | -------------
"Space Bar" | Pause/Resume
"i" | Insert Credits
"o" | Remove Credits
"awsd" | move
"arrows" | move


# Thanks
To Tiago Gomes and the entire FMQ team that gave me this opportunity.
