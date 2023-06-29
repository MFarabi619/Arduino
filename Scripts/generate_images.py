import pyautogui

def getInput(prompt=""):
    while True:
        user_input = input(prompt).lower()
        if user_input in ['yes', 'y', 'no', 'n']:
            return user_input in ['yes', 'y']
        else: 
            print("Invalid input. Please enter 'y' or 'n'.")

print("\nPlease ensure the the Fritzing file is open and visible on the main monitor. The script will alt+Tab to it.\n")
getInput("Is the Fritzing file open?\n")

secs_between_keys = 0.01

pyautogui.hotkey('alt','tab',interval=secs_between_keys)
pyautogui.hotkey('alt', 'f',interval=secs_between_keys)
pyautogui.press('e',interval=secs_between_keys)
pyautogui.press('enter',interval=secs_between_keys)
