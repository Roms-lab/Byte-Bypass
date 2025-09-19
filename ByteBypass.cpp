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
            std::cout << "Value -> ";
            std::cin >> Mem_Value;
            std::cout << "\nValue Set To -> {" << Mem_Value << "}\n";
            std::cout << PMem_Value << "\n";
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Please Press Enter.";
            std::cin.get();
        }
        else if (Option == "4") {
            std:: cout << "Exe -> " << *PExe << "  Address -> " << PExe << "\n";
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
                std::cout << "Please Press Enter.";
                std::cin.get();
            }
        }
        else {
            std::cout << "ERROR. invalid option.\n";
            std::cout << "Aborting program to avoid further Errors...";
            std::this_thread::sleep_for(std::chrono::seconds(3));
                break;
        }
    }
}
