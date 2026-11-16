# ColeusMaze 🌿



A first-person 3D maze game built from scratch in C using the SDL2 library and raycasting techniques. Navigate through textured corridors, track your position on the minimap, and find your way through a virtual jungle of Coleus plants.



## Features ✨



- **3D Raycasting Engine:** Renders a pseudo-3D first-person perspective from a 2D grid map.

- **Textured Environments:** Maps PNG wall textures onto surfaces using uPNG and SDL2.

- **2D Minimap & Player Tracking:** Real-time rendering of the player's position, field of view, and maze layout.

- **Collision Detection:** Prevents the player from clipping through walls while allowing smooth sliding along surfaces.

- **Cross-Platform Input & Rendering:** Powered by SDL2 for window management and responsive keyboard controls.



## Tech Stack 💻



- **Language:** C

- **Graphics & Input:** SDL2

- **PNG Decoding:** uPNG

- **Build System:** Make



## Installation 🛠️



### Prerequisites



You will need a C compiler (`gcc` or `clang`), `make`, and the SDL2 development libraries installed on your machine.



- **Debian / Ubuntu:**

  ```bash

  sudo apt-get update

  sudo apt-get install build-essential libsdl2-dev

  ```

- **Fedora:**

  ```bash

  sudo dnf install gcc make SDL2-devel

  ```

- **macOS (Homebrew):**

  ```bash

  brew install sdl2

  ```

- **Windows:**

  Download the development libraries from the [SDL2 Releases page](https://github.com/libsdl-org/SDL/releases) and link the include and library directories to your compiler.



### Build from Source



1. Clone the repository:

   ```bash

   git clone https://github.com/Darkidd77/ColeusMaze.git

   cd ColeusMaze

   ```

2. Compile the project using the Makefile:

   ```bash

   make

   ```

   This will generate the `maze` executable in the root directory.



## Usage 🎮



Launch the game from the root directory:



```bash

./maze

```



### Controls



| Key | Action |

| --- | --- |

| `W` / `Up Arrow` | Move forward |

| `S` / `Down Arrow` | Move backward |

| `A` / `Left Arrow` | Rotate camera left |

| `D` / `Right Arrow` | Rotate camera right |

| `ESC` | Quit the game |



## Project Structure 📂



```text

ColeusMaze/

├── images/             # Wall textures and visual assets

├── inc/                # Header files (.h)

│   ├── game.h          # Core structs, constants, and function prototypes

│   └── upng.h          # uPNG decoder declarations

├── src/                # Source files (.c)

│   ├── draw.c          # Rendering helpers for pixels, lines, and rectangles

│   ├── input_handler.c # Keyboard event polling

│   ├── main.c          # Entry point and main game loop

│   ├── map.c           # Maze grid parsing and 2D map rendering

│   ├── player_handler.c# Player movement, rotation, and collision logic

│   ├── ray.c           # Single-ray intersection math

│   ├── raycaster.c     # Full-screen raycasting loop

│   ├── tex.c           # Texture loading and pixel sampling

│   ├── upng.c          # PNG decoding implementation

│   ├── wall.c          # 3D wall projection and textured column rendering

│   └── win.c           # SDL window and renderer initialization

├── makefile            # Build instructions

└── README.md           # Project documentation

```



## Contributing 🤝



Contributions, bug reports, and feature suggestions are welcome! Feel free to open an issue or submit a pull request on the [GitHub repository](https://github.com/Darkidd77/ColeusMaze).



## Acknowledgments 🙌



- [uPNG](https://github.com/elanthis/upng) for lightweight PNG image decoding in C.

- **Lode's Computer Graphics Tutorial** & **Permadi's Raycasting Tutorial** for foundational raycasting concepts.



## License 📄



This project is licensed under the MIT License — see the [LICENSE](LICENSE) file for details.



## Author ✍️



**Darkidd77** — [GitHub Profile](https://github.com/Darkidd77)
