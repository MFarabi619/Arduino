import pyautogui
import pyperclip

# Get a valid input from the user
def getInput(prompt=""):
    while True:
        user_input = input(prompt).lower()
        if user_input in ['yes', 'y', 'no', 'n']:
            return user_input in ['yes', 'y']
        else: 
            print("Invalid input. Please enter 'y' or 'n'.")

# print("\nPlease ensure that the Fritzing program is open in fullscreen and on the correct file!\n")

secs_between_keys = 0.04
projectPath = ''
projectName = ''

# Locate the Fritzing icon on the taskbar, and click on it
def locateFritzingIcon():
    pyautogui.moveTo(pyautogui.locateCenterOnScreen("./Scripts/Fritzing_icon.png", region=(0,1030,1920,50), confidence =0.9))
    pyautogui.click()


# Copy project path
def copyProjectPathandName():
    global projectPath
    global projectName

    pyautogui.hotkey('ctrl','shift','s',interval=secs_between_keys) 
    pyautogui.hotkey('ctrl','c',interval=secs_between_keys)
    projectName = pyperclip.paste()
    pyautogui.hotkey('alt','d',interval=secs_between_keys)
    pyautogui.hotkey('ctrl','c',interval=secs_between_keys)
    projectPath = pyperclip.paste()
    pyautogui.hotkey('alt', 'f4',interval=secs_between_keys)


# Navigate to export image window
def navigateToExportImageWindow():
    pyautogui.hotkey('alt', 'f',interval=secs_between_keys)
    pyautogui.press('e',interval=secs_between_keys)
    pyautogui.press('enter', presses=2, interval=secs_between_keys)

# Paste in project path and get project name
def pastePathAndName(name):
    pyautogui.typewrite(projectName+' '+name)
    pyautogui.hotkey('alt','d',interval=secs_between_keys)
    pyautogui.typewrite(projectPath)
    pyautogui.press('enter', interval=secs_between_keys)
    pyautogui.hotkey('alt','s', interval=secs_between_keys)


# Set export DPI to 1200
def setExportDPI():
    pyautogui.hotkey('ctrl','a', interval=secs_between_keys)
    pyautogui.write('1200')
    pyautogui.press('enter', interval=secs_between_keys)
    # wait for export to complete
    pyautogui.sleep(3)

locateFritzingIcon()
copyProjectPathandName()

# Click on Breadboard button
pyautogui.moveTo(237,70)
pyautogui.click()
navigateToExportImageWindow()
pastePathAndName("Wiring Diagram")
setExportDPI()

# Click on Schematic button
pyautogui.moveTo(388,67)
pyautogui.click()
navigateToExportImageWindow()
pastePathAndName("Circuit Schematic")
setExportDPI()
