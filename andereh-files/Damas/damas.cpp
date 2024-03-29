#include <iostream>
#include <vector>

#define cls   system("clear")
#define red   "\033[31m"
#define white "\033[0m"
#define reset "\033[0m"
#define black "\033[90m"
#define bold  "\033[1m"

using namespace std;

// time: 3:48"10'
/* TODO
 * 1. Que las piezas no puedan salir por los bordes (listo)
 * 2. Crear el sistema de promocion
 * 3. Crear una inteligencia artificial
 *
 * <19-11-22, Ronald> */

string toLower(string str)
{
    for (int i = 0; i < str.length(); i++)
        if (str[i] >= 'A' && str[i] <= 'Z')
            str[i] += 32;

    return str;
}

class Board
{
    string        warnings;
    int           playerMoving;
    int           numberOfRedPieces;
    int           numberOfWhitePieces;
    vector<short> positions;
    vector<char>  pieces;
    char          leftSign;
    char          rightSign;

    struct
    { // this is for red pieces
        int lef  = -9;
        int righ = -11;
    } directions;

  public:
    Board()
    {
        warnings = "";

        playerMoving        = 2; // 2 = rojos
        numberOfRedPieces   = 0;
        numberOfWhitePieces = 0;
        positions           = vector<short>(100);
        pieces              = {' ', 'p', 'X'};

        leftSign  = 'l';
        rightSign = 'r';

        // this->initBoard("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR");
        this->initBoard(
            "b1b1b1b1b1/1b1b1b1b1b/b1b1b1b1b1/1b1b1b1b1b/-/-/r1r1r1r1r1/"
            "1r1r1r1r1r/r1r1r1r1r1/1r1r1r1r1r");
        // this->initBoard("-/-/-/-/2b7/1r9/-/-/-/-");
    }

    void print()
    {
        for (int i = 0; i < 10; ++i)
        {
            cout << black bold
                "    "
                "+---+---+---+---+---+---+---+---+---+---+\n" white;

            cout << (10 - i != 10 ? "  " : " ") << 10 - i << black bold;

            for (int j = 0; j < 10; ++j)
            {
                char piece =
                    this->getPieceCharacter(this->positions[(i * 10) + j]);

                cout << " | " bold;

                if (piece == pieces[2])
                    cout << red;
                else
                    cout << white;

                cout << piece << black bold;
            }
            cout << " |\n";
        }
        cout << "    +---+---+---+---+---+---+---+---+---+---+\n";

        cout << "   " white;
        for (int i = 0; i < 10; ++i)
            cout << "   " << char(i + 'A');
        cout << "\n\n Turno de las (" bold << (playerMoving == 2 ? red : white)
             << this->getPieceCharacter(playerMoving) << reset ")\n";

        if (warnings != "")
        {
            cout << "\nMensaje: " << warnings << '\n';
            warnings = "";
        }
    }

    void moveAPiece()
    {
        string mov;
        int    selectedDirection, originPosition, destinationPosition;
        int    enemyPlayer;

        cout << "\n Jugada: ";
        cin >> mov;
        mov = toLower(mov);

        while (!this->isAValidMove(mov))
        {
            warnings = "Debes introducir una jugada correcta";
            cls;
            this->print();

            cout << "\n Jugada: ";
            cin >> mov;
            mov = toLower(mov);
        }

        if (playerMoving == 1)
            selectedDirection =
                (mov[2] == leftSign) ? -directions.lef : -directions.righ;
        else
            selectedDirection =
                (mov[2] == leftSign) ? directions.righ : directions.lef;

        originPosition      = ((mov[0] - 'a')) + (9 - (mov[1] - '1')) * 10;
        destinationPosition = originPosition + selectedDirection;

        enemyPlayer = (playerMoving == 1) ? 2 : 1;

        // cout << originPosition << " <- pos\n";

        if (positions[originPosition] == 0)
        {
            warnings = "Epa vale, aqui no hay ninguna pieza";
            return;
        }

        if (positions[originPosition] == enemyPlayer)
        {
            warnings = "Epa chico, esta pieza no es tuya";
            return;
        }

        if (positions[destinationPosition] == playerMoving)
        {
            warnings = "De hecho tienes una de tus piezas ahi";
            return;
        }

        if (positions[destinationPosition] == enemyPlayer)
        {
            if (positions[destinationPosition + selectedDirection] == 0)
            {
                positions[destinationPosition + selectedDirection] =
                    playerMoving;

                positions[originPosition]      = 0;
                positions[destinationPosition] = 0;

                if (enemyPlayer == 1) // 1 = b
                    numberOfWhitePieces--;
                else
                    numberOfRedPieces--;
            }
            else
                warnings = "No puedes capturar. Hay una pieza detras";
            return;
        }

        positions[destinationPosition] = playerMoving;
        positions[originPosition]      = 0;
        playerMoving                   = enemyPlayer;
    }

    int someoneWin()
    {
        if (numberOfRedPieces == 0)
            return -1; // ganan blancas
        if (numberOfWhitePieces == 0)
            return 1; // ganan rojas

        return 0;
    }

  private:
    bool isAValidMove(string mov)
    {
        mov = toLower(mov);

        if ((mov[0] < 'a' || mov[0] > 'j') || (mov[1] < '1' || mov[1] > '9') ||
            (mov[2] != leftSign && mov[2] != rightSign))
            return false; // no es un caracter dentro de los limites

        if ((mov[0] == 'a' && mov[2] == leftSign) ||
            (mov[0] == 'j' && mov[2] == rightSign))
            return false; // no puedes salirte del tablero lateralmente

        return true;
    }

    char getPieceCharacter(int code)
    {
        if (code == 0)
            return ' ';
        return pieces[code];
    }

    int getPieceCode(char character)
    {
        if (character == 'b')
            return 1;
        else if (character == 'r')
            return 2;
        else
            return -1;
    }

    void initBoard(string FENCode)
    {
        int row    = 0;
        int column = 0;
        int i      = 0;
        while (row < 10 && i < FENCode.length())
        {
            char FENChar = FENCode[i];

            if (FENChar == '/')
                column = 0;
            else if (FENChar == '-')
                column = 10;
            else if (FENChar >= '1' && FENChar <= '9')
                column += FENChar - '0';
            else
            {
                positions[(row * 10) + column] = this->getPieceCode(FENChar);

                if (this->getPieceCode(FENChar) == 2)
                    numberOfRedPieces++;
                else
                    numberOfWhitePieces++;

                column++;
            }

            if (column > 9)
            {
                column = 0;
                row++;
            }
            i++;

        } // end while
    }     // end function
};

int main(int argc, char *argv[])
{
    Board board;

    cls;
    board.print();

    do
    {
        board.moveAPiece();
        cls;
        board.print();
    } while (!board.someoneWin()); // Main loop

    cout << '\n';

    cls;
    board.print();
    if (board.someoneWin() == 1)
        cout << "\nGanaron las rojas nojodaaaaa";
    else
        cout << "\nGanaron las blancas nojodaaaaa";

    cout << '\n';
    return 0;
}

