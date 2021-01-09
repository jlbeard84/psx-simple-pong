#include <stdlib.h>
#include "constants.h"

Color backgroundColor;
Color playerColor;
Color ballColor;

const int playerHeight = 60;
const int playerWidth = 10;
const int playerDistanceFromSide = 10;
const float initialBallSpeed = 1.0f;
const float ballSpeedProgression = 1.2f;

const int ballHeight = 5;
const int ballWidth = 5;

Box playerOne;
int playerOne_x;
int playerOne_y;

Box playerTwo;
int playerTwo_x;
int playerTwo_y;

// yes, we're using a square as the ball
Box ball;
float ball_x;
float ball_y;
float ball_speed;
float ball_x_dir;
float ball_y_dir;

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

    initializeRand();

    backgroundColor = createColor(0, 0, 0);
    setBackgroundColor(backgroundColor);

    playerColor = createColor(255, 255, 255);
    ballColor = createColor(255, 255, 255);

    playerOne_x = playerDistanceFromSide;
    playerOne_y = (SCREEN_HEIGHT) / 2 - (playerHeight / 2);
    playerOne = createBox(playerColor, playerOne_x, playerOne_y, playerOne_x + playerWidth, playerOne_y + playerHeight);

    playerTwo_x = SCREEN_WIDTH - playerDistanceFromSide - playerWidth;
    playerTwo_y = (SCREEN_HEIGHT) / 2 - (playerHeight / 2);
    playerTwo = createBox(playerColor, playerTwo_x, playerTwo_y, playerTwo_x + playerWidth, playerTwo_y + playerHeight);

    ball_x = SCREEN_WIDTH / 2 - ballWidth / 2;
    ball_y = SCREEN_HEIGHT / 2 - ballHeight / 2;
    ball = createBox(ballColor, ball_x, ball_y, ball_x + ballWidth, ball_y + ballHeight);
    ball_speed = initialBallSpeed;

    ball_x_dir = (((float)rand()/(float)RAND_MAX) * 2.0) - 1.0;
    ball_y_dir = (((float)rand()/(float)RAND_MAX) * 2.0) - 1.0;
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

    ball_x = ball_x + ball_x_dir * ball_speed;
    ball_y = ball_y + ball_y_dir * ball_speed;

    if (ball_x < 0)
    {
        ball_x = 0;
        ball_x_dir *= -1;
        ball_speed *= ballSpeedProgression;
    }
    else if (ball_x + ballWidth > SCREEN_WIDTH)
    {
        ball_x = SCREEN_WIDTH - ballWidth;
        ball_x_dir *= -1;
        ball_speed *= ballSpeedProgression;
    }

    if (ball_y < 0)
    {
        ball_y = 0;
        ball_y_dir *= -1;
        ball_speed *= ballSpeedProgression;
    }
    else if (ball_y + ballHeight > SCREEN_HEIGHT)
    {
        ball_y = SCREEN_HEIGHT - ballHeight;
        ball_y_dir *= -1;
        ball_speed *= ballSpeedProgression;
    }

    ball = moveBox(ball, ball_x, ball_y);
}

void draw() {
    drawBox(playerOne);
    drawBox(playerTwo);
    drawBox(ball);
}
