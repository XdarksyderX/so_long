# So_Long

## Overview
`so_long` is a 2D video game project, part of the 42 school curriculum. This project is designed to introduce students to graphical programming and to reinforce skills in managing graphics libraries (like MiniLibX), creating interactive applications, and understanding 2D rendering.

## Features
- A simple yet engaging 2D game environment.
- Implementation of key game mechanics like player movement, map parsing, and collision detection.
- Utilization of MiniLibX for graphical rendering in both Linux and macOS environments.
- Clean, modular code with organized file structure for easy navigation and expansion.

## Compilation and Usage
### Requirements
- GCC compiler
- GNU make
- MiniLibX library (setup varies based on the operating system)

### Compiling the Game
To compile `so_long`, run:

```
make all
```

This command compiles the game executable, `so_long`, along with necessary libraries.

### Running the Game
After compilation, execute the game using:

```
./so_long [path_to_map_file]
```

### Cleaning Up
To remove object files and the game executable:

```
make fclean
```

To recompile the game:

```
make re
```

## File Structure
- `src/*.c` - Source files for game logic, rendering, and control handling.
- `assets/` - Directory containing game assets like sprites and sounds.
- `maps/` - Sample maps for the game.

## Gameplay
In `so_long`, the player navigates through a map, avoiding obstacles and collecting items. The goal is to reach the end of the level while maximizing the score.

Enjoy the game and feel free to contribute or extend it!