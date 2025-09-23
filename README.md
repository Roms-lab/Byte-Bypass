# Byte-Bypass

A command-line tool for exploiting games and debugging applications by reading and modifying process memory.
Byte-Bypass is for educational and security research purposes, helping to understand how game memory works and how vulnerabilities can be exploited.

## Usage: Game Cheating and Debugging

The primary purpose of Byte-Bypass is to assist in the following activities:
*   **Game Exploitation**: Use the tool to find and modify values in a game's memory (such as health, currency, or resources) for cheating or research.
*   **Debugging**: Inspect the memory addresses of applications to understand their internal state and debug issues.

### Key features
*   **Set Executable**: Target and attach to a specific process by setting an executable variable [1.0].
*   **Choose Memory Addresses**: Select specific memory addresses to monitor and alter [1.0].
*   **View Active Values**: Display all currently monitored memory addresses and their values using raw pointers [1.1].
*   **Input Validation**: Prevent errors by checking for a valid memory address before attempting to change its value [1.2].
*   **Interactive Help**: Type `-> Help` inside the program for a detailed explanation of each function [1.2].
*   **Color-Coded Errors**: Receive clear, color-coded error messages for better debugging [1.4].

## Supported Platforms

*   **Windows 10/11**: ✅
*   **Linux**: ❌ (Coming Soon)
*   **Mac OS**: ❌ (Coming Soon)
*   **ARM Windows**: ⚠️ (Untested)
*   **ARM Linux**: ❌

## Building From Source

To compile this tool, you will need the GCC compiler.
1.  **Clone** the repository:
    ```bash
    git clone https://github.com/Roms-lab/Byte-Bypass.git
    cd Byte-Bypass
    ```
2.  **Compile** the source code:
    ```bash
    gcc your_source_file.c -o Byte-Bypass.exe
    ```
3.  **Run** the compiled executable:
    ```bash
    ./Byte-Bypass.exe
    ```

## Changelog

*   **Version 1.0**: Finished basic frame of the project. Can set executable variable and choose memory addresses.
*   **Version 1.1**: Small bug fixes and added the ability to view all active memory addresses and values using raw pointers.
*   **Version 1.2**: Added checks when changing memory. Now includes `-> Help` for detailed function descriptions.
*   **Version 1.3**: Added Credits tab. SELF PROMOTION WOOOO!
*   **Version 1.4**: Fixed error handling and added color to the Error type.
*   **Version 1.5**: Added WaitSeconds() and WaitMiliSeconds() for easier waiting so development will be easier.
*   **Version 1.6**: Replaced long pause cmd every time needing to pause with Pause() Function.
*   **Version 1.7**: Fixed compiler error with the Pause() function.
*   **Version 1.8**: Scanning memory of selected exe is offically implemented. Currently you cannot scan exe's with spaces. Will be fixed in version 1.9 or later.

## Credits

**Author**: Zach / Roms-lab
