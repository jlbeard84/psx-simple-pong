#include "constants.h"

Color backgroundColor;
Color playerColor;

const int playerHeight = 60;
const int playerWidth = 10;
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
    playerOne = createBox(playerColor, playerOne_x, playerOne_y, playerOne_x + playerWidth, playerOne_y + playerHeight);

    playerTwo_x = SCREEN_WIDTH - playerDistanceFromSide - playerWidth;
    playerTwo_y = (SCREEN_HEIGHT) / 2 - (playerHeight / 2);
    playerTwo = createBox(playerColor, playerTwo_x, playerTwo_y, playerTwo_x + playerWidth, playerTwo_y + playerHeight);
}

void update() {
    padUpdate();

    if (padCheck(Pad1Up)) {
        playerOne_y -= 2;
        playerOne_y = playerOne_y < 0 ? 0 : playerOne_y;

        playerOne = moveBox(playerOne, playerOne_x, playerOne_y);
    }

    if (padCheck(Pad1Down)) {
        playerOne_y += 2;
        playerOne_y = playerOne_y + playerHeight > SCREEN_HEIGHT ? SCREEN_HEIGHT - playerHeight : playerOne_y;

        playerOne = moveBox(playerOne, playerOne_x, playerOne_y);
    }

}

void draw() {
    drawBox(playerOne);
    drawBox(playerTwo);
}
