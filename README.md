# **AVR Microcontroller Seven-Segment Display Counter**

## **Overview**
This project demonstrates the use of an AVR microcontroller to control a two-digit seven-segment display. The display counts numbers from 0 to 99, with inputs from two buttons:
- **Increment Button**: Increases the counter value.
- **Reset Button**: Resets the counter to 0.

The project is designed for learning low-level embedded systems programming.

---

## **Features**
- **Dynamic Number Display**:
  - Two-digit numbers (0–99) are displayed on a seven-segment display.
- **Input Handling**:
  - Buttons for incrementing and resetting the counter.
  - Debouncing logic ensures stable button presses.
- **Efficient GPIO Management**:
  - Individual control of segments using AVR `PORTx` and `DDRx` registers.


