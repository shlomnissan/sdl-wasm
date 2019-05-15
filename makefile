sdl-wasm:
	emcc main.c -s WASM=1 -s USE_SDL=2 -o index.js