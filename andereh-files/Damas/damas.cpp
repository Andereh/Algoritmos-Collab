#include <iostream>
#include <vector>

using namespace std;

class Board {
   private:
    vector<int> positions;
    vector<char> pieces;

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
            if (FENCode[i] == '/') {
                column = 0;
            } else if (FENCode[i] >= '1' && FENCode[i] <= '9')
                column += FENCode[i] - '0';
            else if (FENCode[i] == '-')
                column = 10;
            else {
                positions[(row * 10) + column] =
                    this->getPieceCode(FENCode[i]) - 1;
                column++;
            }

            if (column > 9) {
                column = 0;
                row++;
            }
            // cout << "code(" << row << " " << column << "): " << FENCode[i]
            //<< "\n";
            i++;

        }  // end while
    }      // end function

   public:
    Board() {
        positions = vector<int>(100);
        pieces = {' ', 'b', 'r'};

        // this->initBoard("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR");
        this->initBoard(
            "b1b1b1b1b1/1b1b1b1b1b/b1b1b1b1b1/1b1b1b1b1b/-/-/r1r1r1r1r1/"
            "1r1r1r1r1r/r1r1r1r1r1/1r1r1r1r1r");
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
                    cout << "\033[31m";
                else
                    cout << "\033[0m";

                cout << piece << "\033[1;90m";

                // cout << "\033[0m";
            }
            cout << " |\n";
        }
        cout << "    +---+---+---+---+---+---+---+---+---+---+\n";

        cout << "   \033[0m";
        for (int i = 0; i < 10; ++i) cout << "   " << char(i + 'A');
    }
};

int main(int argc, char *argv[]) {
    Board board;
    board.print();
    cout << '\n';
    return 0;
}

