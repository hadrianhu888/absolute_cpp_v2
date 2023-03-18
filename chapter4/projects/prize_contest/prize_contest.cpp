    /**
    * @file prize_contestant.cpp
    * @author your name (you@domain.com)
    * @brief
    * @version 0.1
    * @date 2023-02-18
    *
    * @copyright Copyright (c) 2023
    *
    */

    #include "prize_contest.hpp"
    #include "common.hpp"

    int select_random_winnnig_door(void) { return rand() % 3 + 1; }

    int select_random_door(void) { return rand() % 3 + 1; }

    int select_door(void) {
    int door;
    std::cout << "Select a door (1, 2, or 3): ";
    std::cin >> door;
    return door;
    }

    int select_door_to_open(int door, int winning_door) {
    int door_to_open;
    do {
        door_to_open = select_random_door();
    } while (door_to_open == door || door_to_open == winning_door);
    return door_to_open;
    }

    void play_game(void) {
    int winning_door = select_random_winnnig_door();
    int door = select_door();
    int door_to_open = select_door_to_open(door, winning_door);
    std::cout << "Door " << door_to_open << " has a goat behind it." << std::endl;
    std::cout << "Do you want to switch doors? (y/n): ";
    char answer;
    std::cin >> answer;
    if (answer == 'y') {
        do {
        door = select_door();
        } while (door == door_to_open);
    }
    if (door == winning_door) {
        std::cout << "You win!" << std::endl;
    } else {
        std::cout << "You lose!" << std::endl;
    }
    }

    void play_game(int &win, int &lose) {
    int winning_door = select_random_winnnig_door();
    int door = select_door();
    int door_to_open = select_door_to_open(door, winning_door);
    std::cout << "Door " << door_to_open << " has a goat behind it." << std::endl;
    std::cout << "Do you want to switch doors? (y/n): ";
    char answer;
    std::cin >> answer;
    if (answer == 'y') {
        do {
        door = select_door();
        } while (door == door_to_open);
    }
    if (door == winning_door) {
        win++;
    } else {
        lose++;
    }
    }

    void play_game(int &win, int &lose, int &switch_win, int &switch_lose) {
    int winning_door = select_random_winnnig_door();
    int door = select_door();
    int door_to_open = select_door_to_open(door, winning_door);
    std::cout << "Door " << door_to_open << " has a goat behind it." << std::endl;
    std::cout << "Do you want to switch doors? (y/n): ";
    char answer;
    std::cin >> answer;
    if (answer == 'y') {
        do {
        door = select_door();
        } while (door == door_to_open);
        if (door == winning_door) {
        switch_win++;
        } else {
        switch_lose++;
        }
    } else {
        if (door == winning_door) {
        win++;
        } else {
        lose++;
        }
    }
    }

    void play_game(int &win, int &lose, int &switch_win, int &switch_lose,
                int &stay_win, int &stay_lose) {
    int winning_door = select_random_winnnig_door();
    int door = select_door();
    int door_to_open = select_door_to_open(door, winning_door);
    std::cout << "Door " << door_to_open << " has a goat behind it." << std::endl;
    std::cout << "Do you want to switch doors? (y/n): ";
    char answer;
    std::cin >> answer;
    if (answer == 'y') {
        do {
        door = select_door();
        } while (door == door_to_open);
        if (door == winning_door) {
        switch_win++;
        } else {
        switch_lose++;
        }
    } else {
        if (door == winning_door) {
        stay_win++;
        } else {
        stay_lose++;
        }
    }
    }

    void play_game(int &win, int &lose, int &switch_win, int &switch_lose,
                int &stay_win, int &stay_lose, int &switch_win_2,
                int &switch_lose_2, int &stay_win_2, int &stay_lose_2) {
    int winning_door = select_random_winnnig_door();
    int door = select_door();
    int door_to_open = select_door_to_open(door, winning_door);
    std::cout << "Door " << door_to_open << " has a goat behind it." << std::endl;
    std::cout << "Do you want to switch doors? (y/n): ";
    char answer;
    std::cin >> answer;
    if (answer == 'y') {
        do {
        door = select_door();
        } while (door == door_to_open);
        if (door == winning_door) {
        switch_win++;
        switch_win_2++;
        } else {
        switch_lose++;
        switch_lose_2++;
        }
    } else {
        if (door == winning_door) {
        stay_win++;
        stay_win_2++;
        } else {
        stay_lose++;
        stay_lose_2++;
        }
    }
    }

    void auto_play_game(int &win, int &lose, int &switch_win, int &switch_lose,
                        int &stay_win, int &stay_lose, int &switch_win_2,
                        int &switch_lose_2, int &stay_win_2, int &stay_lose_2) {
    int winning_door = select_random_winnnig_door();
    int door = select_random_door();
    int door_to_open = select_door_to_open(door, winning_door);
    if (door == winning_door) {
        stay_win++;
        stay_win_2++;
    } else {
        stay_lose++;
        stay_lose_2++;
    }
    do {
        door = select_random_door();
    } while (door == door_to_open);
    if (door == winning_door) {
        switch_win++;
        switch_win_2++;
    } else {
        switch_lose++;
        switch_lose_2++;
    }
    }

    void play_10_thousand_games(int &win, int &lose) {
    /**
    * @brief automatically play 10 000 games
    *
    */
    int switch_win = 0;
    int switch_lose = 0;
    int stay_win = 0;
    int stay_lose = 0;
    int switch_win_2 = 0;
    int switch_lose_2 = 0;
    int stay_win_2 = 0;
    int stay_lose_2 = 0;
    for (int i = 0; i < 10000; i++) {
        auto_play_game(win, lose, switch_win, switch_lose, stay_win, stay_lose,
                    switch_win_2, switch_lose_2, stay_win_2, stay_lose_2);
    }
    }
