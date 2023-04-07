int evaluateBoard(Player currentPlayer, const Board& board)
{
    if (checkWin(currentPlayer, board))
    {
        return 100;
    }
    else if (checkWin(getOtherPlayer(currentPlayer), board))
    {
        return -100;
    }
    else if (checkTie(Player::X, board) + checkTie(Player::O, board) == 9)
    {
        return 0;
    }
    else
    {
        return 0;
    }
}

vector<pair<int, int>> generateMoves(const Board& board)
{
    vector<pair<int, int>> moves;
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            if (board[i][j] == Player::None)
            {
                moves.push_back(make_pair(i, j));
            }
        }
    }
    return moves;
}

pair<int, pair<int, int>> minimax(Player currentPlayer, const Board& board, int depth)
{
    if (checkWin(Player::X, board))
    {
        return make_pair(100 - depth, make_pair(-1, -1));
    }
    else if (checkWin(Player::O, board))
    {
        return make_pair(depth - 100, make_pair(-1, -1));
    }
    else if (checkTie(Player::X, board) + checkTie(Player::O, board) == 9)
    {
        return make_pair(0, make_pair(-1, -1));
    }

    int bestScore = (currentPlayer == Player::X) ? -1000 : 1000;
    pair<int, int> bestMove = make_pair(-1, -1);

    vector<pair<int, int>> moves = generateMoves(board);
    for (auto move : moves)
    {
        Board newBoard = board;
        newBoard[move.first][move.second] = currentPlayer;

        int score = minimax(getOtherPlayer(currentPlayer), newBoard, depth + 1).first;
        if (currentPlayer == Player::X)
        {
            if (score > bestScore)
            {
                bestScore = score;
                bestMove = move;
            }
        }
        else
        {
            if (score < bestScore)
            {
                bestScore = score;
                bestMove = move;
            }
        }
    }

    return make_pair(bestScore, bestMove);
}