# sdl-wasm [![License: MIT](https://img.shields.io/badge/License-MIT-blue.svg)](https://opensource.org/licenses/MIT)

A simple example of compiling C/SDL to WebAssembly and binding it to an HTML5 canvas. 

Live demo: https://shlomnissan.github.io/sdl-wasm

## Installation:

1. Install Emscripten:<br/>
https://emscripten.org/docs/getting_started/downloads.html

2. Clone the repository:<br/>
`git clone https://github.com/shlomnissan/sdl-wasm`<br/>
`cd sdl-wasm`

3. Run `make` or build manually:<br/>
`emcc main.c -s WASM=1 -s USE_SDL=2 -s USE_SDL_IMAGE=2 -s SDL2_IMAGE_FORMATS='["png"]' --preload-file assets -o index.js`

4. Chrome doesn't support file XHR requests so you need to open index.html from a web server. You can use Emscripten for that too: 
`emrun index.html`

5. 🕹Use the arrow keys to move the texture around.
<br/>

<img width="640" alt="screen" src="https://user-images.githubusercontent.com/3165988/57870831-c38f0d80-77bc-11e9-9b37-19b64d8f22a7.png">

## Todos:

- [x] Add keyboard input controls to move the square around
- [x] Include SDL_Image and render a texture instead of the blue square

## MIT license:

```
Copyright (c) 2019 Betamark

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
```
