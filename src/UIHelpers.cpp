//
// Created by benja on 26/01/2022.
//

#include "UIHelpers.h"
#include "PlayerInfo/Player.h"
#include "MapInfo/GameMap.h"
#include "Managers/GameManager.h"


//THESE FUNCTIONS HANDLE PLAYER INPUT


bool handleInput(GameManager &man, const std::string &line) {
    if(line == "q" || line == "quit") {
        std::cout << "do you really wish to end the current Game?" << std::endl;
        return !getConfirmation();
    }
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
    else if(line == "credits" || line == "c"){
        printCredits();
    }

    return true;

}

std::string pressEnterToContinue(){
    std::cout << std::endl << "press \"Enter\" to continue\n";
    std::string temp;
    std::getline(std::cin,temp);
    return temp;
}

bool getConfirmation() {
    std::string line;
    do{
        std::cout << std::endl << "enter:\n";
        std::cout << "y= Yes; n=No\n";
        std::getline(std::cin, line);
    } while (line != "n" && line != "y");
    std::cout << std::endl;
    return line == "y";
}




//ACTUAL LOGIC

GameManager setupGame() {
    std::vector<Player> showcaseList(
            {
                    Player("Kerbal", "explosive rocket part", Pronouns::neutral()),
                    Player("Corvo", "Dagger", Pronouns::masculine()),
                    Player("The Pope", "holy prayer bonk", Pronouns::neutral()),
                    Player("Sister of Battle", "Flamer", Pronouns::feminine()),
                    Player("Ironmouse", "flying Monkey", Pronouns::feminine()),
            }
    );
    std::vector<Player> playerList;
    GameManager man{GameMap::getMap1()};
    std::cout << "In this Game, up to six characters face off on a deserted Island.\n"
                 "The last person or thing standing wins.\n"
                 "You decide who enters the competition.\n"
                 "In this current version of the game, the characters act on their own, you have no influence over them.\n";
    pressEnterToContinue();
    std::cout << isolator();
    std::cout << "You create the Participants, entering a name, weapon and their gender/pronouns.\n"
                 "Feel free to write whatever crazy sh*t sounds fun to you.\n"
                 "I try to use the info as much as possible in text generation.\n";
    if (pressEnterToContinue() == "test") {
        playerList = showcaseList;
    }

    do {
        if(playerList.size() >= 3){
            std::cout << "Do you wish to enter more Participants?" << std::endl;
            if(!getConfirmation()) break;
        }
        insertNewPlayer(playerList);
    } while (playerList.size() < 6);
    man.registerPlayer(playerList);
    return man;
}

void insertNewPlayer(std::vector<Player> &playerList) {
    std::string name, weapon, pronoun;
    do {

        std::cout << "Enter the Participants Name or Title\n";
        std::getline(std::cin, name);

        std::cout << "Enter the Weapons Name.\n"
                     "This weapon will be wielded or used by the character to decimate their enemies\n";
        std::getline(std::cin, weapon);
        do {
            std::cout << "Choose what Pronouns should be used for the character\n";
            std::cout << "m=masculine(he/his/him)\n f=feminine(she/her/her)\n n=neutral(they/their/them)\n";
            std::getline(std::cin, pronoun);
        }while(pronoun != "m" && pronoun != "f" && pronoun != "n");
        std::cout << "Please confirm the information, you will NOT be able to change it later\n";
        std::cout << "Name: " << name << std::endl;
        std::cout << "Weapon: " << weapon << std::endl;
        std::cout << "Pronouns: " << pronoun << std::endl;
    } while(!getConfirmation());
    Pronouns chosenPronouns = (pronoun == "m") ? Pronouns::masculine() : (pronoun == "f") ? Pronouns::feminine() : Pronouns::neutral();
    playerList.emplace_back(name, weapon, chosenPronouns);
}


//THESE FUNCTIONS ONLY OUTPUT CERTAIN INFORMATION WHEN NEEDED

std::string isolator(){
    return "------------------------------------------------\n";
}

void printCredits() {
    std::cout
              << isolator() <<
              "BATTLE ROYALE SIMULATOR V1.0 by Benjamin Wenger\n"
              << isolator() <<
              "This is a game inspired by Brant Steele's Hunger games simulator.[https://brantsteele.net/hungergames/disclaimer.php]\n"
              "I designed and programmed this game for the Gaming Technology course at my university in 2022 by myself.\n"
              << isolator() << std::endl;
}

void printInputOptions() {

    std::cout << "command/shortcut: command description." << std::endl << std::endl;
    std::cout << "help / h: displays all comands of the menu you are in." << std::endl << std::endl;
    std::cout << "next / n: advances the game to the next turn." << std::endl;
    std::cout << "events / e: shows current days events." << std::endl;
    std::cout << "map / m: shows current map." << std::endl << std::endl;
    std::cout << "credits / c: shows credits." << std::endl;
    std::cout << "quit / q: Quits current game." << std::endl;
}

