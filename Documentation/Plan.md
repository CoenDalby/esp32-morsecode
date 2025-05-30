# What are we doing?

We're making a morse code interpreter. Later, it can be used as a bluetooth keyboard. It'll work out what letter you're typing internally and then send it as a message after receiving no input for some amount of time.

# Phases
1. Make it output just a dot or dash based on how long the button is pressed.
2. Store dots/dashes in a buffer, attempt to interpret the buffer and print the corresponding letter after x milliseconds with no input.
3. Send the letter as a keyboard input over Bluetooth.