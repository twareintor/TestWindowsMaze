

@del maze.exe
@del drawMaze.o
@del maze.o
@del saveBmp.o
@del main.o


@C:\tcc\tcc\tcc -c maze.c -o maze.o
@C:\tcc\tcc\tcc -c saveBmp.c -o saveBmp.o
@C:\tcc\tcc\tcc -c drawMaze.c -o drawMaze.o
@C:\tcc\tcc\tcc -c main.c -o main.o
@C:\tcc\tcc\tcc main.o drawMaze.o maze.o saveBmp.o -luser32 -lgdi32 -o maze.exe 

rem @maze.exe
@pause
