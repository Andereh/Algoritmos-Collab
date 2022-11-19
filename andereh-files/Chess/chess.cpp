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
        while (row < 8 && i < FENCode.length()) {
            if (FENCode[i] == '/') {
                column = 0;
            } else if (FENCode[i] >= '1' && FENCode[i] <= '9')
                column += FENCode[i] - '0';
            else {
                positions[(row * 8) + column] =
                    this->getPieceCode(FENCode[i]) - 1;
                column++;
            }

            if (column > 7) {
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
        positions = vector<int>(64);
        pieces = {' ', 'P', 'B', 'N', 'R', 'Q', 'K',
                  'p', 'b', 'n', 'r', 'q', 'k'};

        // this->initBoard("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR");
        this->initBoard("8/5k2/3p4/1p1Pp2p/pP2Pp1P/P4P1K/8/8");
    }

    void print() {
        for (int i = 0; i < 8; ++i) {
            cout << " +---+---+---+---+---+---+---+---+\n";

            for (int j = 0; j < 8; ++j) {
                char piece =
                    this->getPieceCharacter(this->positions.at((i * 8) + j));
                int code = this->getPieceCode(piece);

                 cout << " | ";
                // if (code != 1) {
                // if (code < 7)
                // cout << "\033[30;47m";
                // else
                // cout << "\033[40;37m";
                //}
                cout << piece;

                // cout << "\033[0m";
            }
            cout << " |\n";
        }
        cout << " +---+---+---+---+---+---+---+---+\n";
    }
};

int main(int argc, char *argv[]) {
    Board board;
    board.print();
    return 0;
}

