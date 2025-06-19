# Logic Gate Simulator

A comprehensive digital logic circuit simulator built with C++ and SFML, featuring an intuitive graphical interface for designing and testing digital circuits.

## Features

- **Interactive GUI**: User-friendly interface with toolbar and canvas
- **Logic Gates**: AND, OR, NOT gates with proper logic simulation
- **Interactive Components**: Switches for input and LEDs for output visualization
- **Real-time Simulation**: Live circuit simulation with visual feedback
- **Grid-based Layout**: Snap-to-grid placement for clean circuit designs

## Requirements

- C++17 or later
- SFML 3 or later
- CMake 3.16 or later

## Building

1. Install SFML:
   ```bash
   # Ubuntu/Debian
   sudo apt-get install libsfml-dev
   
   # macOS (with Homebrew)
   brew install sfml
   
   # Windows (vcpkg)
   vcpkg install sfml
   ```

2. Clone and build:
   ```bash
   git clone <repository-url>
   cd LogicGateSimulator
   mkdir build && cd build
   cmake ..
   make
   ```

3. Run:
   ```bash
   ./LogicGateSimulator
   ```

## Usage

### Controls
- **Left Click**: Place selected component or interact with switches
- **Toolbar**: Click on component buttons to select them for placement
- **ESC**: Return to selection mode
- **C**: Clear all components from canvas

### Component Types
- **AND Gate**: Outputs true only when all inputs are true
- **OR Gate**: Outputs true when at least one input is true  
- **NOT Gate**: Inverts the input signal
- **Switch**: Interactive input component (click to toggle)
- **LED**: Visual output indicator (lights up when receiving true signal)

### Circuit Design Workflow
1. Select a component from the toolbar
2. Click on the canvas to place it
3. Use switches as inputs and LEDs as outputs
4. Click switches to toggle their state and observe LED responses

## Architecture

The project follows modern C++ design patterns:

- **Component System**: Base `Component` class with specialized gate implementations
- **Observer Pattern**: Wires automatically update connected components
- **Factory Pattern**: Component creation based on selected type
- **RAII**: Smart pointers for automatic memory management
- **Separation of Concerns**: Clear separation between core logic, components, and GUI

## File Structure

- `src/core/`: Core simulation classes (Component, Wire, Circuit)
- `src/components/`: Specific component implementations (gates, switches, LEDs)
- `src/gui/`: User interface classes (Application, Toolbar, Canvas)
- `src/utils/`: Utility classes and constants

## Future Enhancements

- **Wire Routing**: Visual wire connections between components
- **Save/Load**: Circuit persistence to file
- **More Components**: Flip-flops, multiplexers, decoders
- **Timing Simulation**: Clock-based sequential logic
- **Circuit Analysis**: Truth table generation
- **Zoom and Pan**: Better navigation for large circuits

## Contributing

1. Fork the repository
2. Create a feature branch
3. Follow the existing code style and patterns
4. Add tests for new functionality
5. Submit a pull request
