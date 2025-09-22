#include <iostream>
#include <cstdlib>
#include <string>
#include <thread>
#include <chrono>
#include <limits>

int main() {

    // Set Values For Options
    std::string Mem_Value;
    std::string Exe;
    std::string Mem_Address;

    // Set Points For Values Just In Case
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
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Please Press Enter.";
            std::cin.get();
        }
        else if (Option == "2") {
            std::cout << "Adress -> ";
            std::cin >> Mem_Address;
            std::cout << "\nCurrent Adress Selected -> {" << Mem_Address << "}\n";
            std::cout << PMem_Address << "\n";
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Please Press Enter.";
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
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Please Press Enter.";
                std::cin.get();
            }
        }
        else if (Option == "4") {
            std::cout << "Exe -> " << *PExe << "  Address -> " << PExe << "\n";
            std::cout << "Mem Adress -> " << *PMem_Address << "  Address -> " << PMem_Address << "\n";
            std::cout << "Mem Value -> " << *PMem_Value << "  Address -> " << PMem_Address << "\n";
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Please Press Enter.";
            std::cin.get();
        }
        else if (Option == "5") {
            Exe.clear();
            Mem_Address.clear();
            Mem_Value.clear();
            std::cout << "All Values Cleared.\n";
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Please Press Enter.";
            std::cin.get();

        }
        else if (Option == "6") {
            if (Exe == "") {
                std::cout << "Error. No Exe Selected.\n";
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Please Press Enter.";
                std::cin.get();
            }
            else {
                std::cout << "Scanning Memory...\n";
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::this_thread::sleep_for(std::chrono::seconds(1));
                std::cout << "Please Press Enter.";
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

            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Please Press Enter.";
            std::cin.get();
        }
        else if (Option == "Credits") {
            std::cout << "-- Made By Zach --\n";

            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "\nPlease Press Enter.";
            std::cin.get();
        }
        else {
            std::cout << "Error: " << "\033[32m";
            std::cout << "<invalid option.>\n";
            std::cout << "\033[0m" << "\n";
            std::this_thread::sleep_for(std::chrono::seconds(2));
            system("cls");
        }
    }
}
