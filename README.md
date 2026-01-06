# Arduino Simon Memory Game

This project is an Arduino-based Simon memory game using LEDs, push buttons, and sound output.

The game generates an increasing random sequence of lights and tones which the player must repeat correctly.  
Each successful round increases the sequence length.  
An incorrect input triggers a failure sequence and resets the game.

---

## Features

- Random sequence generation
- Progressive difficulty (sequence grows each round)
- Visual feedback using LEDs
- Audio feedback using tones
- Button-based user input
- Startup animation and sound
- Failure detection and reset logic


## Hardware Used

- Arduino Uno
- 4 × LEDs
- 4 × Push buttons
- 4 × Current-limiting resistors(≈220Ω)
- Piezoelectric buzzer 
- Breadboard and jumper wires


## How the Game Works

1. A startup animation and tune plays on boot.
2. The game generates a random LED + sound sequence.
3. The sequence is played back to the player.
4. The player must repeat the sequence using the buttons.
5. If the input matches, the game advances to the next round.
6. If the input is incorrect, a failure sound and light pattern plays and the game resets.


## Libraries Used

- `Tone.h` – for generating audio tones


## Notes

- This project was built as a learning exercise in:
  - Embedded logic
  - Input handling
  - Game state management
  - Hardware interaction


## License

This project is open for learning and experimentation.
