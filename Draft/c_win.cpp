
// bool checkWin(Player player)
// {
//     // Check rows
//     for (int i = 0; i < BOARD_SIZE; i++)
//     {
//         bool win = true;
//         for (int j = 0; j < BOARD_SIZE; j++)
//         {
//             if (board[i][j] != player)
//             {
//                 win = false;
//                 break;
//             }
//         }
//         if (win)
//         {
//             return true;
//         }
//     }

//     // Check columns
//     for (int j = 0; j < BOARD_SIZE; j++)
//     {
//         bool win = true;
//         for (int i = 0; i < BOARD_SIZE; i++)
//         {
//             if (board[i][j] != player)
//             {
//                 win = false;
//                 break;
//             }
//         }
//         if (win)
//         {
//             return true;
//         }
//     }

//     // Check diagonal 1
//     bool win = true;
//     for (int i = 0; i < BOARD_SIZE; i++)
//     {
//         if (board[i][i] != player)
//         {
//             win = false;
//             break;
//         }
//     }
//     if (win)
//     {
//         return true;
//     }

//     // Check diagonal 2
//     win = true;
//     for (int i = 0; i < BOARD_SIZE; i++)
//     {
//         if (board[i][BOARD_SIZE - i - 1] != player)
//         {
//             win = false;
//             break;
//         }
//     }
//     if (win)
//     {
//         return true;
//     }

//     return false;
// }