#ifndef PIECE_H
#define PIECE_H

#include <string>
#include <map>
#include <gf/RenderWindow.h>


namespace stg {
    enum PieceName {
        NONE,
        LAKE,
        DRAPEAU,
        ESPION,
        ECLAIREUR,
        DEMINEUR,
        SERGENT,
        LIEUTENANT,
        CAPITAINE,
        COMMANDANT,
        COLONEL,
        GENERAL,
        MARECHAL,
        BOMBE,
        PION
    };

    enum Color {
        EMPTY,
        RED,
        BLUE
    };

    class Piece {

        public:
            Piece(PieceName _name,Color _col);

            PieceName getPieceName() const;
            Color getColor() const;

            int battleResult(const Piece& other) const;
            
            static Piece makeBlankPiece();

        private:
        PieceName name;
        Color col;

    };

    template<typename Archive>
    Archive operator|(Archive& ar, stg::Piece& p) {
        return ar | p.getPieceName() | p.getColor();
    }
}

#endif