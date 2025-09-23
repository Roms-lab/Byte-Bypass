#include <windows.h>
#include <iostream>
#include <cstdlib>
#include <string>
#include <thread>#include <windows.h>
#include <iostream>
#include <cstdlib>
#include <Psapi.h>
#include <string>
#include <thread>
#include <chrono>
#include <limits>


std::string Mem_Value;
std::string Exe;
std::string Mem_Address;

std::string* PMem_Value = &Mem_Value;
std::string* PExe = &Exe;
std::string* PMem_Address = &Mem_Address;

DWORD FindProcessId(const std::string& exeName) {
    DWORD aProcesses[1024], cbNeeded, cProcesses;
    if (!EnumProcesses(aProcesses, sizeof(aProcesses), &cbNeeded)) {
        return 0;
    }
    cProcesses = cbNeeded / sizeof(DWORD);
    for (unsigned int i = 0; i < cProcesses; i++) {
        if (aProcesses[i] != 0) {
            TCHAR szProcessName[MAX_PATH] = TEXT("<unknown>");
            HANDLE hProcess = OpenProcess(PROCESS_QUERY_INFORMATION | PROCESS_VM_READ, FALSE, aProcesses[i]);
            if (hProcess != NULL) {
                HMODULE hMod;
                DWORD cbNeeded2;
                if (EnumProcessModules(hProcess, &hMod, sizeof(hMod), &cbNeeded2)) {
                    GetModuleBaseName(hProcess, hMod, szProcessName, sizeof(szProcessName)/sizeof(TCHAR));
                    
                    #ifdef UNICODE
                        std::wstring ws(szProcessName);
                        std::string s(ws.begin(), ws.end());
                        if (exeName.compare(s) == 0) {
                            CloseHandle(hProcess);
                            return aProcesses[i];
                        }
                    #else
                        if (exeName.compare(szProcessName) == 0) {
                            CloseHandle(hProcess);
                            return aProcesses[i];
                        }
                    #endif
                }
                CloseHandle(hProcess);
            }
        }
    }
    return 0;
}

void ScanMemory(const std::string& exeName) {
    DWORD pid = FindProcessId(exeName);
    if (pid == 0) {
        std::cout << "Could not find process: " << exeName << std::endl;
        return;
    }
    
    HANDLE hProcess = OpenProcess(PROCESS_QUERY_INFORMATION | PROCESS_VM_READ, FALSE, pid);
    if (hProcess == NULL) {
        std::cerr << "OpenProcess failed. Error: " << GetLastError() << std::endl;
        return;
    }

    std::cout << "Scanning Memory of -> {" << exeName << "}" << "\n";
    std::cout << "\n";

    MEMORY_BASIC_INFORMATION mbi;
    LPVOID address = 0;
    size_t regions_scanned = 0;

    while (VirtualQueryEx(hProcess, address, &mbi, sizeof(mbi))) {
        // Only print addresses of committed memory
        if (mbi.State == MEM_COMMIT) {
            std::cout << "Region found: 0x" << std::hex << (long long)mbi.BaseAddress 
                      << " - 0x" << std::hex << (long long)mbi.BaseAddress + mbi.RegionSize 
                      << " (Size: " << std::dec << mbi.RegionSize << " bytes)\n";
            regions_scanned++;
        }
        address = (LPVOID)((char*)mbi.BaseAddress + mbi.RegionSize);
    }
    
    CloseHandle(hProcess);
    std::cout << "\nScan finished. Found " << regions_scanned << " committed memory regions.\n";
}

void WaitSeconds(int seconds) {
    std::this_thread::sleep_for(std::chrono::seconds(seconds));
}

void WaitMiliSeconds(int MiliSeconds) {
    std::this_thread::sleep_for(std::chrono::milliseconds(MiliSeconds));
}

void Pause() {
    std::cout << "Please Press Enter." << std::endl;
    std::cin.clear();
    std::cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
}

int main() {

    std::cout << "    --[#101001]ByteBypass[#101001]--\n";
    std::cout << "A Simple Program For Cheating Using Memory\n";
    std::cout << "             --Made By Zach--   \n";
    std::cout << "\n";

    std::cout << "Press Anything To Run Program. ";
    std::cin.get();
    while (true) {

        system("cls");
        std::cout << "[1]: Enter Exe Name\n";
        std::cout << "[2]: Select Memory Adress\n";
        std::cout << "[3]: Set Memory Adress\n";
        std::cout << "[4]: List Values\n";
        std::cout << "[5]: Clear All Values Used (May Cause Bugs)\n";
        std::cout << "[6]: List All Addresses of Current exe\n";
        std::cout << "[7]: Scan Exe for a memory value.\n";
        std::cout << "[Help]: Get helpfull quotes on how to use the program\n";
        std::cout << "[Credits]: Get the credits on the program and its creator\n";
        std::cout << "\n";

        std::string Option;
        std::cout << "Option -> ";
        std::cin >> Option;
        system("cls");

        if (Option == "1") {
            std::cout << "Exe -> ";
            std::cin >> Exe;
            std::cout << "\nExe Selected -> {" << Exe << "}\n";
            std::cout << PExe << "\n";
            Pause();
            std::cin.get();
        }
        else if (Option == "2") {
            std::cout << "Adress -> ";
            std::cin >> Mem_Address;
            std::cout << "\nCurrent Adress Selected -> {" << Mem_Address << "}\n";
            std::cout << PMem_Address << "\n";
            Pause();
            std::cin.get();
        }
        else if (Option == "3") {
            if (Mem_Address == "") {
                std::cout << "Error. No Adress Selected.";
            }
            else {
                std::cout << "Value -> ";
                std::cin >> Mem_Value;
                std::cout << "\nValue Set To -> {" << Mem_Value << "}\n";
                std::cout << PMem_Value << "\n";
                Pause();
                std::cin.get();
            }
        }
        else if (Option == "4") {
            std::cout << "Exe -> " << *PExe << "  Address -> " << PExe << "\n";
            std::cout << "Mem Adress -> " << *PMem_Address << "  Address -> " << PMem_Address << "\n";
            std::cout << "Mem Value -> " << *PMem_Value << "  Address -> " << PMem_Address << "\n";
            Pause();
            std::cin.get();
        }
        else if (Option == "5") {
            Exe.clear();
            Mem_Address.clear();
            Mem_Value.clear();
            std::cout << "All Values Cleared.\n";
            Pause();
            std::cin.get();

        }
        else if (Option == "6") {
            if (Exe == "") {
                std::cout << "Error. No Exe Selected.\n";
                Pause();
                std::cin.get();
            }
            else {
                ScanMemory(Exe);
                WaitSeconds(1);
                Pause();
                std::cin.get();
            }
        }
        else if (Option == "7") {
            if (Exe == "") {
                std::cout << "Error. No Exe Selected.\n";
                Pause();
                std::cin.get();
            }
            else {
                std::cout << "Not Currently Implemented.\n";
            }
        }
        else if (Option == "Help") {
            std::cout << "Option 1 -> Select the exe you want to modify.\n";
            std::cout << "Option 2 -> Select a direct memory address to modify.\n";
            std::cout << "Option 3 -> Set the value of a selected memory address.\n";
            std::cout << "Option 4 -> Show the values and addresses of all used values.\n";
            std::cout << "Option 5 -> Clear all currently used values.\n";
            std::cout << "Option 6 -> Scan the memory of a selected exe.\n";
            std::cout << "Option 7 -> Scan the memory for a specific value.\n";
            std::cout << "\n";

            Pause();
            std::cin.get();
        }
        else if (Option == "Credits") {
            std::cout << "-- Made By Zach --\n";

            Pause();
            std::cin.get();
        }
        else {
            std::cout << "Error: " << "\033[32m";
            std::cout << "<invalid option.>\n";
            std::cout << "\033[0m" << "\n";
            WaitSeconds(2);
            system("cls");
        }
    }
}
#include <chrono>
#include <limits>

void ScanMemory() {

}

void WaitSeconds(int seconds) {
    std::this_thread::sleep_for(std::chrono::seconds(seconds));
}

void WaitMiliSeconds(int MiliSeconds) {
    std::this_thread::sleep_for(std::chrono::milliseconds(MiliSeconds));
}

void Pause() {
    std::cout << "Please Press Enter." << std::endl;
    std::cin.clear();
    std::cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
}

int main() {

    std::string Mem_Value;
    std::string Exe;
    std::string Mem_Address;

    std::string* PMem_Value = &Mem_Value;
    std::string* PExe = &Exe;
    std::string* PMem_Address = &Mem_Address;

    std::cout << "    --[#101001]ByteBypass[#101001]--\n";
    std::cout << "A Simple Program For Cheating Using Memory\n";
    std::cout << "             --Made By Zach--   \n";
    std::cout << "\n";

    std::cout << "Press Anything To Run Program. ";
    std::cin.get();
    while (true) {

        system("cls");
        std::cout << "[1]: Enter Exe Name\n";
        std::cout << "[2]: Select Memory Adress\n";
        std::cout << "[3]: Set Memory Adress\n";
        std::cout << "[4]: List Values\n";
        std::cout << "[5]: Clear All Values Used (May Cause Bugs)\n";
        std::cout << "[6]: List All Addresses of Current exe\n";
        std::cout << "[Help]: Get helpfull quotes on how to use the program\n";
        std::cout << "[Credits]: Get the credits on the program and its creator\n";
        std::cout << "\n";

        std::string Option;
        std::cout << "Option -> ";
        std::cin >> Option;
        system("cls");

        if (Option == "1") {
            std::cout << "Exe -> ";
            std::cin >> Exe;
            std::cout << "\nExe Selected -> {" << Exe << "}\n";
            std::cout << PExe << "\n";
            Pause();
            std::cin.get();
        }
        else if (Option == "2") {
            std::cout << "Adress -> ";
            std::cin >> Mem_Address;
            std::cout << "\nCurrent Adress Selected -> {" << Mem_Address << "}\n";
            std::cout << PMem_Address << "\n";
            Pause();
            std::cin.get();
        }
        else if (Option == "3") {
            if (Mem_Address == "") {
                std::cout << "Error. No Adress Selected.";
            }
            else {
                std::cout << "Value -> ";
                std::cin >> Mem_Value;
                std::cout << "\nValue Set To -> {" << Mem_Value << "}\n";
                std::cout << PMem_Value << "\n";
                Pause();
                std::cin.get();
            }
        }
        else if (Option == "4") {
            std::cout << "Exe -> " << *PExe << "  Address -> " << PExe << "\n";
            std::cout << "Mem Adress -> " << *PMem_Address << "  Address -> " << PMem_Address << "\n";
            std::cout << "Mem Value -> " << *PMem_Value << "  Address -> " << PMem_Address << "\n";
            Pause();
            std::cin.get();
        }
        else if (Option == "5") {
            Exe.clear();
            Mem_Address.clear();
            Mem_Value.clear();
            std::cout << "All Values Cleared.\n";
            Pause();
            std::cin.get();

        }
        else if (Option == "6") {
            if (Exe == "") {
                std::cout << "Error. No Exe Selected.\n";
                Pause();
                std::cin.get();
            }
            else {
                std::cout << "Scanning Memory...\n";
                WaitSeconds(1);
                ScanMemory();
                Pause();
                std::cin.get();
            }
        }
        else if (Option == "Help") {
            std::cout << "Option 1 -> Select the exe you want to modify.\n";
            std::cout << "Option 2 -> Select a direct memory address to modify.\n";
            std::cout << "Option 3 -> Set the value of a selected memory address.\n";
            std::cout << "Option 4 -> Show the values and addresses of all used values.\n";
            std::cout << "Option 5 -> Clear all currently used values.\n";
            std::cout << "Option 6 -> Scan the memory of a selected exe.\n";
            std::cout << "\n";

            Pause();
            std::cin.get();
        }
        else if (Option == "Credits") {
            std::cout << "-- Made By Zach --\n";

            Pause();
            std::cin.get();
        }
        else {
            std::cout << "Error: " << "\033[32m";
            std::cout << "<invalid option.>\n";
            std::cout << "\033[0m" << "\n";
            WaitSeconds(2);
            system("cls");
        }
    }
}

