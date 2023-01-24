// Assignment1TurnBased.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <thread>


using namespace std;


void BattleEvent();
void TriggerChoice();
void CharacterCreate();

//Player
int playerclass;
int attack;
int skillDamage;
int playerHP;
int healPlayer;
int ultAttackDamage;
int ultHPloss;
string skillname;
string userName;
string ultAttack;
string ultAttackChant;


//Enemy
int eAttack;
int eHP;

int main()
{
    cout << "TEXT BATTLE SIMULATOR\n\n";
    cout << "A very casual quest is about to begin! \n";
    std::this_thread::sleep_for(1s);

    do
    {
        cout << "PRESS ENTER TO START!\n";
    } while (cin.get() != '\n');



    CharacterCreate(); // To Creation Function


}

void CharacterCreate()
{


    cout << "Please select a name: ";
    cin >> userName;

    cout << "Welcome: " << userName << endl << endl;
    std::this_thread::sleep_for(1s); //Wait for a second

    cout << "                          --Choose a Class--\n\n"
        "------[1] Fighter ------\n"
        "Focus on dealing damage close up with your legendary Sword.\n\n"
        "------[2] Mage ------\n"
        "Rely on your Mana and attack from a distance.\n\n";


    cin >> playerclass;

    switch (playerclass) // Switch giving the player the option between the 2 classes, also sets the stats for each one.
    {
    case 1:
        playerHP = 100;
        attack = 7;
        skillDamage = 12;
        ultAttackDamage = 30;
        ultHPloss = 15;
        skillname = "Blade Style: Lightning Flash!";
        ultAttack = "SECRET ART: Hattenshou! ";

        ultAttackChant = "You take a deep breath before pushing your body to its limit and move insanely fast dealing a consecutive barrage of slashes!  ";

        cout << "\n<FIGHTER SELECTED>\n";
        cout << "\nEquipped: Generic Cool Glowy Sword";
        cout << "\nAttack +5";
        cout << "\nSkill Learnt: Blade Style: Lightning Flash! +12";
        cout << "\nSECRET ART Learnt: Hattenshou! +30 \n\n";
        std::this_thread::sleep_for(1s);
        TriggerChoice();
        break;
    case 2:
        playerHP = 80;
        attack = 2;
        skillDamage = 15;
        ultAttackDamage = 35;
        ultHPloss = 15;
        skillname = "Wind Style: Hyper Slash!";
        ultAttack = "SECRET ART: Al Fura! ";

        ultAttackChant = "You begin to mix the air around you with the mana to unleash a devistating amount of wind blades at the enemy! ";

        cout << "\n<MAGE SELECTED>\n";
        cout << "\nEquipped: Generic Mystic Staff of Wind";
        cout << "\nAttack +2";
        cout << "\nSkill Learnt: Wind Style: Hyper Slash! +15 ";
        cout << "\nSECRET ART Learnt: Al Fura! +35 \n\n";
        std::this_thread::sleep_for(1s);
        TriggerChoice();
        break;


    default:
        cout << "What? Thats not right.\n";
        break;
    }
    return;

}

void TriggerChoice() //Funtion for the story event
{

    cout << "                          --THE NEXT DAY--\n\n";
    std::this_thread::sleep_for(1s);

    cout << "Finally determined to gain power you venture outside exploring to hopefully find something to fight. \n";
    std::this_thread::sleep_for(1s);

    int Fight;

    cout << "\nHeading out of town, You see a suspicious foe in the distance. They appear to be quite powerful. Attack them?\n[1] Heck Yeah I Will! \n[2] Nah Ill Pass \n";
    cin >> Fight;
    std::this_thread::sleep_for(1s);

    if (Fight == 1)
    {
        cout << "\n\n[" << userName << "]" << " Well this might be stupid and go terribly wrong but I want try this class out and they seem like a suitable opponent.\n\n";
        std::this_thread::sleep_for(2s);

        cout << "You Approach them but before even getting to ask them anything they had already vanished out of your line of sight!\n";
        std::this_thread::sleep_for(2s);

        cout << "Barely being able to react you manage to avoid the attack\n";
        std::this_thread::sleep_for(2s);

        cout << "\n\n[" << userName << "]" << " No turning back now LETS BEGIN!.\n\n";
        BattleEvent(); //Triggers the battle event function
    }
    else if (Fight == 2)
    {
        // Game Simply Ends //
        cout << "Wise Choice, You head home and go to sleep instead.\n";
        std::this_thread::sleep_for(1s);
        cout << "The world was taken over and is beyond saving. Great Job Hero.....\n";
        std::this_thread::sleep_for(1s);

    }
    else
    {
        // Incorrect Response, Returns to Main //
        cout << "What? No. Lets try that again.\n\n";
        return TriggerChoice();
    }
}

void BattleEvent() //Battle Stuff Starts Here
{
    int BattleChoice;



    cout << "--------- GET READY TO FIGHT ---------\n\n";
    std::this_thread::sleep_for(1s);

    //Enemy Set Stats
    eHP = (10 + rand() % 50);
    eAttack = (3 + rand() % 15);

    cout << "[Generic Antagonist]" << " HP:" << eHP << "\n\n";
    cout << "[" << userName << "] HP: " << playerHP << "\n\n";

    std::this_thread::sleep_for(1s);

    //Do while loop till either player or enemy is dead.
    do
    {

        cout << "--------------------------------------\n\n";

        cout << "[1] Basic Attack \n";
        cout << "[2] " << skillname << " \n"; //Gets the name based on the class you chose earlier.
        cout << "[3] Heal \n";
        cout << "[4] " << ultAttack << "[LOSE HP UPON USE]\n";
        cin >> BattleChoice;

        if (BattleChoice == 1)
        {
            attack = (attack + rand() % 2);
            cout << "Basic Attack Deals " << attack << " Damage!\n\n";

            eHP = eHP - attack; //Takes health away equal to the attack damage
            cout << "[Generic Antagonist]" << " HP:" << eHP << "\n\n";


        }
        else if (BattleChoice == 2)
        {
            skillDamage = (skillDamage + rand() % 2);
            cout << skillname << " Deals " << skillDamage << " Damage!\n\n";

            eHP = eHP - skillDamage;

            cout << "[Generic Antagonist]" << " HP:" << eHP << "\n\n";



        }
        else if (BattleChoice == 3)
        {
            healPlayer = (0 + rand() % 15); //Heal player randomly  
            playerHP = playerHP + healPlayer;
            cout << "You Healed up by " << healPlayer << "HP\n";

            cout << "Current HP is " << playerHP << "\n\n";



        }
        else if (BattleChoice == 4)
        {
            ultAttackDamage = (ultAttackDamage + rand() % 2);

            cout << ultAttackChant << "\n\n";
            std::this_thread::sleep_for(2s);

            cout << ultAttack << " Deals " << ultAttackDamage << " Damage!\n\n";

            playerHP = playerHP - ultHPloss;
            eHP = eHP - ultAttackDamage;

            std::this_thread::sleep_for(1s);

            cout << "You took " << ultHPloss << " Damage from using it!\n\n";

            cout << "[" << userName << "] HP: " << playerHP << "\n\n";

            cout << "[Generic Antagonist]" << " HP:" << eHP << "\n\n";


        }
        else
        {
            cout << "You Chose to do absolutely nothing....\n\n";

        }

        if (eHP <= 0)
        {
            cout << "You really thought it was over?\n";
            std::this_thread::sleep_for(1s);
            cout << "ITS NEVER OVER TIME TO REDO!\n\n";
            std::this_thread::sleep_for(1s);
            BattleEvent();
            break;
        }
        else
        {
            eAttack = (10 + rand() % 5);
            cout << "You were hit back dealing " << eAttack << " Damage!\n\n";

            playerHP = playerHP - eAttack;

            cout << "[" << userName << "] HP: " << playerHP << "\n\n";

        }


        if (playerHP <= 0)
        {
            cout << "YOU FREAKING DIED";
            break;
        }

        std::this_thread::sleep_for(1s);
    } while (playerHP >= 0 || eHP >= 0);


}