#include "constants.h"

Color backgroundColor;
Color playerColor;

const int playerHeight = 20;
const int playerWidth = 5;
const int playerDistanceFromSide = 10;

Box playerOne;
int playerOne_x;
int playerOne_y;

Box playerTwo;
int playerTwo_x;
int playerTwo_y;

int main() {
    initialize();

    while(1) {
        update();
        draw();
        display();
    }
}

void initialize() {
    initializeScreen();
    initializePad();

    backgroundColor = createColor(0, 0, 0);
    setBackgroundColor(backgroundColor);

    playerColor = createColor(255, 255, 255);

    playerOne_x = playerDistanceFromSide;
    playerOne_y = (SCREEN_HEIGHT) / 2 - (playerHeight / 2);
    playerOne = createBox(playerColor, playerOne_x, playerOne_y, playerOne_x + playerWidth, playerOne_y + playerWidth);

    playerTwo_x = SCREEN_WIDTH - playerDistanceFromSide - playerWidth;
    playerTwo_y = (SCREEN_HEIGHT) / 2 - (playerHeight / 2);
    playerTwo = createBox(playerColor, playerTwo_x, playerTwo_y, playerTwo_x + playerWidth, playerTwo_y + playerWidth);
}

void update() {

}

void draw() {
    drawBox(playerOne);
    drawBox(playerTwo);
}
