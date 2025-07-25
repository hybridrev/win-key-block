# Win Key Block

I don't know is this kind a stupid stuff? But actually i can fix my problem with this, so this is C++ program that blocks the **Windows key** at the **kernel level** using [Interception Driver](https://github.com/oblitum/Interception).  
Useful for thing if you experiencing **keyboard flooding (in the case is me)** due to hardware faults that cause the Windows key to trigger randomly. 

### Speaking about a problem
My laptop win key have flood issue. Not only that, this flood error can cause your Windows system freeze and Blue Screen.
I was try disabling win key with registry and many kind software, and still nothing the Windows still crashing in couple minutes so that why i made this program.

---

## Anyway, what a program actually do?

- Blocks the **Win key** completely from the Windows system
- Operates at **kernel level which is Windows NT**
- Effectively solution for **Flooding error at fcking Win key** without disabling the internal keyboard so you still can use internal keyboard
- Can fix Windows crashing (Hell yeah dude) 
- And you actually can modified your own in .cpp code

---

## How to use

### 1. Install Interception Driver  
> One-time setup (Admin privileges required)
  - Download the Interception driver: [https://github.com/oblitum/Interception/releases](https://github.com/oblitum/Interception/releases)
  - Extract the files  
  - Run `install-interception.exe` as **Administrator**  
  - Restart Windows after installation

> For make sure your Interception Driver installed properly
  - Open Command Prompt
  - Type this command `driverquery | findstr /i keyb`
  - If you see "keyboard - Keyboard Upper Filter" that mean Interception Driver already installed
![Preview](https://raw.githubusercontent.com/hybridrev/win-key-block/refs/heads/main/img/Screenshot%202025-07-25%20202605.jpg)

### 2. Run `intercept.exe`

- Run `intercept.exe` normally (**no window will appear**, but it's running in the background)
- And if success it will be block you win key, if don't? You can run `intercept-debug.exe` to see your keyboard actually detect it or not
- Or build it yourself at `intercept.cpp` using `cl.exe` for compile

### 3. Run `add-to-startup.bat` (Optional)

- Run `add-to-startup.bat` to create a shortcut in the **All Users** Startup folder  
- This allows the app to automatically run every time Windows boots

---

## Build

**Requirements:**
- Visual Studio with the **Desktop Development with C++** workload (It just for compile cpp)
- Interception SDK with:
  - `interception.h`
  - `interception.lib`  
  (Place both in the `library/` folder)

**Compile Commands:**

```bash
cl intercept.cpp /I library library\interception.lib /link /SUBSYSTEM:WINDOWS
cl intercept-debug.cpp /I library library\interception.lib
```

---

## Credits
**Thanks for:**
  - [Interception Driver by @oblitum](https://github.com/oblitum/Interception)
  - [Stackoverflow User from 15 years ago](https://stackoverflow.com/questions/3270434/how-do-i-intercept-windows-key-under-windows-7/8844117#8844117) (Thank you so much i love you) 

---
© 2025 AbenDoesn't
