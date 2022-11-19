#include <iostream>
#include <vector>

#define cls system("clear")
#define red "\033[31m"
#define white "\033[0m"
#define reset "\033[0m"
#define black "\033[90m"
#define bold "\033[1m"

using namespace std;
// time: 3:48"10'
/* TODO:
 * 1. Que las piezas no puedan salir por los bordes
 * 2. Crear el sistema de promocion
 *
 * <19-11-22, Ronald> */

string toLower(string str) {
    for (int i = 0; i < str.length(); i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') str[i] += 32;
    }

    return str;
}

class Board {
   private:
    string warnings;
    int playerMoving = 2;
    int numberOfRedPieces = 0;
    int numberOfWhitePieces = 0;
    vector<int> positions;
    vector<char> pieces;
    struct {
        int lef = -9;
        int righ = -11;
    } directions;

   public:
    Board() {
        positions = vector<int>(100);
        pieces = {' ', 'b', 'r'};
        warnings = "";

        // this->initBoard("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR");
        // this->initBoard(
        //"b1b1b1b1b1/1b1b1b1b1b/b1b1b1b1b1/1b1b1b1b1b/-/-/r1r1r1r1r1/"
        //"1r1r1r1r1r/r1r1r1r1r1/1r1r1r1r1r");
        this->initBoard("-/-/-/-/2b7/1r9/-/-/-/-");
    }

    void print() {
        for (int i = 0; i < 10; ++i) {
            cout << "\033[1;90m    "
                    "+---+---+---+---+---+---+---+---+---+---+\n\033[0m";

            cout << (10 - i != 10 ? "  " : " ") << 10 - i << "\033[1;90m";

            for (int j = 0; j < 10; ++j) {
                char piece =
                    this->getPieceCharacter(this->positions.at((i * 10) + j));

                cout << " | \033[1m";

                if (piece == 'r')
                    cout << red;
                else
                    cout << reset;

                cout << piece << black bold;

                // cout << "\033[0m";
            }
            cout << " |\n";
        }
        cout << "    +---+---+---+---+---+---+---+---+---+---+\n";

        cout << "   \033[0m";
        for (int i = 0; i < 10; ++i) cout << "   " << char(i + 'A');

        cout << "\n\n Turno de las (" bold
             << (playerMoving == 1 ? (white "b") : (red "r")) << reset ")\n";

        if (warnings != "") {
            cout << "\nMensaje: " << warnings << '\n';
            warnings = "";
        }
    }

    void moveAPiece(string mov) {
        mov = toLower(mov);
        int selectedDirection, originPosition, destinationPosition;
        int enemyPlayer;

        while (!this->isAValidMove(mov)) {
            warnings = "Debes introducir una jugada correcta";
            cls;
            this->print();

            cout << "\nJugada: ";
            cin >> mov;
            mov = toLower(mov);
        }

        if (playerMoving == 1) {
            selectedDirection =
                (mov[2] == 'l') ? -directions.lef : -directions.righ;
        } else {
            selectedDirection =
                (mov[2] == 'l') ? directions.righ : directions.lef;
        }

        originPosition = ((mov[0] - 'a')) + (9 - (mov[1] - '1')) * 10;
        destinationPosition = originPosition + selectedDirection;

        enemyPlayer = (playerMoving == 1) ? 2 : 1;

        cout << originPosition << " <- pos\n";

        if (positions[originPosition] == 0) {
            warnings = "Epa vale, aqui no hay ninguna pieza";
            return;
        }

        if (positions[originPosition] == enemyPlayer) {
            warnings = "Epa chico, esta pieza no es tuya";
            return;
        }

        if (positions[destinationPosition] == playerMoving) {
            warnings = "De hecho tienes una de tus piezas ahi";
            return;
        }

        if (positions[destinationPosition] == enemyPlayer) {
            if (positions[destinationPosition + selectedDirection] == 0) {
                positions[destinationPosition + selectedDirection] =
                    playerMoving;

                positions[originPosition] = 0;
                positions[destinationPosition] = 0;

                if (enemyPlayer == 1)  // 1 = b
                    numberOfWhitePieces--;
                else
                    numberOfRedPieces--;
            } else {
                warnings =
                    "No puedes capturar. Hay una pieza hacia donde te quieres "
                    "mover";
            }
            return;
        }

        positions[destinationPosition] = playerMoving;
        positions[originPosition] = 0;
        playerMoving = enemyPlayer;
    }

    int someoneWin() {
        if (numberOfRedPieces == 0) return -1;   // gana blancas
        if (numberOfWhitePieces == 0) return 1;  // ganan rojas

        return 0;
    }

   private:
    bool isAValidMove(string mov) {
        mov = toLower(mov);

        if ((mov[0] < 'a' || mov[0] > 'j') || (mov[2] != 'l' && mov[2] != 'r'))
            return false;  // no es un caracter

        if (mov[1] < '1' || mov[1] > '9') return false;

        return true;
    }

    char getPieceCharacter(int code) {
        if (code == 0) return ' ';
        return pieces[code];
    }

    int getPieceCode(char character) {
        for (int i = 0; i < pieces.size(); ++i)
            if (character == pieces[i]) return i + 1;
        return -1;
    }

    void initBoard(string FENCode) {
        int row = 0;
        int column = 0;
        int i = 0;
        while (row < 10 && i < FENCode.length()) {
            char FENChar = FENCode[i];

            if (FENChar == '/')
                column = 0;
            else if (FENChar == '-')
                column = 10;
            else if (FENChar >= '1' && FENChar <= '9')
                column += FENChar - '0';
            else {
                positions[(row * 10) + column] =
                    this->getPieceCode(FENChar) - 1;

                if (this->getPieceCode(FENChar) == 2)
                    numberOfRedPieces++;
                else
                    numberOfWhitePieces++;

                column++;
            }

            if (column > 9) {
                column = 0;
                row++;
            }
            i++;

        }  // end while
    }      // end function
};

int main(int argc, char *argv[]) {
    Board board;
    string mov;

    cls;
    board.print();
    do {
        cout << "\nJugada: ";
        cin >> mov;
        board.moveAPiece(mov);
        cls;
        board.print();
    } while (!board.someoneWin());

    cout << '\n';

    cls;
    if (board.someoneWin() == 1) {
        cout << "Ganaron las rojas nojodaaaaa";
    } else
        cout << "Ganaron las blancas nojodaaaaa";

    cout << '\n';
    return 0;
}

