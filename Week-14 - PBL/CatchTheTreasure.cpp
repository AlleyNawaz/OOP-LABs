#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

class GameObject {
private:
    int positionX;
    int positionY;
    char symbol;

public:
    GameObject() : positionX(0), positionY(0), symbol('.') {}

    GameObject(int x, int y, char sym) {
        positionX = x;
        positionY = y;
        symbol = sym;
    }

    int getX() { return positionX; }
    int getY() { return positionY; }
    char getSymbol() { return symbol; }

    void setPosition(int x, int y) {
        positionX = x;
        positionY = y;
    }
};

class Game {
private:
    vector<vector<char>> grid;
    GameObject player;
    vector<GameObject> treasures;
    vector<GameObject> obstacles;

    int score;
    int movesRemaining;
    bool gameOver;
    bool gameWon;

    int getRandomCoord() {
        return rand() % 5;
    }

public:
    Game(int totalMoves) {
        score = 0;
        movesRemaining = totalMoves;
        gameOver = false;
        gameWon = false;
        grid.resize(5, vector<char>(5, '.'));
    }

    void initializeGame() {
        int px = getRandomCoord();
        int py = getRandomCoord();
        player = GameObject(px, py, 'P');
        grid[px][py] = 'P';

        int treasureCount = 0;
        while (treasureCount < 3) {
            int r = getRandomCoord();
            int c = getRandomCoord();
            if (grid[r][c] == '.') {
                treasures.push_back(GameObject(r, c, 'T'));
                grid[r][c] = 'T';
                treasureCount++;
            }
        }

        int obstacleCount = 0;
        while (obstacleCount < 3) {
            int r = getRandomCoord();
            int c = getRandomCoord();
            if (grid[r][c] == '.') {
                obstacles.push_back(GameObject(r, c, 'O'));
                grid[r][c] = 'O';
                obstacleCount++;
            }
        }
    }

    void renderGrid() {
        system("cls");
        cout << "=== CATCH THE TREASURE ===" << endl;
        cout << "Score: " << score << " | Moves Left: " << movesRemaining << endl;
        cout << "--------------------------" << endl;

        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                cout << " " << grid[i][j] << " ";
            }
            cout << endl;
        }
        cout << "--------------------------" << endl;
    }

    void checkCell() {
        int x = player.getX();
        int y = player.getY();
    }

    bool movePlayer(char input) {
        if (gameOver) return false;

        int newX = player.getX();
        int newY = player.getY();

        switch (toupper(input)) {
            case 'W': newX--; break;
            case 'S': newX++; break;
            case 'A': newY--; break;
            case 'D': newY++; break;
            default:
                cout << "Invalid move! Use W, A, S, D." << endl;
                return false;
        }

        if (newX < 0 || newX >= 5 || newY < 0 || newY >= 5) {
            cout << "You hit the wall! Move wasted." << endl;
            movesRemaining--;
            return true;
        }

        char targetCell = grid[newX][newY];
        grid[player.getX()][player.getY()] = '.';

        if (targetCell == 'T') {
            score += 10;
            cout << "You found a Treasure! (+10 pts)" << endl;
        }
        else if (targetCell == 'O') {
            cout << "BOOM! You hit an obstacle." << endl;
            gameOver = true;
            grid[newX][newY] = 'X';
            return true;
        }

        player.setPosition(newX, newY);
        grid[newX][newY] = 'P';
        movesRemaining--;

        return true;
    }

    bool isGameOver() {
        if (gameOver) return true;
        if (movesRemaining <= 0) {
            cout << "Out of moves!" << endl;
            return true;
        }
        if (score == 30) {
             cout << "All treasures collected! YOU WIN!" << endl;
             gameWon = true;
             return true;
        }
        return false;
    }

    int getScore() { return score; }
};

int main() {
    srand(time(0));

    Game myGame(15);
    myGame.initializeGame();
    myGame.renderGrid();

    char input;

    while (!myGame.isGameOver()) {
        cout << "Enter move (W: Up, A: Left, S: Down, D: Right): ";
        cin >> input;

        if (myGame.movePlayer(input)) {
            myGame.renderGrid();
        }
    }

    cout << "\nGame Over! Final Score: " << myGame.getScore() << endl;

    return 0;
}