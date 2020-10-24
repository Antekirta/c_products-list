start "g++" src/main.c src/hello.c -o bin/main.exe"
timeout 5
start "" "bin\main.exe"