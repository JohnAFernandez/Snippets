

#include <iostream>
#include "play.hpp"

class game_state {


int main() {

    // Begin the game with the introduction function.
    introduction();

    // Loop through all player turns
    do {
        // Set up the board images with current positions from game state. 
        set_position();

        // Display the board
        draw();

        // Allow the current player to take their turn.
        take_turn();

        // Update the game state to reflect the player's turn
        update_board();

        // Check to see if the current player has won and break out of the loop if they have.
        if (is_winner()){
            break;
        }

        // Change players so that they can take their turn. 
        change_player();

    // If the board has been filled up, then it is time to end the game.
    // This does not guarantee that there is a draw.  end_game() needs to have an internal check for the winning player.
    } while (!filled_up())

    // Set up board images and display one more time.
    set_position();
    draw();

    // Display the end game results
    end_game();
}