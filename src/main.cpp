#include <iostream>
#include "UIHelpers.h"
#include "Managers/GameManager.h"






int main() {
    try {
        printCredits();
        bool running = true;
        do {
            GameManager man = setupGame();
            man.printMap();

            std::string line;
            do {
                std::cout << isolator();
                running = handleInput(man, line);

                if (running) {
                    std::cout << "input help: to see all commands." << std::endl;
                    std::cout << "input a command to continue:" << std::endl;
                }
            } while (running && std::getline(std::cin, line));
            std::cout << "Do you wish to start a new Game?" << std::endl;
            running = getConfirmation();
        } while (running);
    }catch (std::exception& e){
        std::cout << "ERROR:" << e.what();
    }
    return 0;
}


