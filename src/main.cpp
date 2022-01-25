#include <iostream>
#include "PlayerInfo/Player.h"
#include "MapInfo/GameMap.h"
#include "Managers/GameManager.h"
#include "Managers/EventSystem/TextTranslator/EventTextStorage/EventTextTranslator.h"


bool handleInput(GameManager &man, const std::string &line);

void printInputOptions();

int main() {


    /*try {

        v.setValue<std::string>("test", "REPLACED");
        std::cout << EventTextTranslator::translate("Test should have {test} this", v) << std::endl;
        std::cout << EventTextTranslator::translate("{test} should this be {test}?", v) << std::endl;

    }catch (std::runtime_error& e){
        std::cout << e.what();
    }*/

    Player p1("BigBoi", "Battleaxe", Pronouns::masculine());
    Player p2("Old Asian Man", "Nunchucks", Pronouns::masculine());
    /*std::vector<Player> surv;
    std::vector<Player> dead;
    surv.push_back(p1);
    dead.push_back(p2);

    TextVariables v;
    v.setValue<std::vector<Player>>(TextVariables::KEY_SURVIVORLIST(), surv);
    v.setValue<std::vector<Player>>(TextVariables::KEY_DEADLIST(), dead);

    std::string tes = "Hesitantly, {[FIGHT_SURVIVORLIST,(LAMBDA_PLAYERNAME)]} team up and kill {[FIGHT_DEADLIST,(LAMBDA_PLAYERNAME)]}\n";
    EventTextTranslator translator;
    std::cout << translator.translate(v, tes) ;*/




    Player p3("Super Woman", "Super Gun", Pronouns::feminine());
    Player p4("Super Worm", "Super Teeth", Pronouns::neutral());
    Player p5("tiny anime character", "Big ass sword", Pronouns::neutral());
    Player p6("big anime character", "small ass sword", Pronouns::neutral());
    GameManager man{GameMap::getMultifightTestMap()};


    man.registerPlayer({p1,p2,p3,p4,p5,p6});
    man.printMap();


    std::string line;
    bool running;
    do{
        std::cout << "-------------------------------------------\n\n";
        running = handleInput(man, line);

        if(running) {
            std::cout << "input help: to see all commands." << std::endl;
            std::cout << "input a command to continue:" << std::endl;
        }
    }while (running && std::getline(std::cin, line));

    return 0;
}

void printInputOptions() {

    std::cout << "command/shortcut: command description." << std::endl << std::endl;
    std::cout << "help / h: displays all comands of the menu you are in." << std::endl;
    std::cout << "next / n: advances the game to the next turn." << std::endl;
    std::cout << "events / e: shows current days events." << std::endl;
    std::cout << "map / m: shows current map." << std::endl;
    std::cout << "quit / q: Quits program." << std::endl;
}

bool handleInput(GameManager &man, const std::string &line) {
    if(line == "q" || line == "quit") return false;
    if(line == "next" || line == "n"){
        return man.tick();
    }
    else if(line == "map" || line == "m"){
        man.printMap();
    }
    else if(line == "e" || line == "events"){
        man.printEvents();
    }
    else if(line == "help" || line == "h"){
        printInputOptions();
    }

    return true;

}
