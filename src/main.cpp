#include <iostream>
#include "UIHelpers.h"
#include "PlayerInfo/Player.h"
#include "MapInfo/GameMap.h"
#include "Managers/GameManager.h"
#include "EventSystem/TextTranslator/EventTextTranslator.h"






int main() {
    printCredits();
    bool running = true;
    do {
        GameManager man = setupGame();
        man.printMap();

        std::string line;
        do {
            std::cout << "-------------------------------------------\n\n";
            running = handleInput(man, line);

            if (running) {
                std::cout << "input help: to see all commands." << std::endl;
                std::cout << "input a command to continue:" << std::endl;
            }
        } while (running && std::getline(std::cin, line));
        std::cout << "Do you wish to start a new Game?" << std::endl;
        running = getConfirmation();
    } while (running);
    return 0;
}


